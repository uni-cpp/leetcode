#include <leetcode/Solution209.hpp>

#include <algorithm>

namespace leetcode
{
uint32_t
Solution209::minSubArrayLen( uint32_t target, std::vector< uint32_t >& nums )
{
    // Check conditions
    if( nums.empty( ) )
    {
        return 0;
    }

    // Logic
    // Sliding windows
    // store min_len and calculate current_length and current_sum
    // if current_sum >= target ==> save len and move left                                    +
    // if current_sum < target ==> move right + check border + calculate new sum/return
    // if left == right and current_sum => target ==>return 1;                                +

    size_t min_subarray_length{ std::numeric_limits< size_t >::max( ) };

    size_t left{ 0U };
    size_t right{ 0U };
    size_t sum{ nums[ right ] };

    while( right < nums.size( ) )
    {
        if( sum >= target )
        {
            min_subarray_length = std::min( min_subarray_length, 1 + right - left );
            if( min_subarray_length == 1 )
            {
                break;
            }
            sum -= nums[ left ];
            ++left;
            continue;
        }

        ++right;
        if( right == nums.size( ) )
        {
            break;
        }
        sum += nums[ right ];
    }

    // Return
    return min_subarray_length == std::numeric_limits< size_t >::max( ) ? 0U : min_subarray_length;
}
}  // namespace leetcode
