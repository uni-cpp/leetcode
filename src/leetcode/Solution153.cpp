#include <leetcode/Solution153.hpp>

namespace leetcode
{


//    /
//   /
//  /
// /
//
//     /
//    /

int16_t
Solution153::findMin( std::vector< int16_t >& nums )
{
    int16_t left{ 0 };
    int16_t right = nums.size( ) - 1;

    while( left < right )
    {
        if( nums[ left ] < nums[ right ] )
        {
            return nums[ left ];
        }

        int16_t mid = ( left + right ) / 2;
        if( mid == left )
        {
            break;
        }


        if( nums[ mid ] > nums[ left ] )
        {
            left = mid;
            continue;
        }

        right = mid;
    }


    return std::min( nums[ left ], nums[ right ] );
}

}  // namespace leetcode
