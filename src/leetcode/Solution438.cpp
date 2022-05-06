#include <leetcode/Solution438.hpp>

#include <algorithm>
#include <array>

namespace leetcode
{
std::vector< int32_t >
Solution438::findAnagrams( std::string s, std::string p )
{
    std::vector< int32_t > result;

    // Check pre-reqs
    if( s.empty( ) || p.empty( ) || s.size( ) < p.size( ) )
    {
        return result;
    }

    // Logic
    // Create and fill hash-vector based on p
    // iterate through s using slide window and count chars.
    // In case of all values in vector == 0, then bingo and save offset.

    constexpr uint8_t SIZE{ 'z' - 'a' + 1U };
    std::array< int32_t, SIZE > counts;
    counts.fill( 0 );

    for( const auto ch : p )
    {
        ++counts[ ch - 'a' ];
    }

    uint32_t right{ 0 };
    for( ; right < p.size( ); ++right )
    {
        --counts[ s[ right ] - 'a' ];
    }

    --right;
    uint32_t left{ 0 };

    do
    {
        if( std::all_of( counts.cbegin( ), counts.cend( ), []( const auto val ) { return val == 0; } ) )
        {
            result.push_back( left );
        }

        ++counts[ s[ left ] - 'a' ];
        ++left;
        ++right;
        if( right < s.size( ) )
        {
            --counts[ s[ right ] - 'a' ];
        }
    } while( right < s.size( ) );

    // Return
    return result;
}

}  // namespace leetcode
