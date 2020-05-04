//
// Created by Albert Galang on 5/2/20.
//

#include "EdgeWeighted.hpp"
#include "Vertex.hpp"

namespace UnitTest {
    class VertexUnitTests
    {
    public:
        static void make_BuildAVertexWithThreeEdges_PassWithObjectValueComparison()
        {
            auto V = Vertex<std::string, EdgeWeighted<std::string, int>>::make()
                        .setVertexValue("Reno")
                        .addEdge(EdgeWeighted<std::string, int>{"Reno", "San Francisco", 180})
                        .addEdge(EdgeWeighted<std::string, int>{"Reno", "Seattle", 431})
                        .addEdge(EdgeWeighted<std::string, int>{"Reno", "Las Vegas", 685})
                        .Build();

            auto edges = V.getAllEdges();

            auto result = (edges[0].To == "San Francisco" && edges[0].weight == 180) &&
                          (edges[1].To == "Seattle" && edges[1].weight == 431) &&
                          (edges[2].To == "Las Vegas" && edges[2].weight == 685);

            if (result)
                std::cout << "make_BuildAVertexWithThreeEdges_PassWithObjectValueComparison() : PASS" << std::endl;
            else
                std::cout << "make_BuildAVertexWithThreeEdges_PassWithObjectValueComparison() : FAIL" << std::endl;
        }
    };
}