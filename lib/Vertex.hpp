//
// Created by Albert Galang on 5/2/20.
//

#ifndef UNRHW7TSM_VERTEX_HPP
#define UNRHW7TSM_VERTEX_HPP

#include "EdgeWeighted.hpp"

template <typename T, typename edgeType> class VertexBuilder; // forward declaration
/**
 *
 * @class Vertex is used for building a graph
 * @tparam T - Item type
 * @tparam edgeType - Edge type
 */
template <typename T, typename edgeType>
class Vertex
{
private:
    T item;

    std::vector<edgeType> edges;

    Vertex() = default;

public:
    friend VertexBuilder<T, edgeType>;

    Vertex(const Vertex<T, edgeType>&) = delete; // copy constructor
    Vertex<T, edgeType>& operator=(const Vertex<T, edgeType>&) = delete; // copy operator
    /**
     *
     * @brief Move constructor
     * @param rightObj - Vertex object.
     */
    Vertex(Vertex<T, edgeType> &&rightObj) noexcept;
    /**
     *
     * @brief Initiate builder process.
     * @return VertexBuilder
     */
    static VertexBuilder<T, edgeType> make()
    {
        return VertexBuilder<T, edgeType>();
    }
    /**
     *
     * @return All registered edges as a vector package.
     * @note Move semantics already applied.
     */
    std::vector<edgeType> getAllEdges() const;
    /**
     *
     * @return Vertex item value.
     */
    T getItem() const;
};
/**
 *
 * @class VertexBuilder builds Vertex type object.
 * @tparam T - Item type
 * @tparam edgeType - Edge type
 */
template <typename T, typename edgeType>
class VertexBuilder
{
private:
    Vertex<T, edgeType> vertex;

public:
    /**
     *
     * @param value - Vertex item value
     * @return Builder
     */
    VertexBuilder<T, edgeType>& setVertexValue(const T& value)
    {
        vertex.item = value;
        return *this;
    }
    /**
     *
     * @param newEdge - An Edge type
     * @return Builder
     */
    VertexBuilder<T, edgeType>& addEdge(const edgeType& newEdge)
    {
        vertex.edges.push_back(newEdge);
        return *this;
    }
    /**
     *
     * @brief End build.
     * @return Vertex object.
     */
    Vertex<T, edgeType>&& Build()
    {
        return std::move(vertex);
    }

};


#include "Vertex.cpp"
#endif //UNRHW7TSM_VERTEX_HPP
