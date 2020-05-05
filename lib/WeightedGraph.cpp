//
// Created by Albert Galang on 4/28/20.
//

#include "WeightedGraph.hpp"

template<typename T, typename weightType>
template<typename edgeType>
bool WeightedGraph<T, weightType>::addVertex(const Vertex<T, edgeType> &newVertex)
{
    if (adjacencyListHas(newVertex)) return false;
    else
    {
        auto N = NodeWeighted<T, weightType>(newVertex.getItem(), 0, nullptr);
        auto headNodePtr = std::make_shared<NodeWeighted<T, weightType>>(N);
        auto tempPtr = headNodePtr;
        for (auto& edge : newVertex.getAllEdges())
        {
            auto W = NodeWeighted<T, weightType>(edge.To, edge.weight, nullptr);
            auto newNodePtr = std::make_shared<NodeWeighted<T, weightType>>(W);
            tempPtr->setNextNodeWeightedPtr(newNodePtr);
            tempPtr = tempPtr->getNextNodeWeightedPtr();
        }
        adjacencyList.push_back(headNodePtr);
    }
    return true;
} // addVertex

template<typename T, typename weightType>
bool WeightedGraph<T, weightType>::remove(const NodeWeighted<T, weightType> &vertex)
{
    return false;
} // remove

template<typename T, typename weightType>
bool WeightedGraph<T, weightType>::is_Empty()
{
    return false;
} // is_Empty

template<typename T, typename weightType>
int WeightedGraph<T, weightType>::get_Vertices()
{
    return 0;
} // get_Vertices

template<typename T, typename weightType>
int WeightedGraph<T, weightType>::get_Edges(const std::shared_ptr<NodeWeighted<T, weightType>> &node)
{
    int edgesCount = 0;
    auto targetPtr = node;
    while (targetPtr != nullptr) ++edgesCount;
    return edgesCount;
} // get_Edges

template<typename T, typename weightType>
template<typename edgeType>
void WeightedGraph<T, weightType>::BFTraversal(Vertex<T, edgeType> start_Vertex, void (*visit)(edgeType &))
{

} // BFTraversal

template<typename T, typename weightType>
template<typename edgeType>
bool WeightedGraph<T, weightType>::adjacencyListHas(const Vertex<T, edgeType> &V)
{
    if (adjacencyList.empty()) return false;
    else
    {
        for (auto& node : adjacencyList)
            if (node->getItem() == V.getItem()) return true;
    }
    return false;
} // adjacencyListHas

template<typename T, typename weightType>
bool WeightedGraph<T, weightType>::isConnected(const std::shared_ptr<NodeWeighted<T, weightType>> &V1,
                                               const std::shared_ptr<NodeWeighted<T, weightType>> &V2)
{
    auto Vertex = adjacencyList[getAdjacencyListPosition(V1)];
    while (Vertex != nullptr)
    {
        if (Vertex->getItem() == V2->getItem()) return true;
        Vertex = Vertex->getNextNodeWeightedPtr();
    }
    return false;
}

template<typename T, typename weightType>
bool WeightedGraph<T, weightType>::isConnected(const T &V1, const T &V2)
{
    int position;
    for (size_t i = 0; i < adjacencyList.size(); i++)
    {
        if (adjacencyList[i]->getItem() == V1) position = i;
    }

    auto vertex = adjacencyList[position]->getNextNodeWeightedPtr();
    while (vertex != nullptr)
    {
        if (vertex->getItem() == V2) return true;
        vertex = vertex->getNextNodeWeightedPtr();
    }
    return false;
}

template<typename T, typename weightType>
weightType WeightedGraph<T, weightType>::getWeight(const std::shared_ptr<NodeWeighted<T, weightType>> &from,
                                                   const std::shared_ptr<NodeWeighted<T, weightType>> &to)
{
    auto n = adjacencyList[getAdjacencyListPosition(from)];
    while (n != nullptr)
    {
        if (n->getItem() == to->getItem()) return n->getWeight();
        n = n->getNextNodeWeightedPtr();
    }
}

template<typename T, typename weightType>
weightType WeightedGraph<T, weightType>::getWeight(const T &from, const T &to)
{
    std::shared_ptr<NodeWeighted<T, weightType>> fromNodePtr;
    for (size_t i = 0; i < adjacencyList.size(); i++)
    {
        if (adjacencyList[i]->getItem() == from)
        {
            fromNodePtr = adjacencyList[i];
            break;
        }
    }

    auto n = fromNodePtr;
    weightType weight;
    while (n != nullptr)
    {
        if (n->getItem() == to) weight = n->getWeight();
        n = n->getNextNodeWeightedPtr();
    }
    return weight;
}
