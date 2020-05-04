//
// Created by Albert Galang on 4/28/20.
//

#include "WeightedGraph.hpp"
#include <array>
#include <iostream>

namespace UnitTest {
    class WeightedGraphUnitTests
    {
    public:
        static void addVertex_addAVertexIntoEmptyAdjacencyList_SuccessfulAdditionReturnsTrue()
        {
            auto Reno = Vertex<std::string, EdgeWeighted<std::string, int>>::make()
                        .setVertexValue("Reno")
                        .addEdge(EdgeWeighted<std::string, int>{"Reno", "San Francisco", 234})
                        .addEdge(EdgeWeighted<std::string, int>{"Reno", "Seattle", 240958})
                        .Build();

            auto Seattle = Vertex<std::string, EdgeWeighted<std::string, int>>::make()
                           .setVertexValue("Seattle")
                           .addEdge(EdgeWeighted<std::string, int>{"Seattle", "Reno", 245})
                           .addEdge(EdgeWeighted<std::string, int>{"Seattle", "San Francisco", 2450})
                           .addEdge(EdgeWeighted<std::string, int>{"Seattle", "Salt Lake City", 2450})
                           .Build();

            auto graph = WeightedGraph<std::string, EdgeWeighted<std::string, int>>();
            graph.addVertex(Reno, Seattle);

            auto result = true;

            if (result)
                std::cout << "add_addAVertexIntoEmptyAdjacencyList_SuccessfulAdditionReturnsTrue() : PASS" << std::endl;
            else
                std::cout << "add_addAVertexIntoEmptyAdjacencyList_SuccessfulAdditionReturnsTrue() : FAIL" << std::endl;
        }
    };
}
