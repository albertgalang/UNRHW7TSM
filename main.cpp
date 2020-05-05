#include "Graph.hpp"
#include <iostream>

int main() {
	std::cout << "Begin test_main" << std::endl << std::endl;

	auto Reno = Vertex<std::string, EdgeWeighted<std::string, int>.make()
				.setVertexValue("Reno")
				.addEdge(EdgeWeighted<std::string, int>{"Reno", "San Francisco", 218})
				.addEdge(EdgeWeighted<std::string, int>{"Reno", "Las Vegas", 439})
				.addEdge(EdgeWeighted<std::string, int>{"Reno", "Seattle", 704})
				.addEdge(EdgeWeighted<std::string, int>{"Reno", "Salt Lake City", 518})
				.Build();

	auto Las_Vegas = Vertex<std::string, EdgeWeighted<std::string, int>>.make()
				.setVertexValue("Las Vegas")
				.addEdge(EdgeWeighted<std::string, int>{"Las Vegas", "Reno", 439})
				.addEdge(EdgeWeighted<std::string, int>{"Las Vegas", "San Francisco", 569})
				.addEdge(EdgeWeighted<std::string, int>{"Las Vegas", "Salt Lake City", 421})
				.addEdge(EdgeWeighted<std::string, int>{"Las Vegas", "Seattle", 1143})
				.Build();

	auto Salt_Lake_City = Vertex<std::string, EdgeWeighted<std::string, int>>.make()
				.setVertexValue("Salt Lake City")
				.addEdge(EdgeWeighted<std::string, int>{"Salt Lake City", "Reno", 518})
				.addEdge(EdgeWeighted<std::string, int>{"Salt Lake City", "Las Vegas", 421})
				.addEdge(EdgeWeighted<std::string, int>{"Salt Lake City", "San Francisco", 736})
				.addEdge(EdgeWeighted<std::string, int>{"Salt Lake City", "Seattle", 838})
				.Build();

	auto San_Francisco = Vertex<std::string, EdgeWeighted<std::string, int>>.make()
				.setVertexValue("San Francisco")
				.addEdge(EdgeWeighted<std::string, int>{"San Francisco", "Reno", 218})
				.addEdge(EdgeWeighted<std::string, int>{"San Francisco", "Las Vegas", 569})
				.addEdge(EdgeWeighted<std::string, int>{"San Francisco", "Salt Lake City", 736})
				.addEdge(EdgeWeighted<std::string, int>{"San Francisco", "Seattle", 808})

	auto Seattle = Vertex<std::string, EdgeWeighted<std::string, int>>.make()
				.setVertexValue("Seattle")
				.addEdge(EdgeWeighted<std::string, int>{"Seattle", "Reno", 704})
				.addEdge(EdgeWeighted<std::string, int>{"Seattle", "Las Vegas", 1143})
				.addEdge(EdgeWeighted<std::string, int>{"Seattle", "Salt Lake City", 838})
				.addEdge(EdgeWeighted<std::string, int>{"Seattle", "San Francisco", 808})
				.Build();

	auto Graph = WeightedGraph<std::string, EdgeWeighted<std::string, int>>();
	graph.addVertex(Reno);
	graph.addVertex(Las_Vegas);
	graph.addVertex(Salt_Lake_City);
	graph.addVertex(Seattle);
	graph.addVertex(San_Francisco);

	auto total_miles = Graph.find_ShortestPath();

	std::cout << "Best path mileage = " << total_miles << std::endl;
	
