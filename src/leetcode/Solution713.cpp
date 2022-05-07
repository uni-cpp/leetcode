#include <leetcode/Solution713.hpp>

#include <cstddef>

namespace leetcode
{

uint32_t
Solution713::numSubarrayProductLessThanK( std::vector< uint32_t >& nums, uint32_t k )
{
    uint32_t count{ 0U };

    // Check conditions
    if( nums.empty( ) || k == 0 )
    {
        return count;
    }

    // Logic
    // We should use sliding window
    // If product < k ==> move right and check again
    // If product >= k ==> move left
    // if left == right and product >= k move left and right
    size_t left{ 0 };
    size_t right{ 0 };

    size_t product = nums[ right ];

    while( right < nums.size( ) )
    {
        if( product < k )
        {
            count += ( 1 + right - left );
            ++right;
            if( right < nums.size( ) )
            {
                product *= nums[ right ];
            }
            continue;
        }

        if( right == left )
        {
            product /= nums[ left ];
            ++left;
            ++right;
            product *= nums[ right ];
            continue;
        }

        // product > k and left < right
        product /= nums[ left ];
        ++left;
    }


    // Return
    return count;
}

//
}  // namespace leetcode
