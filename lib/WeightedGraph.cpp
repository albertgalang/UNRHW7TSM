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

template<typename T, typename weightType>
auto WeightedGraph<T, weightType>::find_ShortestPath() {
    //  Convert adjacency list to matrix [5][5]
    auto ad_matrix[adjacency_list.size()][adjacency_list.size()];

    //  NodeWeighted ptrs to help in making the matrix
    NodeWeighted<itemType, weightType>* traversalPtr = nullptr;
    NodeWeighted<itemType, weightType>* targetPtr = nullptr;

    //  Nested for loops to make ad_matrix
    for (int i = 0; i < adjacency_list.size(); i++) {
        traversalPtr = adjacency_list[i];
        targetPtr = traversalPtr.getNextNodeWeightedPtr();

        for (int j = 0; j < adjacency_list.size(); j++) {

            auto item = targetPtr.getItem();

            if (i == j){
                ad_matrix[i][j] = 0;
            }
            else if (item == "Reno"){                       //  If Reno, 0th column
                ad_matrix[i][0] = targetPtr.getWeight();
            }
            else if (item == "Las Vegas"){                  //  If Las Vegas, 1st column
                ad_matrix[i][1] = targetPtr.getWeight();
            }
            else if (item == "Salt Lake City"){             //  If Salt Lake City, 2nd column
                ad_matrix[i][2] = targetPtr.getWeight();
            }
            else if (item == "Seattle"){                    //  If Seattle, 3rd column
                ad_matrix[i][3] = targetPtr.getWeight();    
            }
            else {                                          //  If San Francisco, 4th column
                ad_matrix[i][4] = targetPtr.getWeight();    
            }

            targetPtr = targetPtr.getNextNodeWeightedPtr();
        }

    }

//  This vector will be used to create the paths, the cities are converted to number values corresponding to columns
    vector<int> cities                      

    //  Add the cities to travel through to cities vector
    //  Cities will be cities{1, 2, 3, 4}
    //  1 - LV, 2 - SLC, 3 - S, 4 - SF
    for (int i = 0; i < adjacency_list.size() - 1; i++) {
        cities.push_back(i+1);
    }
    
    auto bestPathWeight = 0;

    //  Do while loop to run permutations and collect best path weight
    do {
        auto currentWeight = 0;
        int start = 0;
        int path = 0;

        for (int i = 0; i < cities.size(); i++) {
            currentWeight += ad_matrix[path][cities[i]];
            path = cities[i];
        }
        currentWeight += ad_matrix[path][start];
        bestPathWeight = std::min(bestPathWeight, currentWeight);
    }
    while (next_permutation(cities.begin(), cities.end()));

    return bestPathWeight;
}