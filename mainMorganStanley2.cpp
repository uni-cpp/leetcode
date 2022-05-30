#include <cstddef>
#include <string>

// 001 == 1
// 000 == 0
// 110 == 6

size_t
count_bits( unsigned number )
{
    size_t count{ 0U };

    while( number > 0 )
    {
        if( ( number & 0x1 ) == 1U )
        {
            ++count;
        }
        number = ( number >> 1U );
    }

    return count;
}


// 2 strings A and B (0 or 1)
//
// A     010101011
// B 1000110000001
// C 1001000101100

std::string
add( const std::string& A, const std::string& B )
{
    if( A.empty( ) )
    {
        return B;
    }

    if( B.empty( ) )
    {
        return A;
    }

    // lets assume A <=B, in other case swap them

    std::string C;
    C.resize( B.size( ) );  // Probably added 1 more to front

    const auto A_MAX_INDEX = A.size( ) - 1;
    const auto B_MAX_INDEX = B.size( ) - 1;

    bool is_increased{ false };

    for( int32_t i = 0; i < A.size( ); ++i )
    {
        if( ( A[ A_MAX_INDEX - i ] == '1' && B[ B_MAX_INDEX - i ] == '1' ) || ( is_increased && ( A[ A_MAX_INDEX - i ] == '1' || B[ B_MAX_INDEX - i ] == '1' ) ) )
        {
            is_increased = true;
        }
        else
        {
            is_increased = false;
        }
    }


    return { };
}


class MyString
{
    // Ctor
    // Dtor
    // CopyCtor

    // Operator=

    MyString&
    operator=( const MyString& right )
    {
        if( this == &right )
        {
            return *this;
        }

        len = right.len;

        auto copy( right );
        std::swap( *this, copy );

        return *this;
    }

private:
    char* S;
    int len;
};
