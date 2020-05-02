//
// Created by Albert Galang on 4/28/20.
//

#ifndef HW7_NODE_HPP
#define HW7_NODE_HPP

#include <memory>
#include "INode.hpp"

template <typename itemType, typename weightType>
class VertexWeighted : INode<itemType>
{
private:
    itemType item;

    weightType weight;

    std::shared_ptr<VertexWeighted<itemType, weightType>> nextVertexPtr;

public:
    /**
     *
     * @brief Default constructor. Initialize a Vertex object with empty values.
     */
    VertexWeighted();
    /**
     *
     * @brief Overloaded constructor. Initialize a Vertex object with specified values.
     * @param item - set a Vertex item/value.
     * @param weight - set a Vertex weight value.
     * @param nextVertexPtr - set the next Vertex node link.
     */
    VertexWeighted(itemType item, weightType weight,
                   const std::shared_ptr<VertexWeighted<itemType, weightType>> &nextVertexPtr);
    /**
     *
     * @return Vertex item value
     */
    itemType getItem() const override;
    /**
     *
     * @param newItem  - new vertex value/item
     */
    void setItem(const itemType &newItem) override;
    /**
     *
     * @return Vertex weight value
     */
    weightType getWeight() const;
    /**
     *
     * @param newWeight  - new weight value
     */
    void setWeight(const weightType &newWeight);
    /**
     *
     * @return The next Vertex pointer as a shared pointer object.
     */
    std::shared_ptr<VertexWeighted<itemType, weightType>> getNextVertexPtr();
    /**
     *
     * @brief The Vertex pointer is converted into a shared pointer object.
     * @param vertexPtr - new next Vertex node pointer.
     */
    void setNextVertexPtr(const VertexWeighted<itemType, weightType> *vertexPtr);
    /**
     *
     * @param vertexPtr - new next Vertex shared pointer
     */
    void setNextVertexPtr(const std::shared_ptr<VertexWeighted<itemType, weightType>> &vertexPtr);
};


#include "VertexWeighted.cpp"
#endif //HW7_NODE_HPP
