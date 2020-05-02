//
// Created by Albert Galang on 5/2/20.
//

#ifndef UNRHW7TSM_INODE_HPP
#define UNRHW7TSM_INODE_HPP

template <typename T>
class INode
{
public:
    virtual T getItem() const = 0;
    virtual void setItem(const T &newItem) = 0;

    virtual ~INode() = default;
};

#endif //UNRHW7TSM_INODE_HPP
