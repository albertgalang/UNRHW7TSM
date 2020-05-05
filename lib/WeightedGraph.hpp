//
// Created by Albert Galang on 4/28/20.
// Modified by Matt Facque on 5/02/20.

#ifndef HW7_WEIGHTEDGRAPH_HPP
#define HW7_WEIGHTEDGRAPH_HPP

#include "NodeWeighted.hpp"
#include "IWeightedGraph.hpp"
#include "Vertex.hpp"
#include <memory>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>

//fstream fout;
//fout.open("Final_Txt.txt", ios::out)

template<typename T, typename edgeType> class WeightedGraph; // forward declaration
/**
 *
 * @class WeightedGraph will consist of Vertexs w/ weights
 * @tparam T - item type
 * @tparam edgeType - item type
 */
template<typename T, typename weightType>
class WeightedGraph : public IWeightedGraph<T, weightType>
{
private:
    std::vector<std::shared_ptr<NodeWeighted<T, weightType>>> adjacencyList;

    int	vertex_Count;
    int	edge_Count;

    /**
     *
     * @category Private helper method
     * @brief Check for existing Vertex in the adjacency list.
     * @param item
     * @return
     */
    template <typename edgeType>
    bool adjacencyListHas(const Vertex<T, edgeType> &V);
    /**
     *
     * @brief Check if vertex are connectec
     * @param V1  - vertex type
     * @param V2  - vertex type
     * @return  - bool
     */
    bool isConnected(const std::shared_ptr<NodeWeighted<T, weightType>> &V1, const std::shared_ptr<NodeWeighted<T, weightType>> &V2);
    /**
     *
     * @brief check if vertex are connected by value
     * @param V1  - value type
     * @param V2  - value type
     * @return  bool
     */
    bool isConnected(const T &V1, const T &V2);

public:
    WeightedGraph() = default; 	// Constructor
    ~WeightedGraph() = default;	// Destructor
   /**
    *
    * @tparam edgeType
    * @param newVertex
    * @return
    *
    */
    template <typename edgeType>
    bool addVertex(const Vertex<T, edgeType> &newVertex);
    /**
     *
     * @brief Remove a vertex and subsequent edges from gra:ph
     * @param Vertex<T, edgeType> Vertex to be removed
     */
    bool remove(const NodeWeighted<T, weightType> &vertex) override;
    /**
     *
     * @brief Checks to see if graph contains vertices or not
     * @param null
     * @return If no vertices (empty), return true otherwise false
     */
    bool is_Empty() override;
    /**
     *
     * @brief Returns the number of vertices in graph
     * @param null
     */
    int	get_Vertices() override ;
    /**
     *
     * @brief Returns the number of edges in graph
     * @param null
     */
    int	get_Edges()override ;
    /**
     *
     * @brief Traversal to 'visit' every vertex in the graph
     * @param Vertex<T, edgeType> start_Vertex Start of traversal of graph
     * @param void visit(&edgeType) place holder function to return value of vertex at 'visit' of vertex]
     */
    template<typename edgeType>
    void BFTraversal(Vertex<T, edgeType> start_Vertex, void visit(edgeType&));
    /**
     *
     * @brief get weight between vertex by node type
     * @param from - shared pointer node type
     * @param to  - shared pointer node type
     * @return  weight type
     */
    weightType getWeight(const std::shared_ptr<NodeWeighted<T, weightType>> &from, const std::shared_ptr<NodeWeighted<T, weightType>> &to);
    /**
     *
     * @brief get weight between vertex by value
     * @param from  value type
     * @param to  value type
     * @return  weight type
     */
    weightType getWeight(const T &from, const T&to);
    /**
     *
     * @brief Find best path weight
     * @param null
     * @return weight
     */
     weightType find_ShortestPath();
};

#include "WeightedGraph.cpp"
#endif //HW7_WEIGHTEDGRAPH_HPP
