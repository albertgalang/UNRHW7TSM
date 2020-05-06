/**
 * FILE:	IWeightedGraph.hpp
 * DESCRIPTION:	Interface file for WeightedGraph.hpp
 * AUTHOR		Date
 * Matt Facque		2020-05-02
 */

#ifndef _IWEIGHTEDGRAPH_HPP_
#define _IWEIGHTEDGRAPH_HPP_

#include <vector>

template <typename T, typename edgeType> class Vertex; // forward declaration

template <typename T, typename weightType>
class IWeightedGraph
{
	public:
		virtual ~IWeightedGraph() = default;

		//virtual bool add(Vertex<T, weightType> a_Vertex) = 0;
		virtual bool remove(const std::shared_ptr<NodeWeighted<T, weightType>> &vertex) = 0;
		virtual bool is_Empty() = 0;
		virtual int  get_Vertices()  = 0;
		virtual int  get_Edges(const std::shared_ptr<NodeWeighted<T, weightType>> &node) = 0;
//		virtual int  get_Edgeweight(Vertex<T, weightType> start_Vertex, Vertex<T, weightType> end_Vertex) = 0;
};

#endif // _IWEIGHTEDGRAPH_HPP_
