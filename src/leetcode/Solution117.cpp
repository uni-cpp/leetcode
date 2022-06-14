#include <leetcode/Solution117.hpp>

#include <queue>

namespace leetcode
{
std::unique_ptr< std::vector< Node > >
create_node_list( const std::vector< int32_t >& values )
{
    auto nodes = std::make_unique< std::vector< Node > >( values.size( ) );

    for( size_t i{ 0U }; i < values.size( ); ++i )
    {
        ( *nodes )[ i ].val = values[ i ];

        size_t left = 2 * i + 1U;
        if( left < values.size( ) )
        {
            ( *nodes )[ i ].left = &( nodes->at( left ) );
        }

        size_t right = left + 1U;
        if( right < values.size( ) )
        {
            ( *nodes )[ i ].right = &( nodes->at( right ) );
        }
    }

    return nodes;
}

void
dfs( Node* current, size_t index, std::vector< Node >& nodes )
{
    if( !current )
    {
        return;
    }

    if( index >= nodes.size( ) )
    {
        nodes.resize( index + 1 );
    }
    nodes[ index ] = *current;
    dfs( current->left, 2 * index + 1, nodes );
    dfs( current->right, 2 * index + 2, nodes );
}

std::string
serialize( Node* first_node )
{
    std::string data{ "[" };

    std::vector< Node > nodes;
    dfs( first_node, 0, nodes );

    for( size_t i{ 0U }; i < nodes.size( ); ++i )
    {
        if( nodes[ i ].val == NULLPTR_VALUE )
        {
            data += "null";
        }
        else
        {
            data += std::to_string( nodes[ i ].val );
        }
        data += ",";
    }

    if( data.length( ) > 1U )
    {
        data.pop_back( );
    }

    data += "]";

    return data;
}

std::string
serialize_next_bfs( Node* first_node )
{
    std::string data{ "[" };

    std::vector< Node > nodes;
    dfs( first_node, 0, nodes );

    for( size_t i{ 0U }; i < nodes.size( ); ++i )
    {
        if( nodes[ i ].val == NULLPTR_VALUE )
        {
            continue;
        }

        data += std::to_string( nodes[ i ].val );
        data += ",";

        if( nodes[ i ].next == nullptr )
        {
            data += "null,";
        }
    }


    if( data.length( ) > 1U )
    {
        data.pop_back( );
    }

    data += "]";
    return data;
}

// 0           0
// 1      1          2
// 2    3   4     5     6
// 3   7 8 9 10 11 12 13 14
// ...

Node*
Solution117::connect( Node* root )
{
    if( !root )
    {
        return root;
    }

    std::queue< Node* > queue;
    queue.push( root );

    while( !queue.empty( ) )
    {
        const size_t current_level_size = queue.size( );
        const size_t max_index = current_level_size - 1U;
        ;
        for( size_t i{ 0U }; i < current_level_size; ++i )
        {
            auto* current = queue.front( );
            queue.pop( );

            if( current->left )
            {
                queue.push( current->left );
            }

            if( current->right )
            {
                queue.push( current->right );
            }

            if( i != max_index )
            {
                current->next = queue.front( );
            }
        }
    }

    return root;
}

}  // namespace leetcode
