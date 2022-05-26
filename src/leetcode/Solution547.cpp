#include <leetcode/Solution547.hpp>

#include <algorithm>

namespace leetcode
{

DisjointSet::DisjointSet( size_t n )
    : m_groups{ n }
{
    m_parents.reserve( n );
    for( size_t i{ 0U }; i < n; ++i )
    {
        m_parents.emplace_back( i );
    }

    m_ranks.resize( n, 0U );
}

void
DisjointSet::unite( size_t element1, size_t element2 )
{
    if( element1 == element2 )
    {
        return;
    }

    auto element1_parent{ find( element1 ) };
    auto element2_parent{ find( element2 ) };

    if( element1_parent == element2_parent )
    {
        return;
    }

    // if( m_ranks[] )
    m_parents[ element1_parent ] = element2_parent;
    --m_groups;
}

size_t
DisjointSet::find( size_t element )
{
    // Return if i >= m_parent.size();

    if( m_parents[ element ] == element )
    {
        return element;
    }

    std::vector< size_t > to_update_parents{ element };

    size_t result{ m_parents[ element ] };
    while( m_parents[ result ] != result )
    {
        // Profit in case of modification -> search. Otherwise, too expensive and not useful
        to_update_parents.emplace_back( result );
        result = m_parents[ result ];
    }

    // Cut the tree
    for( auto node : to_update_parents )
    {
        m_parents[ node ] = result;
    }


    return result;
}

size_t
DisjointSet::count( ) const
{
    return m_groups;
}

uint32_t
Solution547::findCircleNum( const std::vector< std::vector< uint8_t > >& isConnected )
{
    if( isConnected.size( ) < 2U )
    {
        return 1;
    }

    DisjointSet d_set( isConnected.size( ) );

    for( size_t i{ 0U }; i < isConnected.size( ); ++i )
    {
        for( size_t j{ 0U }; j < i; ++j )
        {
            if( isConnected[ i ][ j ] == 1 )
            {
                d_set.unite( i, j );
            }
        }
    }


    return d_set.count( );
}


}  // namespace leetcode
