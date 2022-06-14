#include <leetcode/Solution572.hpp>

namespace leetcode
{

bool
isEqual( TreeNode* root, TreeNode* subRoot )
{
    if( !root && !subRoot )
    {
        return true;
    }
    else if( !root || !subRoot )
    {
        return false;
    }

    if( root->val != subRoot->val )
    {
        return false;
    }

    return isEqual( root->left, subRoot->left ) && isEqual( root->right, subRoot->right );
}

bool
Solution572::isSubtree( TreeNode* root, TreeNode* subRoot )
{
    if( !subRoot )
    {
        return true;
    }

    if( !root )
    {
        return false;
    }

    if( isEqual( root, subRoot ) )
    {
        return true;
    }

    return isSubtree( root->left, subRoot ) || isSubtree( root->right, subRoot );
}

std::unique_ptr< std::vector< TreeNode > >
create_tree( const std::vector< int32_t >& values )
{
    auto nodes = std::make_unique< std::vector< TreeNode > >( values.size( ) );

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

    // TODO Remove pointers to NULL_VALUE
    // TODO Fix in case of missed last NULL_VALUES

    return nodes;
}

}  // namespace leetcode
