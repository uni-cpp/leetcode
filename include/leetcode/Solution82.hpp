// 82. Remove Duplicates from Sorted List II

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// Return the linked list sorted as well.

// Example 1:
//  Input: head = [1,2,3,3,4,4,5]
//  Output: [1,2,5]

// Example 2:
//  Input: head = [1,1,1,2,3]
//  Output: [2,3]


// Constraints:
// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

#pragma once

#include <memory>
#include <vector>

namespace leetcode
{


// Definition for singly-linked list.
struct ListNode
{
    int32_t val{ 0 };
    ListNode* next{ nullptr };
};

ListNode* create_linked_list( const std::vector< int32_t >& values );

std::string serialize( ListNode* first_node );

class Solution82
{
public:
    ListNode* deleteDuplicates( ListNode* head );
};

}  // namespace leetcode
