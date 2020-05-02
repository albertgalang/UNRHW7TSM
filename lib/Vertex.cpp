//
// Created by Albert Galang on 5/2/20.
//

template<typename T, typename edgeType>
Vertex<T, edgeType>::Vertex(Vertex<T, edgeType> &&rightObj) noexcept
{
    this->item = std::move(rightObj.item);
    rightObj.edges.swap(this->edges);
} // Move constructor

template<typename T, typename edgeType>
std::vector<edgeType> Vertex<T, edgeType>::getAllEdges() const
{
    return edges;
} // getAllEdges

template<typename T, typename edgeType>
T Vertex<T, edgeType>::getItem() const
{
    return item;
} // getItem

