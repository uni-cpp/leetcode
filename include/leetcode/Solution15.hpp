// 15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and
// nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Example 1:
//  Input: nums = [-1,0,1,2,-1,-4]
//  Output: [[-1,-1,2],[-1,0,1]]

// Example 2:
//  Input: nums = []
//  Output: []

// Example 3:
//  Input: nums = [0]
//  Output: []

// Constraints:
//  0 <= nums.length <= 3000
//  -105 <= nums[i] <= 105

#pragma once

#include <cstdint>
#include <iostream>
#include <vector>

namespace leetcode
{

class Solution15
{
public:
    std::vector< std::vector< int32_t > > threeSum( std::vector< int32_t >& nums );
};

}  // namespace leetcode


template < typename T >
std::ostream&
operator<<( std::ostream& os, const std::vector< T >& v )
{
    os << "[";
    for( size_t i{ 0 }; i < v.size( ); ++i )
    {
        os << v[ i ];
        if( i != v.size( ) - 1 )
        {
            os << ",";
        }
    }
    os << "]";
    return os;
}

template < typename T >
std::ostream&
operator<<( std::ostream& os, const std::vector< std::vector< T > >& v )
{
    os << "[";
    for( size_t i{ 0 }; i < v.size( ); ++i )
    {
        os << v[ i ];
        if( i != v.size( ) - 1 )
        {
            os << ",";
        }
    }
    os << "]";
    return os;
}
