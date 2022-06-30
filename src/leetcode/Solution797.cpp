#include <leetcode/Solution797.hpp>

namespace
{
void
backtracking( const leetcode::Solution797::GraphNodes& graph, leetcode::Solution797::Path& current_path, leetcode::Solution797::Paths& result )
{
    if( current_path.back( ) == ( graph.size( ) - 1 ) )
    {
        result.emplace_back( current_path );
        return;
    }

    for( auto next_node : graph.at( current_path.back( ) ) )
    {
        current_path.emplace_back( next_node );
        backtracking( graph, current_path, result );
        current_path.pop_back( );
    }
}
}  // namespace

namespace leetcode
{
Solution797::Paths
Solution797::allPathsSourceTarget( const GraphNodes& graph )
{
    // Check preconditions
    if( graph.size( ) <= 1U )
    {
        return graph;
    }


    Paths result;
    Path current_path;
    current_path.emplace_back( 0 );

    backtracking( graph, current_path, result );

    return result;
}

}  // namespace leetcode
