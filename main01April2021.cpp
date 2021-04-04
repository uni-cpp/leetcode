////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file app/main.cpp
/// @brief Extra calculations of hash sums for data blocks in multiple threads. uni::Thread approach
/// @author Sergey Polyakov <white.irbys@gmail.com>
/// @date 2020-2021
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3693/
//
// Palindrome Linked List
//
// Given the head of a singly linked list, return true if it is a palindrome.
// Example 1:
// Input: head = [1,2,2,1]
// Output: true
// Example 2:
// Input: head = [1,2]
// Output: false
// Constraints:
// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9
// Follow up: Could you do it in O(n) time and O(1) space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    struct ListNode* slow_ptr{ head };
    struct ListNode* fast_ptr{ head };
    struct ListNode* second_half{ nullptr };
    struct ListNode* prev_of_slow_ptr{ head };
    struct ListNode* midnode = nullptr; // To handle odd size list
    bool res = true; // initialize result
 
    if (head != nullptr && head->next != nullptr) {
        /* Get the middle of the list. Move slow_ptr by 1
        and fast_ptrr by 2, slow_ptr will have the middle
        node */
        while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
            fast_ptr = fast_ptr->next->next;
 
            /*We need previous of the slow_ptr for
            linked lists with odd elements */
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        /* fast_ptr would become NULL when there are even elements in list.
        And not NULL for odd elements. We need to skip the middle node
        for odd case and store it somewhere so that we can restore the
        original list*/
        if (fast_ptr != nullptr) {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
 
        // Now reverse the second half and compare it with first half
        second_half = slow_ptr;
        prev_of_slow_ptr->next = nullptr; // nullptr terminate first half
        reverse(&second_half); // Reverse the second half
        res = compareLists(head, second_half); // compare
 
        /* Construct the original list back */
        reverse(&second_half); // Reverse the second half again
 
        // If there was a mid node (odd size case) which
        // was not part of either first half or second half.
        if (midnode != nullptr) {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }

    return res;
    }
    
    /* Function to reverse the linked list Note that this
    function may change the head */
void reverse(ListNode** head_ref)
{
    struct ListNode* prev = nullptr;
    struct ListNode* current = *head_ref;
    struct ListNode* next;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
 
/* Function to check if two input lists have same data*/
bool compareLists(ListNode* head1, ListNode* head2)
{
    struct ListNode* temp1 = head1;
    struct ListNode* temp2 = head2;
 
    while (temp1 && temp2) {
        if (temp1->val == temp2->val) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
 
    /* Both are empty reurn 1*/
    if (temp1 == nullptr && temp2 == nullptr)
        return 1;
 
    /* Will reach here when one is nullptr
    and other is not */
    return 0;
}
};

auto
main( int /*argc*/, char* * /*argv*/ ) -> int
{
    Solution solution;

    {
//        std::cout << std::endl;
//        std::vector< int32_t > A{ 2, 0, 4, 1, 2 };
 //       std::vector< int32_t > B{ 1, 3, 0, 0, 2 };

  //      std::vector< int32_t > EXPECTED{ 2, 0, 2, 1, 4 };
   //     auto real = solution.advantageCount( A, B );
    //    if( EXPECTED != real )
     //   {
      //      std::cout << "ERROR" << std::endl;
       //     std::terminate( );
       // }
       // std::cout << "3 Test case passed" << std::endl;
    }

    return 0;
}
