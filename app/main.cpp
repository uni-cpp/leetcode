#include <leetcode/Solution153.hpp>

#include <iostream>

auto
main( int /*argc*/, char** /*argv*/ ) -> int
{
    {
        leetcode::Solution153 solution;
        std::vector< int16_t > in1{ 3, 4, 5, 1, 2 };
        if( solution.findMin( in1 ) != 1 )
        {
            std::cerr << "Example 1 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution153 solution;
        std::vector< int16_t > in2{ 4, 5, 6, 7, 0, 1, 2 };
        if( solution.findMin( in2 ) != 0 )
        {
            std::cerr << "Example 2 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution153 solution;
        std::vector< int16_t > in3{ 11, 13, 15, 17 };
        if( solution.findMin( in3 ) != 11 )
        {
            std::cerr << "Example 3 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution153 solution;
        std::vector< int16_t > in3{ 14 };
        if( solution.findMin( in3 ) != 14 )
        {
            std::cerr << "Example 4 not passed" << std::endl;
        }
    }

    return 0;
}
