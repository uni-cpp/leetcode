#include <leetcode/Solution153.hpp>
#include <leetcode/Solution162.hpp>

#include <iostream>

auto
main( int /*argc*/, char** /*argv*/ ) -> int
{
    {
        leetcode::Solution153 solution;
        std::vector< int16_t > in1{ 3, 4, 5, 1, 2 };
        if( solution.findMin( in1 ) != 1 )
        {
            std::cerr << "Example 153-1 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution153 solution;
        std::vector< int16_t > in2{ 4, 5, 6, 7, 0, 1, 2 };
        if( solution.findMin( in2 ) != 0 )
        {
            std::cerr << "Example 153-2 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution153 solution;
        std::vector< int16_t > in3{ 11, 13, 15, 17 };
        if( solution.findMin( in3 ) != 11 )
        {
            std::cerr << "Example 153-3 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution153 solution;
        std::vector< int16_t > in4{ 11 };
        if( solution.findMin( in4 ) != 11 )
        {
            std::cerr << "Example 153-4 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution162 solution;
        std::vector< int32_t > in1{ 1, 2, 3, 1 };
        if( solution.findPeakElement( in1 ) != 2 )
        {
            std::cerr << "Example 162-1 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution162 solution;
        std::vector< int32_t > in2{ 1, 2, 1, 3, 5, 6, 4 };
        if( solution.findPeakElement( in2 ) != 1 && solution.findPeakElement( in2 ) != 5 )
        {
            std::cerr << "Example 162-2 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution162 solution;
        std::vector< int32_t > in3{ 1, 2, 3 };
        if( solution.findPeakElement( in3 ) != 2 )
        {
            std::cerr << "Example 162-3 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution162 solution;
        std::vector< int32_t > in4{ 3, 2, 3 };
        if( solution.findPeakElement( in4 ) != 0 && solution.findPeakElement( in4 ) != 2 )
        {
            std::cerr << "Example 162-4 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution162 solution;
        std::vector< int32_t > in5{ 6, 5, 4, 3, 2, 3, 2 };
        if( solution.findPeakElement( in5 ) != 0 && solution.findPeakElement( in5 ) != 5 )
        {
            std::cerr << "Example 162-5 not passed" << std::endl;
        }
    }

    return 0;
}
