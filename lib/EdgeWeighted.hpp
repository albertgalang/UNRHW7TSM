//
// Created by Albert Galang on 5/2/20.
//

#ifndef HW7_EDGEWEIGHTED_HPP
#define HW7_EDGEWEIGHTED_HPP


#include <vector>

template <typename itemType, typename weightType>
struct EdgeWeighted
{
    itemType From;

    itemType To;

    weightType weight;
};


#endif // HW7_EDGEWEIGHTED_HPP
