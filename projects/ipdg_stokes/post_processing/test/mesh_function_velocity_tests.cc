#include <gtest/gtest.h>

#include <mesh_function_velocity.h>

#include <lf/mesh/hybrid2d/mesh_factory.h>
#include <lf/mesh/utils/codim_mesh_data_set.h>
#include <lf/mesh/utils/mesh_data_set.h>
#include <lf/mesh/utils/tp_triag_mesh_builder.h>
#include <lf/uscalfe/uscalfe.h>

#include <tuple>
#include <vector>

static std::shared_ptr<const lf::uscalfe::UniformScalarFESpace<double>>
initFESpace() {
  // Build a very simple triangular mesh
  auto factory = std::make_shared<lf::mesh::hybrid2d::MeshFactory>(2);
  lf::mesh::hybrid2d::TPTriagMeshBuilder builder(std::move(factory));
  builder.setBottomLeftCorner(0, 0);
  builder.setTopRightCorner(1, 1);
  builder.setNoXCells(1);
  builder.setNoYCells(1);
  const auto mesh = builder.Build();
  return std::make_shared<const lf::uscalfe::FeSpaceLagrangeO1<double>>(mesh);
}

TEST(projects_ipdg_stokes_post_processing, mesh_function_velocity) {
  // Create a suitable finite element space
  const auto fe_space = initFESpace();

  // Initialize pairs of basis function coefficients together with velocities on
  // entities to test the implementation
  std::vector<std::tuple<Eigen::Matrix<double, Eigen::Dynamic, 1>,
                         std::shared_ptr<lf::mesh::utils::CodimMeshDataSet<Eigen::Vector2d>>>>
      tests;

  tests.emplace_back(Eigen::VectorXd::Zero(4),
                     std::make_shared<lf::mesh::utils::CodimMeshDataSet<Eigen::Vector2d>>(
                         fe_space->Mesh(), 0));
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 0))) << 0, 0;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 1))) << 0, 0;

  tests.emplace_back(Eigen::VectorXd::Ones(4),
                     std::make_shared<lf::mesh::utils::CodimMeshDataSet<Eigen::Vector2d>>(
                         fe_space->Mesh(), 0));
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 0))) << 0, 0;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 1))) << 0, 0;

  tests.emplace_back(Eigen::VectorXd::Zero(4),
                     std::make_shared<lf::mesh::utils::CodimMeshDataSet<Eigen::Vector2d>>(
                         fe_space->Mesh(), 0));
  std::get<0>(tests.back())[0] = 1;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 0))) << -1, 0;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 1))) << 0, 1;

  tests.emplace_back(Eigen::VectorXd::Zero(4),
                     std::make_shared<lf::mesh::utils::CodimMeshDataSet<Eigen::Vector2d>>(
                         fe_space->Mesh(), 0));
  std::get<0>(tests.back())[1] = 1;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 0))) << 0, 0;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 1))) << -1, -1;

  tests.emplace_back(Eigen::VectorXd::Zero(4),
                     std::make_shared<lf::mesh::utils::CodimMeshDataSet<Eigen::Vector2d>>(
                         fe_space->Mesh(), 0));
  std::get<0>(tests.back())[2] = 1;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 0))) << 1, 1;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 1))) << 0, 0;

  tests.emplace_back(Eigen::VectorXd::Zero(4),
                     std::make_shared<lf::mesh::utils::CodimMeshDataSet<Eigen::Vector2d>>(
                         fe_space->Mesh(), 0));
  std::get<0>(tests.back())[3] = 1;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 0))) << 0, -1;
  (*std::get<1>(tests.back()))(*(fe_space->Mesh()->EntityByIndex(0, 1))) << 1, 0;

  // Run through all coefficient vectors
  for (const auto& test : tests) {
    const auto& coeffs = std::get<0>(test);
    const auto& v_exact = *std::get<1>(test);
    projects::ipdg_stokes::post_processing::MeshFunctionVelocity v_func(
        fe_space, coeffs);
    for (const auto& entity : fe_space->Mesh()->Entities(0)) {
      const auto v_comp =
          v_func(entity, entity.RefEl().NodeCoords().rowwise().sum() / 3)[0];
      EXPECT_TRUE(v_exact(entity).isApprox(v_comp))
          << "Mismatch in the exact and computed velocity for coefficient "
             "vector ["
          << coeffs.transpose() << "] on entity "
          << fe_space->Mesh()->Index(entity)
          << "\nExact : " << v_exact(entity).transpose()
          << "\nApprox: " << v_comp.transpose();
    }
  }
}