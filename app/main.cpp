#include <leetcode/Solution11.hpp>
#include <leetcode/Solution15.hpp>
#include <leetcode/Solution153.hpp>
#include <leetcode/Solution162.hpp>
#include <leetcode/Solution209.hpp>
#include <leetcode/Solution438.hpp>
#include <leetcode/Solution713.hpp>
#include <leetcode/Solution82.hpp>
#include <leetcode/Solution844.hpp>
#include <leetcode/Solution986.hpp>

#include <iostream>

auto
main( int /*argc*/, char** /*argv*/ ) -> int
{
    {
        leetcode::Solution11 solution;

        std::vector< int32_t > in1{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        const auto actual = solution.maxArea( in1 );
        const int32_t expected = 49;

        if( actual != expected )
        {
            std::cerr << "Example 11-1 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution11 solution;

        std::vector< int32_t > in1{ 1, 1 };
        const auto actual = solution.maxArea( in1 );
        const int32_t expected = 1;

        if( actual != expected )
        {
            std::cerr << "Example 11-2 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution15 solution;

        std::vector< int32_t > in1{ -1, 0, 1, 2, -1, -4 };
        const auto actual = solution.threeSum( in1 );
        const std::vector< std::vector< int32_t > > expected = { { -1, -1, 2 }, { -1, 0, 1 } };

        if( actual != expected )
        {
            std::cerr << "Example 15-1 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution15 solution;

        std::vector< int32_t > in2{ };
        const auto actual = solution.threeSum( in2 );
        const std::vector< std::vector< int32_t > > expected = { };

        if( actual != expected )
        {
            std::cerr << "Example 15-2 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution15 solution;

        std::vector< int32_t > in3{ 0 };
        const auto actual = solution.threeSum( in3 );
        const std::vector< std::vector< int32_t > > expected = { };

        if( actual != expected )
        {
            std::cerr << "Example 15-3 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution82 solution;
        auto* in1 = leetcode::create_linked_list( { 1, 2, 3, 3, 4, 4, 5 } );

        constexpr auto expected = "[1,2,5]";
        const auto actual = leetcode::serialize( solution.deleteDuplicates( in1 ) );

        if( actual != expected )
        {
            std::cerr << "Example 82-1 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution82 solution;
        auto* in2 = leetcode::create_linked_list( { 1, 1, 1, 2, 3 } );

        if( leetcode::serialize( solution.deleteDuplicates( in2 ) ) != "[2,3]" )
        {
            std::cerr << "Example 82-2 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution82 solution;
        auto* in3 = leetcode::create_linked_list( { 1, 1, 1 } );

        if( leetcode::serialize( solution.deleteDuplicates( in3 ) ) != "[]" )
        {
            std::cerr << "Example 82-3 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution82 solution;
        auto* in4 = leetcode::create_linked_list( { 1, 1, 2, 2 } );

        if( leetcode::serialize( solution.deleteDuplicates( in4 ) ) != "[]" )
        {
            std::cerr << "Example 82-4 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution82 solution;
        auto* in5 = leetcode::create_linked_list( { } );

        if( leetcode::serialize( solution.deleteDuplicates( in5 ) ) != "[]" )
        {
            std::cerr << "Example 82-5 not passed" << std::endl;
        }
    }

    {
        leetcode::Solution82 solution;
        auto* in1 = leetcode::create_linked_list( { 1, 2, 2 } );

        constexpr auto expected = "[1]";
        const auto actual = leetcode::serialize( solution.deleteDuplicates( in1 ) );

        if( actual != expected )
        {
            std::cerr << "Example 82-6 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

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

    {
        leetcode::Solution209 solution;
        const uint32_t expected = 2;
        std::vector< uint32_t > in1{ 2, 3, 1, 2, 4, 3 };
        const auto actual = solution.minSubArrayLen( 7, in1 );

        if( actual != expected )
        {
            std::cerr << "Example 209-1 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution209 solution;
        const uint32_t expected = 1;
        std::vector< uint32_t > in1{ 1, 4, 4 };
        const auto actual = solution.minSubArrayLen( 4, in1 );

        if( actual != expected )
        {
            std::cerr << "Example 209-2 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution209 solution;
        const uint32_t expected = 0;
        std::vector< uint32_t > in1{ 1, 1, 1, 1, 1, 1, 1, 1 };
        const auto actual = solution.minSubArrayLen( 11, in1 );

        if( actual != expected )
        {
            std::cerr << "Example 209-3 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution209 solution;
        const uint32_t expected = 5;
        std::vector< uint32_t > in1{ 1, 2, 3, 4, 5 };
        const auto actual = solution.minSubArrayLen( 15, in1 );

        if( actual != expected )
        {
            std::cerr << "Example 209-4 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution438 solution;
        const std::vector< int32_t > expected{ 0, 6 };
        const auto actual = solution.findAnagrams( "cbaebabacd", "abc" );

        if( actual != expected )
        {
            std::cerr << "Example 438-1 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution438 solution;
        const std::vector< int32_t > expected{ 0, 1, 2 };
        const auto actual = solution.findAnagrams( "abab", "ab" );

        if( actual != expected )
        {
            std::cerr << "Example 438-2 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution438 solution;
        const std::vector< int32_t > expected{ 1 };
        const auto actual = solution.findAnagrams( "baa", "aa" );

        if( actual != expected )
        {
            std::cerr << "Example 438-3 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution713 solution;
        constexpr uint32_t expected{ 8 };
        std::vector< uint32_t > in1{ 10, 5, 2, 6 };
        const auto actual = solution.numSubarrayProductLessThanK( in1, 100 );

        if( actual != expected )
        {
            std::cerr << "Example 713-1 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution713 solution;
        constexpr uint32_t expected{ 0 };
        std::vector< uint32_t > in1{ 1, 2, 3 };
        const auto actual = solution.numSubarrayProductLessThanK( in1, 0 );

        if( actual != expected )
        {
            std::cerr << "Example 713-2 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution844 solution;

        const auto actual = solution.backspaceCompare( "ab#c", "ad#c" );
        const bool expected = true;

        if( actual != expected )
        {
            std::cerr << "Example 844-1 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution844 solution;

        const auto actual = solution.backspaceCompare( "ab##", "c#d#" );
        const bool expected = true;

        if( actual != expected )
        {
            std::cerr << "Example 844-2 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution844 solution;

        const auto actual = solution.backspaceCompare( "a#c", "b" );
        const bool expected = false;

        if( actual != expected )
        {
            std::cerr << "Example 844-3 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution986 solution;

        std::vector< std::vector< int32_t > > vec1{ { 0, 2 }, { 5, 10 }, { 13, 23 }, { 24, 25 } };
        std::vector< std::vector< int32_t > > vec2{ { 1, 5 }, { 8, 12 }, { 15, 24 }, { 25, 26 } };
        const auto actual = solution.intervalIntersection( vec1, vec2 );
        const std::vector< std::vector< int32_t > > expected = { { 1, 2 }, { 5, 5 }, { 8, 10 }, { 15, 23 }, { 24, 24 }, { 25, 25 } };

        if( actual != expected )
        {
            std::cerr << "Example 986-1 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    {
        leetcode::Solution986 solution;

        std::vector< std::vector< int32_t > > vec1{ { 0, 2 }, { 5, 10 }, { 13, 23 }, { 24, 25 } };
        std::vector< std::vector< int32_t > > vec2{ };
        const auto actual = solution.intervalIntersection( vec1, vec2 );
        const std::vector< std::vector< int32_t > > expected = { };

        if( actual != expected )
        {
            std::cerr << "Example 986-2 not passed." << std::endl;
            std::cerr << "Actual " << actual << std::endl;
            std::cerr << "Expected: " << expected << std::endl;
        }
    }

    return 0;
}
