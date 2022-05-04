#include <leetcode/Solution162.hpp>

namespace leetcode
{

//   /
//  /
// /

// \
//  \
//   \

//
//     /\
//    /  \
//   /    \
//  /      \
// /

// if (num[i] > num[i+1]) => return num[i]


// 3-2-3                    0||2
// 6, 5, 4, 3, 2, 3, 2      0||5

int32_t
leetcode::Solution162::findPeakElement( std::vector< int32_t >& nums )
{
    if( nums.size( ) < 2 )
    {
        return 0;
    }

    int32_t left = 0;
    int32_t right = nums.size( ) - 1;

    while( left < right )
    {
        int32_t mid = ( left + right ) / 2;


        if( nums[ mid ] > nums[ mid + 1 ] )
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

}  // namespace leetcode
