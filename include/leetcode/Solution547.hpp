// 547. Number of Provinces

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected
// directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected,
// and isConnected[i][j] = 0 otherwise. Return the total number of provinces.

// Example 1:
//  Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//  Output: 2

// Example 2:
//  Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//  Output: 3

// Constraints:
//  1 <= n <= 200
//  n == isConnected.length
//  n == isConnected[i].length
//  isConnected[i][j] is 1 or 0.
//  isConnected[i][i] == 1
//  isConnected[i][j] == isConnected[j][i]

#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace leetcode
{

// https://www.geeksforgeeks.org/disjoint-set-data-structures/
// https://en.wikipedia.org/wiki/Disjoint-set_data_structure
class DisjointSet
{
public:
    explicit DisjointSet( size_t n );

    void unite( size_t element1, size_t element2 );
    size_t find( size_t element );
    size_t count( ) const;

private:
    std::vector< size_t > m_parents{ };
    std::vector< size_t > m_ranks{ };
    size_t m_groups{ 0U };
};

class Solution547
{
public:
    uint32_t findCircleNum( const std::vector< std::vector< uint8_t > >& isConnected );
};

}  // namespace leetcode
