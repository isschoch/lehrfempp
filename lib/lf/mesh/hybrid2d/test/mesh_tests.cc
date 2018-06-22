#include <gtest/gtest.h>
#include <lf/geometry/geometry.h>
#include <lf/mesh/hybrid2d/hybrid2d.h>
#include <lf/mesh/test_utils/check_entity_indexing.h>
#include <lf/mesh/test_utils/check_geometry_orientation.h>
#include <lf/mesh/test_utils/check_local_topology.h>
#include <lf/mesh/test_utils/check_mesh_completeness.h>

#include <iostream>

using namespace lf::geometry;

using size_type = unsigned int;

namespace lf::mesh::hybrid2d::test {
TEST(hybrid2d, directMeshConstruction) {
  // construct a very simple mesh with two elements (tria, quad)
  // manually.
  hybrid2d::MeshFactory factory(2);

  factory.AddPoint(Eigen::Vector2d{0, 0});
  factory.AddPoint(Eigen::Vector2d{1, 0});
  factory.AddPoint(Eigen::Vector2d{2, 0});
  factory.AddPoint(Eigen::Vector2d{1, 1});
  factory.AddPoint(Eigen::Vector2d{0, 1});

  Eigen::MatrixXd nodesQuad(2, 4), nodesTria(2, 3);
  nodesQuad << 0, 1, 1, 0, 0, 0, 1, 1;
  factory.AddEntity(base::RefEl::kQuad(), {0, 1, 3, 4},
                    std::make_unique<QuadO1>(nodesQuad));

  nodesTria << 1, 2, 1, 0, 0, 1;
  factory.AddEntity(base::RefEl::kTria(), {1, 2, 3},
                    std::make_unique<TriaO1>(nodesTria));

  auto mesh = factory.Build();

  EXPECT_EQ(mesh->DimMesh(), 2);
  EXPECT_EQ(mesh->DimWorld(), 2);

  EXPECT_EQ(mesh->Size(0), 2);
  EXPECT_EQ(mesh->Size(1), 6);
  EXPECT_EQ(mesh->Size(2), 5);

  auto element0 = mesh->Entities(0).begin();
  auto element1 = element0;
  ++element1;

  auto node0 = mesh->Entities(2).begin();
  auto node1 = node0;
  ++node1;
  auto node2 = node1;
  ++node2;
  auto node3 = node2;
  ++node3;
  auto node4 = node3;
  ++node4;

  EXPECT_EQ(element0->Codim(), 0);
  EXPECT_EQ(element1->Codim(), 0);

  EXPECT_EQ(element0->SubEntities(2)[0], *node0);
  EXPECT_EQ(element0->SubEntities(2)[1], *node1);
  EXPECT_EQ(element0->SubEntities(2)[2], *node3);
  EXPECT_EQ(element0->SubEntities(2)[3], *node4);

  EXPECT_EQ(element0->SubEntities(1)[1], element1->SubEntities(1)[2]);
  EXPECT_EQ(element0->SubEntities(1)[1].SubEntities(1)[0].Codim(), 2);
  EXPECT_EQ(element0->SubEntities(1)[1].SubEntities(1)[0], *node1);
  EXPECT_EQ(element0->SubEntities(1)[1].SubEntities(1)[1], *node3);

  mesh::test_utils::checkEntityIndexing(*mesh);
}

TEST(hybrid2d, buildMeshWithExplicitEdges) {
  hybrid2d::MeshFactory factory(2);

  // add nodes
  EXPECT_EQ(factory.AddPoint(Eigen::Vector2d{0, 0}), 0);
  EXPECT_EQ(factory.AddPoint(Eigen::Vector2d{1, 0}), 1);
  EXPECT_EQ(factory.AddPoint(Eigen::Vector2d{2, 0}), 2);
  EXPECT_EQ(factory.AddPoint(Eigen::Vector2d{1, 1}), 3);
  EXPECT_EQ(factory.AddPoint(Eigen::Vector2d{0, 1}), 4);

  // add elements
  Eigen::MatrixXd nodesQuad(2, 4), nodesTria(2, 3);
  nodesQuad << 0, 1, 1, 0, 0, 0, 1, 1;
  EXPECT_EQ(factory.AddEntity(base::RefEl::kQuad(), {0, 1, 3, 4},
                              std::make_unique<QuadO1>(nodesQuad)),
            0);
  nodesTria << 1, 2, 1, 0, 0, 1;
  EXPECT_EQ(factory.AddEntity(base::RefEl::kTria(), {1, 2, 3},
                              std::make_unique<TriaO1>(nodesTria)),
            1);

  // add some edges manually:
  factory.AddEntity(base::RefEl::kSegment(), {3, 1}, nullptr);
  factory.AddEntity(base::RefEl::kSegment(), {0, 1}, nullptr);

  Eigen::MatrixXd nodesSegment(2, 2);
  nodesSegment << 5, 5, 5, 6;
  factory.AddEntity(base::RefEl::kSegment(), {0, 4},
                    std::make_unique<SegmentO1>(nodesSegment));

  auto mesh = factory.Build();
  test_utils::checkEntityIndexing(*mesh);

  EXPECT_EQ(mesh->Size(0), 2);
  EXPECT_EQ(mesh->Size(1), 6);
  EXPECT_EQ(mesh->Size(2), 5);

  // edge0
  auto iterator = mesh->Entities(1).begin();
  EXPECT_EQ(mesh->Index(*iterator), 0);
  EXPECT_EQ(mesh->Index(iterator->SubEntities(1)[0]), 1);
  EXPECT_EQ(mesh->Index(iterator->SubEntities(1)[1]), 3);
  test_utils::checkGeometryOrientation(*iterator);

  // edge1
  ++iterator;
  EXPECT_EQ(mesh->Index(*iterator), 1);
  EXPECT_EQ(mesh->Index(iterator->SubEntities(1)[0]), 0);
  EXPECT_EQ(mesh->Index(iterator->SubEntities(1)[1]), 1);
  test_utils::checkGeometryOrientation(*iterator);

  // edge2
  ++iterator;
  EXPECT_EQ(mesh->Index(*iterator), 2);
  EXPECT_EQ(mesh->Index(iterator->SubEntities(1)[0]), 0);
  EXPECT_EQ(mesh->Index(iterator->SubEntities(1)[1]), 4);
  EXPECT_TRUE(iterator->Geometry()
                  ->Global(base::RefEl::kSegment().NodeCoords())
                  .isApprox(nodesSegment, 1e-6));

  // edge3
  ++iterator;
  EXPECT_EQ(mesh->Index(*iterator), 3);
}

// TODO(raffael): enable once it works!
// TEST(hybrid2d, buildStructuredMesh) {
//  // Construct a structured mesh with 8 triangles
//  lf::mesh::hybrid2d::TPTriagMeshBuilder builder{};
//  // Set mesh parameters following the Builder pattern
//  // Domain is the unit square
//  builder.setBottomLeftCorner(Eigen::Vector2d{0, 0})
//      .setTopRightCorner(Eigen::Vector2d{1, 1})
//      .setNoXCells(2)
//      .setNoYCells(2);
//  auto mesh_p = builder.Build();
//
//  EXPECT_NE(mesh_p, nullptr) << "Oops! no mesh!";
//  EXPECT_EQ(mesh_p->DimMesh(), 2) << "Mesh dimension != 2 !";
//  EXPECT_EQ(mesh_p->DimWorld(), 2) << "Wolrd dimension must be 2";
//  EXPECT_EQ(mesh_p->Size(0), 8) << "Mesh should comprise 8 triangles";
//  EXPECT_EQ(mesh_p->Size(1), 16) << "Mesh should have 16 edges";
//  EXPECT_EQ(mesh_p->Size(2), 9) << "Mesh should have 9 vertices";
//
//  std::cout << "Checking entity indexing" << std::endl;
//  test_utils::checkEntityIndexing(*mesh_p);
//  std::cout << "Checking mesh completeness" << std::endl;
//  test_utils::checkMeshCompleteness(*mesh_p);
//}
}  // namespace lf::mesh::hybrid2d::test
