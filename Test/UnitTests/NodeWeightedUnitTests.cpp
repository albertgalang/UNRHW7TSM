//
// Created by Albert Galang on 4/28/20.
//

#include "NodeWeighted.hpp"
#include <string>
#include <iostream>

namespace UnitTest {
    class NodeWeightedUnitTests
    {
    public:
        static void setItem_SetAnItemIntoAnEmptyVertex_PassWithTheSameValueComparison()
        {
            auto V = NodeWeighted<std::string, int>();

            std::string City = "Reno";

            V.setItem(City);

            auto result = V.getItem() == City;

            if (result)
                std::cout << "setItem_SetAnItemIntoAnEmptyVertex_PassWithTheSameValueComparison() : PASS" << std::endl;
            else
                std::cout << "setItem_SetAnItemIntoAnEmptyVertex_PassWithTheSameValueComparison() : FAIL" << std::endl;
        }

        static void setWeight_SetAWeightValueIntoAnEmptyVertex_PassWithTheSameValueComparison()
        {
            auto V = NodeWeighted<std::string, int>();

            int Miles = 123098;

            V.setWeight(Miles);

            auto result = V.getWeight() == Miles;

            if (result)
                std::cout << "setWeight_SetAWeightValueIntoAnEmptyVertex_PassWithTheSameValueComparison() : PASS" << std::endl;
            else
                std::cout << "setWeight_SetAWeightValueIntoAnEmptyVertex_PassWithTheSameValueComparison() : FAIL" << std::endl;
        }

        static void VertexWeighted_InitializeAVertexObjectWithTheOverloadedConstructor_PassWithSameValuesComparison()
        {
            std::string City = "Reno";
            int Miles = 120983;
            auto V = NodeWeighted<std::string, int>(City, Miles, nullptr);

            auto result = (V.getNextNodeWeightedPtr() == nullptr) &&
                    (V.getItem() == City) &&
                    (V.getWeight() == Miles);

            if (result)
                std::cout << "VertexWeighted_InitializeAVertexObjectWithTheOverloadedConstructor_PassWithSameValuesComparison() : PASS" << std::endl;
            else
                std::cout << "VertexWeighted_InitializeAVertexObjectWithTheOverloadedConstructor_PassWithSameValuesComparison() : FAIL" << std::endl;
        }
    };
}
