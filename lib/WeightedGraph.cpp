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
        adjacencyList.emplace_back(headNodePtr);
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
int WeightedGraph<T, weightType>::get_Edges()
{
    return 0;
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
weightType WeightedGraph<T, weightType>::find_ShortestPath() {
    std::cout << "SHORTEST PATH" << std::endl;

    //  Convert adjacency list to matrix [5][5]
    weightType ad_matrix[adjacencyList.size()][adjacencyList.size()];

    std::cout << "MATRIX BUILT" << std::endl;
    //  NodeWeighted ptrs to help in making the matrix
    std::shared_ptr<NodeWeighted<T, weightType>> traversalPtr = nullptr;
    std::shared_ptr<NodeWeighted<T, weightType>> targetPtr = nullptr;

    //  Nested for loops to make ad_matrix
    for (int i = 0; i < adjacencyList.size(); i++) {
        traversalPtr = adjacencyList[i];
//      targetPtr = traversalPtr->getNextNodeWeightedPtr();
        targetPtr = traversalPtr;
        auto item = targetPtr->getItem();
//        std::cout << "ROW ADD" << std::endl;
//        std::cout << "ROW ITEM = " << item << std::endl;

//        std::cout << "ROW ADD" << std::endl;

        for (int j = 0; j < 5; j++) {

            std::cout << "COLUMN ADD" << std::endl;

            auto item = traversalPtr->getItem();
//            std::cout << "ITEM WEIGHT = " << item << std::endl;

//             if (i == j){
// //                ad_matrix[i][j] = 0;
// //                std::cout << "weight = " << ad_matrix[i][j] << std::endl;
//             }
//             else if (item == "Reno"){                       //  If Reno, 0th column
//                 //ad_matrix[i][0] = targetPtr->getWeight();
//                 ad_matrix[0][j] = 0;
// //                std::cout << "weight = " << ad_matrix[i][0] << std::endl;
//             }
//             else if (item == "Las Vegas"){                  //  If Las Vegas, 1st column
//                 //ad_matrix[i][1] = targetPtr->getWeight();
//                 ad_matrix[1][j] = 0;
// //                std::cout << "weight = " << ad_matrix[i][1] << std::endl;
//             }
//             else if (item == "Salt Lake City"){             //  If Salt Lake City, 2nd column
//                 //ad_matrix[i][2] = targetPtr->getWeight();
//                 ad_matrix[2][j] = 0;
// //                std::cout << "weight = " << ad_matrix[i][2] << std::endl;
//             }
//             else if (item == "Seattle"){                    //  If Seattle, 3rd column
//                 //ad_matrix[i][3] = targetPtr->getWeight();
//                 ad_matrix[3][j] = 0;    
//  //               std::cout << "weight = " << ad_matrix[i][3] << std::endl;
//             }
//             else if (item == "San Francisco") {                                          //  If San Francisco, 4th column
//                 ad_matrix[4][j] = targetPtr->getWeight();
//  //               std::cout << "weight = " << ad_matrix[i][4] << std::endl;    
//             }

//             targetPtr = targetPtr->getNextNodeWeightedPtr();

            enum {R, LV, SLC, S, SF};


            if (i == j)
            {
                ad_matrix[i][j] = 0;
            }
            else
            {
                auto resolvePosition = getAdjacencyListPosition(targetPtr);
                ad_matrix[i][resolvePosition] = targetPtr->getWeight();
            }

            targetPtr = targetPtr->getNextNodeWeightedPtr();
        }

    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << ad_matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }

//  This vector will be used to create the paths, the cities are converted to number values corresponding to columns
    std::vector<int> cities;                      

    std::cout << "CITIES VECTOR BUILT" << std::endl;

    //  Add the cities to travel through to cities vector
    //  Cities will be cities{1, 2, 3, 4}
    //  1 - LV, 2 - SLC, 3 - S, 4 - SF
    for (int i = 0; i < adjacencyList.size() - 1; i++) {
        cities.push_back(i+1);
    }
    
    std::cout << "CITIS w/ INT" << std::endl;

    auto bestPathWeight = 0;

    //  Do while loop to run permutations and collect best path weight
    do {
        auto currentWeight = 0;
        int start = 0;
        int path = 0;

        std::cout << "DO WHILE LOOP" << std::endl;

        for (int i = 0; i < cities.size(); i++) {
            currentWeight += ad_matrix[path][cities[i]];
            path = cities[i];
        }
        currentWeight += ad_matrix[path][start];
        bestPathWeight = std::min(bestPathWeight, currentWeight);

    }
    while (next_permutation(cities.begin(), cities.end()));
    std::cout << "PROBLEM FINISHED" << std::endl;

    return bestPathWeight;
}