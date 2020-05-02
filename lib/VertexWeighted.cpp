//
// Created by Albert Galang on 4/28/20.
//

template<typename itemType, typename weightType>
VertexWeighted<itemType, weightType>::VertexWeighted() : item(itemType()) , weight(weightType()), nextVertexPtr(nullptr)
{
} // default constructor

template<typename itemType, typename weightType>
VertexWeighted<itemType, weightType>::VertexWeighted(itemType item, weightType weight,
                                                     const std::shared_ptr<VertexWeighted<itemType, weightType>> &nextVertexPtr)
        :item(item), weight(weight), nextVertexPtr(nextVertexPtr)
{
} // overloaded constructor

template<typename itemType, typename weightType>
itemType VertexWeighted<itemType, weightType>::getItem() const {
    return item;
} // getItem

template<typename itemType, typename weightType>
void VertexWeighted<itemType, weightType>::setItem(const itemType &newItem)
{
    item = newItem;
} // setItem

template<typename itemType, typename weightType>
weightType VertexWeighted<itemType, weightType>::getWeight() const
{
    return weight;
} // getWeight

template<typename itemType, typename weightType>
void VertexWeighted<itemType, weightType>::setWeight(const weightType &newWeight)
{
    weight = newWeight;
} // setWeight

template<typename itemType, typename weightType>
std::shared_ptr<VertexWeighted<itemType, weightType>> VertexWeighted<itemType, weightType>::getNextVertexPtr()
{
    return nextVertexPtr;
} // get NextVertexPtr

template<typename itemType, typename weightType>
void VertexWeighted<itemType, weightType>::setNextVertexPtr(const VertexWeighted<itemType, weightType> *vertexPtr)
{
    nextVertexPtr = std::make_shared<VertexWeighted<itemType, weightType>>(vertexPtr);
} // setNextVertexPtr

template<typename itemType, typename weightType>
void VertexWeighted<itemType, weightType>::setNextVertexPtr(
        const std::shared_ptr<VertexWeighted<itemType, weightType>> &vertexPtr)
{
    nextVertexPtr = vertexPtr;
} // setNextVertexPtr


#include "VertexWeighted.hpp"

