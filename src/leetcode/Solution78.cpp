#include <leetcode/Solution78.hpp>

#include <cmath>

namespace leetcode
{

Solution78::Sets
Solution78::subsets( Set& nums )
{
    Sets result;

    if( nums.empty( ) )
    {
        return result;
    }

    const uint32_t SIZE = nums.size( );

    for( uint32_t number{ 0 }; number < pow( 2, SIZE ); ++number )
    {
        Set current;
        uint32_t shift{ 0 };
        uint32_t copy{ number };
        while( copy != 0 )
        {
            if( ( copy & 1U ) == 1U )
            {
                current.emplace_back( nums[ shift ] );
            }
            ++shift;
            copy >>= 1U;
        }

        result.emplace_back( current );
    }

    return result;
}

}  // namespace leetcode
