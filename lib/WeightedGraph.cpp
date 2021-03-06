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
bool WeightedGraph<T, weightType>::remove(const std::shared_ptr<NodeWeighted<T, weightType>> &vertex)
{
    auto node = vertex;
    auto position = getAdjacencyListPosition(node);
    adjacencyList.erase(adjacencyList.begin()+position);
    return false;
} // remove

template<typename T, typename weightType>
bool WeightedGraph<T, weightType>::is_Empty()
{
    return adjacencyList.empty();
} // is_Empty

template<typename T, typename weightType>
int WeightedGraph<T, weightType>::get_Vertices()
{
    return adjacencyList.size();
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
weightType WeightedGraph<T, weightType>::find_ShortestPath() {

    std::fstream fout;
    fout.open("Final_Txt.txt", std::ios::out);

    std::cout << "Miles from and to: " << std::endl;
    for (auto& linkedNode : adjacencyList)
    {
        auto headNodePtr = linkedNode->getNextNodeWeightedPtr();
        while (headNodePtr != nullptr)
        {
            std::cout << '\t' << linkedNode->getItem() << " -> " << headNodePtr->getItem() << " = " << headNodePtr->getWeight() << " miles" << std::endl;
            fout << '\t' << linkedNode->getItem() << " -> " << headNodePtr->getItem() << " = " << headNodePtr->getWeight() << " miles" << std::endl;
            headNodePtr = headNodePtr->getNextNodeWeightedPtr();
        }
        std::cout << std::endl;
        fout << std::endl;
    }
    std::cout << "\n\n";
    fout << "\n\n";

    //  Convert adjacency list to matrix [5][5]
    weightType ad_matrix[adjacencyList.size()][adjacencyList.size()];

    for (size_t i = 0; i < adjacencyList.size(); i++)
    {
        for (size_t j = 0; j < adjacencyList.size(); j++)
            ad_matrix[i][j] = 0;
    }


    //  Nested for loops to make ad_matrix
    for (int i = 0; i < adjacencyList.size(); i++)
    {
        auto traversalPtr = adjacencyList[i];
        auto targetPtr = traversalPtr;

        for (int j = 0; j < 5; j++)
        {
            auto resolvePosition = getAdjacencyListPosition(targetPtr);
            ad_matrix[i][resolvePosition] = targetPtr->getWeight();
            targetPtr = targetPtr->getNextNodeWeightedPtr();
        }

    }

//  This vector will be used to create the paths, the cities are converted to number values corresponding to columns
    std::vector<int> cities;                    
    std::vector<int> best_cities;

    //  Add the cities to travel through to cities vector
    //  Cities will be cities{1, 2, 3, 4}
    //  1 - LV, 2 - SLC, 3 - S, 4 - SF
    for (int i = 0; i < adjacencyList.size() - 1; i++)
        cities.push_back(i+1);

    auto bestPathWeight = 0;
    auto current_minWeight = 10000;

    int pathNumber = 0;
    //  Do while loop to run permutations and collect best path weight
    do {
//      auto current_minWeight = 0;
        auto currentWeight = 0;
        int start = 0;
        int path = 0;

        std::cout << "Path number : " << ++pathNumber << std::endl;
        std::cout << "\tReno -> ";
        fout << "\tReno -> ";
        for (int cityNum : cities)
        {
            if (cityNum == 1){
                std::cout << "Las Vegas -> ";
                fout << "Las Vegas -> ";
            }
            else if (cityNum == 2){
                std::cout << "Salt Lake City -> ";
                fout << "Salt Lake City -> ";
            }
            else if (cityNum == 3){
                std::cout << "Seattle -> ";
                fout << "Seattle -> ";
            }
            else if (cityNum == 4){
                std::cout << "San Francisco -> ";
                fout << "San Francisco -> ";
            }
        }
        std::cout << "Reno" << std::endl;
        fout << "Reno" << std::endl;


        for (auto & cityPos : cities)
        {
            currentWeight += ad_matrix[path][cityPos];
            path = cityPos;
        }
        currentWeight += ad_matrix[path][start];
        std::cout << "\tPath total miles = " << currentWeight << " miles" << std::endl;
        fout << "\tPath total miles = " << currentWeight << " miles" << std::endl;
        std::cout << std::endl;
        fout << std::endl;
//      current_minWeight = currentWeight;
        if (currentWeight < current_minWeight){
            current_minWeight = currentWeight;
            for (int i = 0; i < cities.size(); i++){
                best_cities.push_back(cities[i]);
            }
        }
        bestPathWeight = std::min(current_minWeight, currentWeight);

    } while (next_permutation(cities.begin(), cities.end()));

    auto gallons = bestPathWeight / 40;

//  Output the path of the best combination of cities
    std::cout << "Best Path (cities): ";
    fout << "Best Path (cities): ";
    std::cout << "Reno -> ";
    fout << "Reno -> ";
    for (int i = 0; i < best_cities.size(); i++) {
        if (best_cities[i] == 1){
            std::cout << "Las Vegas -> ";
            fout << "Las Vegas -> ";
        }
        else if (best_cities[i] == 2){
            std::cout << "Salt Lake City -> ";
            fout << "Salt Lake City -> ";
        }
        else if (best_cities[i] == 3){
            std::cout << "Seattle -> ";
            fout << "Seattle -> ";
        }
        else if (best_cities[i] == 4){
            std::cout << "San Francisco -> ";
            fout << "San Francisco -> ";
        }
    }
    std::cout << "Reno" << std::endl;
    fout << "Reno" << std::endl;

    fout << "Best Path (miles): " << bestPathWeight << std::endl;
    std::cout << "Gallons of gas used: " << gallons << std::endl;
    fout << "Gallons of gas used: " << gallons << std::endl;
    fout.close();

    return bestPathWeight;
}

template<typename T, typename weightType>
int WeightedGraph<T, weightType>::getAdjacencyListPosition(const std::shared_ptr<NodeWeighted<T, weightType>> &node)
{
    auto value = node->getItem();
    for (size_t i = 0; i < adjacencyList.size(); i++)
    {
        if (adjacencyList[i]->getItem() == value) return i;
    }
    return -1;
} // getAdjacencyListPosition
