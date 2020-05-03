//
// Created by Albert Galang on 4/28/20.
// Modified by Matt Facque on 5/02/20.

#ifndef HW7_WEIGHTEDGRAPH_HPP
#define HW7_WEIGHTEDGRAPH_HPP

template<typename T, typename edgeType> class WeightedGraph; // forward declaration
/**
 *
 * @class WeightedGraph will consist of Vertexs w/ weights
 * @tparam T - item type
 * @tparam edgeType - item type
 */
template<typename T, typename edgeType>
class WeightedGraph : IWeightedGraph
{
	private:
		std::vector<Vertex<T, edgeType>> adjacency_List;
		WeightedGraph() = default;

		int	vertex_Count;
		int	edge_Count;

	public:
		WeightedGraph(); 	// Constructor
		~WeightedGraph();	// Destructor

		/**
		 *
		 * @brief Add a vertex to graph
		 * @param Vertex<T, edgeType> new Vertex to add
		 */
		bool	add(Vertex<T, edgeType> a_Vertex);
		/**
		 *
		 * @brief Remove a vertex and subsequent edges from graph
		 * @param Vertex<T, edgeType> Vertex to be removed
		 */
		bool	remove(Vertex<T, edgeType> the_Vertex);
		/**
		 *
		 * @brief Checks to see if graph contains vertices or not
		 * @param null
		 * @return If no vertices (empty), return true otherwise false
		 */
		bool	is_Empty();
		/**
		 *
		 * @brief Returns the number of vertices in graph
		 * @param null
		 */
		int	get_Vertices();
		/**
		 *
		 * @brief Returns the number of edges in graph
		 * @param null
		 */
		int	get_Edges();
		/**
		 *
		 * @brief Returns the associated weight to the edge in question
		 * @param Vertex<T, edgeType> start_Vertex starting vertex
		 * 	  Vertex<T, edgeType> end_Vertex destination vertex
		 */
		int	get_EdgeWeight(Vertex<T, edgeType> start_Vertex, Vertex<T, edgeType> end_Vertex);
		/**
		 *
		 * @brief Traversal to 'visit' every vertex in the graph
		 * @param Vertex<T, edgeType> start_Vertex Start of traversal of graph
		 * @param void visit(&edgeType) place holder function to return value of vertex at 'visit' of vertex]
		 */
		void	BFTraversal(Vertex<T, edgeType> start_Vertex, void visit(&edgeType));
};

#include "WeightedGraph.cpp"
#endif //HW7_WEIGHTEDGRAPH_HPP
