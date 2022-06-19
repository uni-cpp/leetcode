#include <leetcode/Solution146.hpp>

namespace leetcode
{

Solution146::Solution146( Capacity capacity )
    : m_capacity{ capacity }
{
    m_hash.reserve( m_capacity );
}

Solution146::Value
Solution146::get( Solution146::Key key )
{
    const auto it = m_hash.find( key );

    if( it == m_hash.end( ) )
    {
        return -1;
    }

    // Move data to front
    m_data.emplace_front( *( it->second ) );
    // Erase prev
    m_data.erase( it->second );
    // Update hash
    it->second = m_data.begin( );

    // it->second is iterator to pair <Key, Value>
    return it->second->second;
}

void
Solution146::put( Solution146::Key key, Solution146::Value value )
{
    auto it = m_hash.find( key );

    if( it != m_hash.end( ) )
    {
        // Move data to front
        m_data.emplace_front( *( it->second ) );
        // Erase prev
        m_data.erase( it->second );

        m_data.front( ).second = value;
        it->second = m_data.begin( );
        return;
    }

    // Remove oldest
    if( m_hash.size( ) >= m_capacity )
    {
        auto to_remove = m_hash.find( m_data.back( ).first );
        m_hash.erase( to_remove );

        m_data.erase( std::prev( m_data.end( ) ) );
    }

    m_data.emplace_front( key, value );
    m_hash[ key ] = m_data.begin( );
}

}  // namespace leetcode
