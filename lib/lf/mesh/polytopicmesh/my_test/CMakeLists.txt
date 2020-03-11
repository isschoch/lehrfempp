add_executable(my_test my_test.cpp)
target_link_libraries(my_test PUBLIC Eigen3::Eigen 
  lf.io
  lf.mesh.polytopicmesh
  lf.mesh.test_utils
  lf.mesh.utils)