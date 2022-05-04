#include <leetcode/Solution82.hpp>

namespace leetcode
{

// 1, 2, 3, 3, 4, 4, 5
//
//  1, 2, 2
ListNode*
Solution82::deleteDuplicates( ListNode* head )
{
    if( !head )
    {
        return nullptr;
    }

    auto pre_head = new ListNode{ -101, nullptr };
    int32_t should_be_skipped = -101;
    auto tail = pre_head;

    while( head )
    {
        if( head->val == should_be_skipped )
        {
            head = head->next;
            continue;
        }

        if( head->next && head->val == head->next->val )
        {
            should_be_skipped = head->val;
            head = head->next->next;
            continue;
        }

        tail->next = head;
        tail = head;
        head = head->next;
        tail->next = nullptr;
    }

    return pre_head->next;
}

ListNode*
create_linked_list( const std::vector< int32_t >& values )
{
    ListNode* prev{ nullptr };

    for( auto value_it{ values.crbegin( ) }; value_it != values.crend( ); ++value_it )
    {
        prev = new ListNode{ *value_it, prev };
    }

    return prev;
}

std::string
serialize( ListNode* first_node )
{
    std::string data{ "[" };

    while( first_node )
    {
        data += std::to_string( first_node->val );
        data += ",";
        first_node = first_node->next;
    }

    if( data.length( ) > 1 )
    {
        data.pop_back( );
    }

    data += "]";

    return data;
}

}  // namespace leetcode
