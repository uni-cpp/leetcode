#include <leetcode/Solution130.hpp>

#include <cstdint>

namespace
{
using Index = uint32_t;

void
bfs( std::vector< std::vector< char > >& board, Index row, Index column )
{
    if( board[ row ][ column ] != 'O' )
    {
        return;
    }

    board[ row ][ column ] = 'V';

    if( row != 0 )
    {
        bfs( board, row - 1, column );
    }

    if( ( row + 1 ) < board.size( ) )
    {
        bfs( board, row + 1, column );
    }

    if( column != 0 )
    {
        bfs( board, row, column - 1 );
    }

    if( ( column + 1 ) < board.front( ).size( ) )
    {
        bfs( board, row, column + 1 );
    }
}

}  // namespace

namespace leetcode
{
void
Solution130::solve( std::vector< std::vector< char > >& board )
{
    // Check pre-conditions
    if( board.size( ) <= 2U || board.front( ).size( ) <= 2U )
    {
        return;
    }

    for( Index row{ 0U }; row < board.size( ); ++row )
    {
        Index step = 1U;
        if( row > 0 && row < ( board.size( ) - 1 ) )
        {
            step = board.front( ).size( ) - 1U;
        }

        for( Index column{ 0U }; column < board.front( ).size( ); column += step )
        {
            bfs( board, row, column );
        }
    }

    for( Index row{ 0U }; row < board.size( ); ++row )
    {
        for( Index column{ 0U }; column < board.front( ).size( ); ++column )
        {
            if( board[ row ][ column ] == 'X' )
            {
                continue;
            }
            else if( board[ row ][ column ] == 'O' )
            {
                board[ row ][ column ] = 'X';
            }
            else
            {
                // == V
                board[ row ][ column ] = 'O';
            }
        }
    }
    return;
}

}  // namespace leetcode
