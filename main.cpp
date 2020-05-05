#include "Graph.hpp"
#include <iostream>

int main() {
	std::cout << "Begin test_main" << std::endl << std::endl;

	typedef std::string City;
	typedef int Miles;

	auto Reno = Vertex<City, EdgeWeighted<City, Miles>>::make()
				.setVertexValue("Reno")
				.addEdge(EdgeWeighted<City, Miles>{"Reno", "San Francisco", 218})
				.addEdge(EdgeWeighted<City, Miles>{"Reno", "Las Vegas", 439})
				.addEdge(EdgeWeighted<City, Miles>{"Reno", "Seattle", 704})
				.addEdge(EdgeWeighted<City, Miles>{"Reno", "Salt Lake City", 518})
				.Build();
 
	auto Las_Vegas = Vertex<City, EdgeWeighted<City, Miles>>::make()
				.setVertexValue("Las Vegas")
				.addEdge(EdgeWeighted<City, Miles>{"Las Vegas", "Reno", 439})
				.addEdge(EdgeWeighted<City, Miles>{"Las Vegas", "San Francisco", 569})
				.addEdge(EdgeWeighted<City, Miles>{"Las Vegas", "Salt Lake City", 421})
				.addEdge(EdgeWeighted<City, Miles>{"Las Vegas", "Seattle", 1143})
				.Build();

	auto Salt_Lake_City = Vertex<City, EdgeWeighted<City, Miles>>::make()
				.setVertexValue("Salt Lake City")
				.addEdge(EdgeWeighted<City, Miles>{"Salt Lake City", "Reno", 518})
				.addEdge(EdgeWeighted<City, Miles>{"Salt Lake City", "Las Vegas", 421})
				.addEdge(EdgeWeighted<City, Miles>{"Salt Lake City", "San Francisco", 736})
				.addEdge(EdgeWeighted<City, Miles>{"Salt Lake City", "Seattle", 838})
				.Build();

	auto San_Francisco = Vertex<City, EdgeWeighted<City, Miles>>::make()
				.setVertexValue("San Francisco")
				.addEdge(EdgeWeighted<City, Miles>{"San Francisco", "Reno", 218})
				.addEdge(EdgeWeighted<City, Miles>{"San Francisco", "Las Vegas", 569})
				.addEdge(EdgeWeighted<City, Miles>{"San Francisco", "Salt Lake City", 736})
				.addEdge(EdgeWeighted<City, Miles>{"San Francisco", "Seattle", 808})
				.Build();

	auto Seattle = Vertex<City, EdgeWeighted<City, Miles>>::make()
				.setVertexValue("Seattle")
				.addEdge(EdgeWeighted<City, Miles>{"Seattle", "Reno", 704})
				.addEdge(EdgeWeighted<City, Miles>{"Seattle", "Las Vegas", 1143})
				.addEdge(EdgeWeighted<City, Miles>{"Seattle", "Salt Lake City", 838})
				.addEdge(EdgeWeighted<City, Miles>{"Seattle", "San Francisco", 808})
				.Build();

	auto graph = WeightedGraph<City, Miles>();
	graph.addVertex(Reno);
	graph.addVertex(Las_Vegas);
	graph.addVertex(Salt_Lake_City);
	graph.addVertex(Seattle);
	graph.addVertex(San_Francisco);

	auto total_miles = graph.find_ShortestPath();


	std::cout << "Best path mileage = " << total_miles << std::endl;
	return 0;
};

