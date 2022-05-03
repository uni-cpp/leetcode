// -3 0 3 - simple var
//  |       (-3;0)       total_count == 0
//    |     (-3;1)       total_count == 1 (because current_index == 0)
//      |   (-3;1) (0;1) total_count == 2 (because current_sum == 0)
// -3;0;3 and 0 - is the answer TOTAL 2
// Used partial_sums and create hash map Partial_Sum <-> count of entrance

// 2, -2, 3, 0, 4, -7
// |                   (2;0)                         Sum == 2    Count += 0
//     |               (0;1) (2;0)                   Sum == 0    Count += 1 // Cause sum == 0
//        |            (0;1) (2;0)   (3;2)           Sum == 3    Count += 0
//           |         (0;1) (2;0)   (3;2,3)         Sum == 3    Count += 1 // Cause (3;2) existed before this step
//              |      (7;4) (0;1)   (2;0) (3;2,3)   Sum == 7    Count += 0
//                  |  (7;4) (0;1,5) (2;0) (3;2,3)   Sum == 7    Count += 2 // Cause Sum==0 and (0;1) existed before

#include <iostream>
#include <unordered_map>
#include <vector>

int
solution( std::vector< int >& A )
{
    constexpr int LIMIT{ 1000000000 };
    using sum = int;
    using count = int;
    std::unordered_map< sum, count > partials_sums;

    int current_sum{ 0 };
    int total_count{ 0 };

    for( size_t i{ 0 }; i < A.size( ); ++i )
    {
        current_sum += A[ i ];

        if( 0 == current_sum )
        {
            ++total_count;
            if( total_count > LIMIT )
            {
                return -1;
            }
        }

        if( partials_sums.find( current_sum ) != partials_sums.cend( ) )
        {
            total_count += partials_sums[ current_sum ];
            if( total_count > LIMIT )
            {
                return -1;
            }
        }

        ++partials_sums[ current_sum ];
    }

    return total_count;
}

int
main( )
{
    std::vector< int > data1 = { -3, 0, 3 };
    std::cout << solution( data1 ) << std::endl;

    std::vector< int > data2 = { 2, -2, 3, 0, 4, -7 };
    std::cout << solution( data2 ) << std::endl;

    return 0;
}
