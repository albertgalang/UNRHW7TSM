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

template <typename T, typename edgeType>
class IWeightedGraph
{
	public:
		virtual ~IWeightedGraph() = default;

		virtual bool add(Vertex<T, edgeType> a_Vertex) = 0;
		virtual bool remove(Vertex<T, edgeType> the_Vertex) = 0;
		virtual bool is_Empty() = 0;
		virtual int  get_Vertices()  = 0;
		virtual int  get_Edges() = 0;
		virtual int  get_Edgeweight(Vertex<T, edgeType> start_Vertex, Vertex<T, edgeType> end_Vertex) = 0;

		virtual void BFTraversal(Vertex<T, edgeType> start_Vertex, void visit(edgeType&)) = 0;
};

#endif // _IWEIGHTEDGRAPH_HPP_
