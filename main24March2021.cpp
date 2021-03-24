////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file app/main.cpp
/// @brief Extra calculations of hash sums for data blocks in multiple threads. uni::Thread approach
/// @author Sergey Polyakov <white.irbys@gmail.com>
/// @date 2020-2021
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/591/week-4-march-22nd-march-28th/3683/

// Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].
// Return any permutation of A that maximizes its advantage with respect to B.
// Example 1:
// Input: A = [2,7,11,15], B = [1,10,4,11]
// Output: [2,11,7,15]
// Example 2:
// Input: A = [12,24,8,32], B = [13,25,32,11]
// Output: [24,32,8,12]
// Note:
// 1 <= A.length = B.length <= 10000
// 0 <= A[i] <= 10^9
// 0 <= B[i] <= 10^9


class Solution
{
public:
    std::vector< int32_t >
    advantageCount( std::vector< int32_t >& A, std::vector< int32_t >& B )
    {
        if( A.size( ) <= 1U )
        {
            return A;
        }

        if( A.size( ) != B.size( ) )
        {
            return A;
        }

        // modify B as B1 set of pair <index,value> where sorted by value
        // sorting A as A1
        // reverse iterate through B1 set and in case of max A1 element is more then copy A1 element to result to appropriate index from B1 set.
        // In case of A1 has no bigger element, then copy minimum element from A.
        using index = int32_t;
        using value = int32_t;
        using BWithIndexes = std::pair< index, value >;

        auto cmp = []( BWithIndexes left, BWithIndexes right ) { return left.second > right.second; };
        std::multiset< BWithIndexes, decltype( cmp ) > s( cmp );
        index ind{ 0 };
        for( auto element : B )
        {
            s.insert( { ind, element } );
            ++ind;
        }

        std::sort( A.begin( ), A.end( ), std::greater< int32_t >( ) );

        std::vector< int32_t > result{};
        result.reserve( A.size( ) );
        result.resize( A.size( ) );
        int32_t left_ind = 0;
        int32_t right_ind = B.size( ) - 1;
        for( const auto& indexAndElementFromB : s )
        {
            if( A.at( left_ind ) > indexAndElementFromB.second )
            {
                result.at( indexAndElementFromB.first ) = A.at( left_ind );
                ++left_ind;
            }
            else
            {
                result.at( indexAndElementFromB.first ) = A.at( right_ind );
                --right_ind;
            }
        }

        return result;
    };
};

auto
main( int /*argc*/, char* * /*argv*/ ) -> int
{
    Solution solution;

    {
        std::cout << std::endl;
        std::vector< int32_t > A{ 2, 7, 11, 15 };
        std::vector< int32_t > B{ 1, 10, 4, 11 };

        std::vector< int32_t > EXPECTED{ 2, 11, 7, 15 };
        auto real = solution.advantageCount( A, B );
        if( EXPECTED != real )
        {
            std::cout << "ERROR" << std::endl;
            std::terminate( );
        }
        std::cout << "1 Test case passed" << std::endl;
    }

    {
        std::cout << std::endl;
        std::vector< int32_t > A{ 12, 24, 8, 32 };
        std::vector< int32_t > B{ 13, 25, 32, 11 };

        std::vector< int32_t > EXPECTED{ 24, 32, 8, 12 };
        auto real = solution.advantageCount( A, B );
        if( EXPECTED != real )
        {
            std::cout << "ERROR" << std::endl;
            std::terminate( );
        }
        std::cout << "2 Test case passed" << std::endl;
    }

    {
        std::cout << std::endl;
        std::vector< int32_t > A{ 2, 0, 4, 1, 2 };
        std::vector< int32_t > B{ 1, 3, 0, 0, 2 };

        std::vector< int32_t > EXPECTED{ 2, 0, 2, 1, 4 };
        auto real = solution.advantageCount( A, B );
        if( EXPECTED != real )
        {
            std::cout << "ERROR" << std::endl;
            std::terminate( );
        }
        std::cout << "3 Test case passed" << std::endl;
    }

    return 0;
}
