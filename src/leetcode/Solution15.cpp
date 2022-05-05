#include <leetcode/Solution15.hpp>

#include <algorithm>

namespace leetcode
{

// After sort
// -2 -2 -1 -1 0 0 1 2 3 4 5 Target 0
// |                         - base_iter, should iterate only on unique numbers
//        |                  - left iter, should iterate only on unique numbers
//                         | - right iter, should iterate only on unique numbers
// base from 0 to size - 2
// left from base to right
// right from size-2 to left
// left and right became closer every step based on difference their sum and (target - base_it)
// base iterate in case of
// a) after (left + 1 == right)
// b) -(target - base_it) < left*2
// c) -(target - base_it) > right*2

std::vector< std::vector< int32_t > >
Solution15::threeSum( std::vector< int32_t >& nums )
{
    if( nums.size( ) <= 2U )
    {
        return { };
    }

    std::sort( nums.begin( ), nums.end( ) );

    if( nums.front( ) > 0 || nums.back( ) < 0 )
    {
        return { };
    }

    std::vector< std::vector< int32_t > > result;
    const int32_t BASE_LIMIT = nums.size( ) - 2;
    for( int32_t base{ 0U }; base < BASE_LIMIT; )
    {
        if( !result.empty( ) && result.back( )[ 0 ] == nums[ base ] )
        {
            continue;
        }

        int32_t to_find = 0 - nums[ base ];

        int32_t left{ base + 1 };
        int32_t right = nums.size( ) - 1;

        while( left < right )
        {
            int32_t sum2 = nums[ left ] + nums[ right ];

            if( to_find == sum2 )
            {
                result.push_back( { nums[ base ], nums[ left ], nums[ right ] } );

                // Find unique left
                while( left < right && nums[ left ] == result.back( )[ 1 ] )
                {
                    ++left;
                }

                // Find unique right
                while( left < right && nums[ right ] == result.back( )[ 2 ] )
                {
                    --right;
                }
                continue;
            }

            if( to_find > sum2 )
            {
                int32_t checked_left = nums[ left ];

                // Find unique left
                while( left < right && nums[ left ] == checked_left )
                {
                    ++left;
                }
            }
            else
            {
                int32_t checked_right = nums[ right ];

                // Find unique right
                while( left < right && nums[ right ] == checked_right )
                {
                    --right;
                }
            }
        }

        int32_t checked_base = nums[ base ];
        // Find unique base
        while( base < BASE_LIMIT && nums[ base ] == checked_base )
        {
            ++base;
        }
    }

    return result;
}

}  // namespace leetcode
