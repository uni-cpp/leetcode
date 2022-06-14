// 572. Subtree of Another Tree

// Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot
// and false otherwise. A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants.
// The tree tree could also be considered as a subtree of itself.

// Example 1:
//  Input: root = [3,4,5,1,2], subRoot = [4,1,2]
//  Output: true

// Example 2:
//  Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
//  Output: false

// Constraints:
//  The number of nodes in the root tree is in the range [1, 2000].
//  The number of nodes in the subRoot tree is in the range [1, 1000].
//  -104 <= root.val <= 104
//  -104 <= subRoot.val <= 104

#pragma once

#include <cstdint>
#include <memory>
#include <numeric>
#include <vector>

namespace leetcode
{

// See NULLPTR_VALUE
constexpr int32_t NULL_VALUE = std::numeric_limits< int32_t >::max( );
// Definition for a binary tree node.
struct TreeNode
{
    int32_t val{ NULL_VALUE };
    TreeNode* left{ nullptr };
    TreeNode* right{ nullptr };
};

class Solution572
{
public:
    bool isSubtree( TreeNode* root, TreeNode* subRoot );
};

// Some nodes can be empty
std::unique_ptr< std::vector< TreeNode > > create_tree( const std::vector< int32_t >& values );

}  // namespace leetcode
