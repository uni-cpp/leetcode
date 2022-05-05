#include <leetcode/Solution986.hpp>

#include <utility>

namespace leetcode
{

// ..[|||]...
// []...[|||]
// firstList = [[0,2],[5,10],[13,23],[24,25]],
// secondList = [[1,5],[8,12],[15,24],[25,26]]
// result [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

// Logic
// Always compare 2 intervals (TOP is the smallest start)
// 6 situations:
// [..]      |  [.......]  |  [.......]
//      [..] |   [....]    |     [      ]

//      [..] |   [....]    |     [      ]
// [..]      |  [.......]  |  [.......]


// firstList = [[0,2]],
// secondList = [[1,5]]
// result [[1,2]]

std::vector< std::vector< int32_t > >
Solution986::intervalIntersection( std::vector< std::vector< int32_t > >& firstList, std::vector< std::vector< int32_t > >& secondList )
{
    if( secondList.empty( ) || firstList.empty( ) )
    {
        return { };
    }

    uint32_t index_1{ 0U };
    uint32_t index_2{ 0U };
    constexpr uint8_t START{ 0U };
    constexpr uint8_t END{ 1U };

    std::vector< std::vector< int32_t > > intersections;

    while( index_1 < firstList.size( ) && index_2 < secondList.size( ) )
    {
        const auto& first_pair{ firstList[ index_1 ] };
        const auto& second_pair{ secondList[ index_2 ] };

        if( first_pair[ END ] < second_pair[ START ] )
        {
            ++index_1;
            continue;
        }

        if( second_pair[ END ] < first_pair[ START ] )
        {
            ++index_2;
            continue;
        }

        if( first_pair[ START ] < second_pair[ START ] && first_pair[ END ] >= second_pair[ END ] )
        {
            intersections.push_back( { second_pair[ START ], second_pair[ END ] } );
            ++index_2;
            continue;
        }

        if( second_pair[ START ] < first_pair[ START ] && second_pair[ END ] >= first_pair[ END ] )
        {
            intersections.push_back( { first_pair[ START ], first_pair[ END ] } );
            ++index_1;
            continue;
        }

        if( first_pair[ START ] <= second_pair[ START ] && first_pair[ END ] <= second_pair[ END ] )
        {
            intersections.push_back( { second_pair[ START ], first_pair[ END ] } );
            ++index_1;
            continue;
        }

        if( second_pair[ START ] <= first_pair[ START ] && second_pair[ END ] <= first_pair[ END ] )
        {
            intersections.push_back( { first_pair[ START ], second_pair[ END ] } );
            ++index_2;
            continue;
        }

        // Should not happened. Check it?
    }


    return intersections;
}

}  // namespace leetcode
