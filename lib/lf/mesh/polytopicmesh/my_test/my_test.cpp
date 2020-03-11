#include <iostream>

#include <lf/mesh/polytopicmesh/polytopicmesh.h>

namespace lf::mesh::polytopicmesh{


int main()
{
    using GeometryPtr = std::shared_ptr<lf::geometry::Geometry>;
    using NodeCoordList = std::vector<GeometryPtr>;
    using EdgeList = std::vector<std::pair<std::array<size_type, 2>, GeometryPtr>>;
    using CellList = std::vector<std::pair<std::array<size_type, 4>, GeometryPtr>>;

    std::cout << "Hi from polytopic mesh" << std::endl;

    dim_t dim_world = 2;
    int num_coords = 3;
    NodeCoordList nodes;
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

    // initialize edges
    int num_edges = 3;
    EdgeList edges; 
    edges.reserve(num_edges);

    Eigen::Matrix<double, 2, 2> edges_coords0, edges_coords1, edges_coords2;
    std::array<size_type, 2> ns_edge0, ns_edge1, ns_edge2;

    edges_coords0 << nodes_coord0, nodes_coord1;
    ns_edge0[0] = 0;
    ns_edge0[1] = 1;

    edges_coords1 << nodes_coord1, nodes_coord2;
    ns_edge1[0] = 1;
    ns_edge1[1] = 2;

    edges_coords2 << nodes_coord2, nodes_coord0;   
    ns_edge2[0] = 2;
    ns_edge2[1] = 0;

    // std::pair<std::array<size_type, 2>, GeometryPtr> edge_obj0(ns_edge0, std::make_unique<lf::geometry::SegmentO1>(edges_coords0));

    // std::pair<std::array<size_type, 2>, GeometryPtr> edge_obj1(ns_edge1, std::make_unique<lf::geometry::SegmentO1>(edges_coords1));

    // std::pair<std::array<size_type, 2>, GeometryPtr> edge_obj2(ns_edge2, std::make_unique<lf::geometry::SegmentO1>(edges_coords2));
    
    edges.emplace_back(ns_edge0, std::make_shared<lf::geometry::SegmentO1>(edges_coords0));
    edges.emplace_back(ns_edge1, std::make_shared<lf::geometry::SegmentO1>(edges_coords1));
    edges.emplace_back(ns_edge2, std::make_shared<lf::geometry::SegmentO1>(edges_coords2));


    // initialize cells
    int num_cells = 1;
    CellList cells;
    cells.reserve(num_cells);
    
    Eigen::Matrix<double, 2, 3> cells_coords0;
    cells_coords0 << nodes_coord0, nodes_coord1, nodes_coord2;

    std::array<size_type, 4> ns_cell0;
    ns_cell0[0] = 0;
    ns_cell0[1] = 1;
    ns_cell0[2] = 2;
    ns_cell0[3] = -1;

    // std::pair<std::array<size_type, 4>, GeometryPtr> cell_obj0(ns_cell0, std::make_unique<lf::geometry::TriaO1> (cells_coords0));

    cells.emplace_back(ns_cell0, std::make_shared<lf::geometry::TriaO1> (cells_coords0));

    lf::mesh::polytopicmesh::Mesh mesh(dim_world, nodes, edges, cells, false);
    // std::cout << "mesh_p->DimMesh()" << mesh_p->DimMesh();

    return 0;
}
}