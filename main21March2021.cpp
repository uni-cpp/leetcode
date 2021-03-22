////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file app/main.cpp
/// @brief Extra calculations of hash sums for data blocks in multiple threads. uni::Thread approach
/// @author Sergey Polyakov <white.irbys@gmail.com>
/// @date 2020-2021
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <set>
#include <vector>

// https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/590/week-3-march-15th-march-21st/3679/

// Starting with a positive integer N, we rStarting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not
// zero.
// Return true if and only if we can do this in a way such that the resulting number is a power of 2.
// Note:
//    1 <= N <= 10^9


auto
main( int /*argc*/, char* * /*argv*/ ) -> int
{
    class Solution
    {
        using Digit = int8_t;
        using Digits = std::vector< Digit >;

    public:
        Solution( )
        {
            // Multimap with length number and vector of the all digit counter.
            // Total size < 32
            // Could be static for performance optimization
            // Number <==> Length, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] - DIGITS
            // 1      <==> 1,      [0, 1, 0, 0, 0, 0, 0, 0, 0, 0]
            // 2      <==> 1,      [0, 0, 1, 0, 0, 0, 0, 0, 0, 0]
            // 4      <==> 1,      [0, 0, 0, 0, 1, 0, 0, 0, 0, 0]
            // 8      <==> 1,      [0, 0, 0, 0, 0, 0, 0, 0, 1, 0]
            // 16     <==> 2,      [0, 1, 0, 0, 0, 0, 1, 0, 0, 0]
            // 32     <==> 2,      [0, 0, 1, 1, 0, 0, 1, 0, 0, 0]
            // 64 ...
            for( int32_t i = 1U; i <= 1000000000; i *= 2 )
            {
                m_set.emplace( parse_number_to_digits( i ) );
            }
        }

        bool
        reorderedPowerOf2( int N )
        {
            const auto digits_for_n = parse_number_to_digits( N );

            for( auto& data : m_set )
            {
                if( data == digits_for_n )
                {
                    return true;
                }
            }

            return false;
        }

    private:
        Digits
        parse_number_to_digits( int N )
        {
            Digits digits( 10, 0 );
            for( auto x = N; x > 0; x /= 10U )
            {
                ++( digits[ x % 10 ] );
            }

            return digits;
        }

    private:
        std::set< Digits > m_set{ };
    };

    Solution solution;

    std::cout << solution.reorderedPowerOf2( 536870912 ) << std::endl;
    std::cout << solution.reorderedPowerOf2( 236870915 ) << std::endl;
    std::cout << solution.reorderedPowerOf2( 536870921 ) << std::endl;
    std::cout << solution.reorderedPowerOf2( 536870911 ) << std::endl;

    return 0;
}
