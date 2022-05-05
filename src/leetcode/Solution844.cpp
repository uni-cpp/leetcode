#include <leetcode/Solution844.hpp>
namespace leetcode
{

bool
Solution844::backspaceCompare( std::string s, std::string t )
{
    int32_t to_skip{ 0 };

    std::string s_clear;
    for( auto r_it{ s.crbegin( ) }; r_it != s.crend( ); ++r_it )
    {
        if( *r_it == '#' )
        {
            ++to_skip;
            continue;
        }

        if( to_skip > 0 )
        {
            --to_skip;
            continue;
        }

        s_clear += *r_it;
    }

    to_skip = 0;
    std::string t_clear;
    for( auto r_it{ t.crbegin( ) }; r_it != t.crend( ); ++r_it )
    {
        if( *r_it == '#' )
        {
            ++to_skip;
            continue;
        }

        if( to_skip > 0 )
        {
            --to_skip;
            continue;
        }

        t_clear += *r_it;
    }

    return t_clear == s_clear;
}

}  // namespace leetcode
