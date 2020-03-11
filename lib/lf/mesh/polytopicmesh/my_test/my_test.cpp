#include <iostream>

#include <lf/mesh/polytopicmesh/polytopicmesh.h>

namespace lf::mesh::polytopicmesh{


int main()
{
    using GeometryPtr = std::unique_ptr<lf::geometry::Geometry>;
    using EdgeList = std::vector<std::pair<std::array<size_type, 2>, GeometryPtr>>;
    using CellList = std::vector<std::pair<std::array<size_type, 4>, GeometryPtr>>;

    std::cout << "Hi from polytopic mesh" << std::endl;

    dim_t dim_world = 2;
    int num_coords = 3;
    std::vector<GeometryPtr> nodes;
    nodes.reserve(num_coords);

    // initialize nodes

    // Eigen::Vector2d coord0 = Eigen::Vector2d::Zero();
    Eigen::Vector2d nodes_coord0, nodes_coord1, nodes_coord2;
    nodes_coord0 << 0., 0.;
    nodes_coord1 << 1., 0.;
    nodes_coord2 << 0., 1.;

    // nodes.push_back(p0);
    nodes.emplace_back(new lf::geometry::Point(nodes_coord0));
    nodes.emplace_back(new lf::geometry::Point(nodes_coord1));
    nodes.emplace_back(new lf::geometry::Point(nodes_coord2));

    int num_edges = 3;
    EdgeList edges; 
    edges.reserve(num_edges);

    // Eigen::Matrix<double, 2, 2> edges_coords0, edges_coords1, edges_coords2;
    // edges_coords0 << nodes_coord0, nodes_coord1;
    // edges_coords1 << nodes_coord1, nodes_coord2;
    // edges_coords2 << nodes_coord2, nodes_coord0;   

    // edges.emplace_back(new lf::geometry::SegmentO1(edges_coords0));
    // edges.emplace_back(new lf::geometry::SegmentO1(edges_coords1));
    // edges.emplace_back(new lf::geometry::SegmentO1(edges_coords2));

    // initialize edges


    int num_cells = 1;
    CellList cells(num_cells);
    // initialize cells

    lf::mesh::polytopicmesh::Mesh* mesh_p;
    std::cout << "mesh_p->DimMesh()" << mesh_p->DimMesh();

    return 0;
}
}