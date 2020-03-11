set(sources
  polytopicmesh.h
  mesh.cc
  mesh.h
  mesh_factory.cc
  mesh_factory.h
  point.h
  point.cc
  quad.h
  quad.cc
  segment.h
  segment.cc
  triangle.h
  triangle.cc
)

lf_add_library(lf.mesh.polytopicmesh ${sources})
target_link_libraries(lf.mesh.polytopicmesh PUBLIC Eigen3::Eigen lf.base lf.mesh lf.mesh.utils)

add_subdirectory(my_test)
