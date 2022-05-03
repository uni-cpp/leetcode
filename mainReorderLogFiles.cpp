#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

class Solution
{
public:
    std::vector< std::string >
    reorderLogFiles( std::vector< std::string >& logs )
    {
        auto MyComparator = []( const std::string& log1, const std::string& log2 )
        {
            const auto& idValue1 = parseIdValue( log1 );
            const auto& idValue2 = parseIdValue( log2 );

            if( idValue1.second == idValue2.second )
            {
                return idValue1.first < idValue2.first;
            }

            return idValue1.second < idValue2.second;
        };

        std::multiset< std::string, decltype( MyComparator ) > sortedLetterLogs( MyComparator );
        std::vector< std::string > orderedDigitLogs;

        for( const auto& log : logs )
        {
            const auto& idValue = parseIdValue( log );

            if( isDigitLog( idValue.second ) )
            {
                orderedDigitLogs.emplace_back( log );
            }
            else
            {
                sortedLetterLogs.insert( log );
            }
        }

        std::vector< std::string > result;
        result.reserve( logs.size( ) );

        std::copy( sortedLetterLogs.begin( ), sortedLetterLogs.end( ), std::back_inserter( result ) );
        std::copy( orderedDigitLogs.begin( ), orderedDigitLogs.end( ), std::back_inserter( result ) );

        return result;
    }

private:
    std::pair< std::string, std::string > static parseIdValue( const std::string& log )
    {
        auto space = log.find( ' ' );
        if( space == 0 || space == log.length( ) )
        {
            // Log error
            return { "", "" };
        }

        std::string id = log.substr( 0, space - 1 );
        std::string value = log.substr( space );
        return { id, value };
    }

    bool static isDigitLog( const std::string& value )
    {
        auto isSpaceOrDigit = []( auto ch ) { return ( ch == ' ' ) || std::isdigit( ch ); };
        return std::all_of( value.cbegin( ), value.cend( ), isSpaceOrDigit );
    }
};

auto
main( int /*argc*/, char** /*argv*/ ) -> int
{
    Solution solution;

    {
        std::vector< std::string > logs;
        logs.emplace_back( "dig1 8 1 5 1" );
        logs.emplace_back( "let1 art can" );
        logs.emplace_back( "dig2 3 6" );
        logs.emplace_back( "let2 own kit dig" );
        logs.emplace_back( "let3 art zero" );

        auto answer = solution.reorderLogFiles( logs );

        for( const auto& log : answer )
        {
            std::cout << log << std::endl;
        }
        std::cout << std::endl;
    }

    {
        std::vector< std::string > logs;
        logs.emplace_back( "a1 9 2 3 1" );
        logs.emplace_back( "g1 act car" );
        logs.emplace_back( "zo4 4 7" );
        logs.emplace_back( "ab1 off key dog" );
        logs.emplace_back( "a8 act zoo" );

        auto answer = solution.reorderLogFiles( logs );

        for( const auto& log : answer )
        {
            std::cout << log << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
