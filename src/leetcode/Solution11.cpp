#include <leetcode/Solution11.hpp>

namespace leetcode
{

int32_t
Solution11::maxArea( std::vector< int32_t >& height )
{
    int32_t max_area{ 0U };

    // Check pre-conditions
    if( height.size( ) < 2 )
    {
        return 0;
    }

    // logic
    int32_t left{ 0U };
    int32_t right = height.size( ) - 1;

    while( left < right )
    {
        max_area = std::max( max_area, ( right - left ) * std::min( height[ left ], height[ right ] ) );

        if( height[ left ] < height[ right ] )
        {
            ++left;
            continue;
        }

        --right;
    }

    // return
    return max_area;
}

}  // namespace leetcode
