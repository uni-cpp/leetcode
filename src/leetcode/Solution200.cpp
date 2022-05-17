#include <leetcode/Solution200.hpp>

#include <cstddef>

namespace leetcode
{

uint32_t
leetcode::Solution200::numIslands( std::vector< std::vector< char > >& grid )
{
    uint32_t count{ 0U };

    if( grid.empty( ) || grid.front( ).empty( ) )
    {
        return count;
    }


    m_rows = grid.size( );
    m_columns = grid.front( ).size( );

    std::vector< bool > is_visited_default_row( m_columns, false );
    m_is_visited = std::vector< std::vector< bool > >( m_rows, is_visited_default_row );


    for( size_t i{ 0U }; i < m_rows; ++i )
    {
        for( size_t j{ 0U }; j < m_columns; ++j )
        {
            if( m_is_visited[ i ][ j ] || grid[ i ][ j ] == '0' )
            {
                continue;
            }

            dfs( grid, i, j );
            ++count;
        }
    }

    return count;
}

void
Solution200::dfs( std::vector< std::vector< char > >& grid, uint32_t row, uint32_t column )
{
    if( m_is_visited[ row ][ column ] || grid[ row ][ column ] == '0' )
    {
        return;
    }

    m_is_visited[ row ][ column ] = true;

    if( row != 0 )
    {
        dfs( grid, row - 1, column );
    }

    if( ( row + 1 ) != grid.size( ) )
    {
        dfs( grid, row + 1, column );
    }

    if( column != 0 )
    {
        dfs( grid, row, column - 1 );
    }
    if( ( column + 1 ) != grid.front( ).size( ) )
    {
        dfs( grid, row, column + 1 );
    }
}


}  // namespace leetcode
