//
// Created by Albert Galang on 4/28/20.
//

template<typename itemType, typename weightType>
NodeWeighted<itemType, weightType>::NodeWeighted() : item(itemType()) , weight(weightType()), nextNodeWeightedPtr(nullptr)
{
} // default constructor

template<typename itemType, typename weightType>
NodeWeighted<itemType, weightType>::NodeWeighted(itemType item, weightType weight,
                                                 const std::shared_ptr<NodeWeighted<itemType, weightType>> &nextNodeWeightedPtr)
        :item(item), weight(weight), nextNodeWeightedPtr(nextNodeWeightedPtr)
{
} // overloaded constructor

template<typename itemType, typename weightType>
itemType NodeWeighted<itemType, weightType>::getItem() const {
    return item;
} // getItem

template<typename itemType, typename weightType>
void NodeWeighted<itemType, weightType>::setItem(const itemType &newItem)
{
    item = newItem;
} // setItem

template<typename itemType, typename weightType>
weightType NodeWeighted<itemType, weightType>::getWeight() const
{
    return weight;
} // getWeight

template<typename itemType, typename weightType>
void NodeWeighted<itemType, weightType>::setWeight(const weightType &newWeight)
{
    weight = newWeight;
} // setWeight

template<typename itemType, typename weightType>
std::shared_ptr<NodeWeighted<itemType, weightType>> NodeWeighted<itemType, weightType>::getNextNodeWeightedPtr()
{
    return nextNodeWeightedPtr;
} // get NextVertexPtr

template<typename itemType, typename weightType>
void NodeWeighted<itemType, weightType>::setNextNodeWeightedPtr(const NodeWeighted<itemType, weightType> *nodeWeightedPtr)
{
    nextNodeWeightedPtr = std::make_shared<NodeWeighted<itemType, weightType>>(nodeWeightedPtr);
} // setNextNodeWeightedPtr

template<typename itemType, typename weightType>
void NodeWeighted<itemType, weightType>::setNextNodeWeightedPtr(
        const std::shared_ptr<NodeWeighted<itemType, weightType>> &nodeWeightedPtr)
{
    nextNodeWeightedPtr = nodeWeightedPtr;
} // setNextNodeWeightedPtr

