project( leetcode )

set( HEADERS
    "include/leetcode/Solution11.hpp"
    "include/leetcode/Solution15.hpp"
    "include/leetcode/Solution82.hpp"
    "include/leetcode/Solution117.hpp"
    "include/leetcode/Solution130.hpp"
    "include/leetcode/Solution146.hpp"
    "include/leetcode/Solution153.hpp"
    "include/leetcode/Solution162.hpp"
    "include/leetcode/Solution200.hpp"
    "include/leetcode/Solution209.hpp"
    "include/leetcode/Solution438.hpp"
    "include/leetcode/Solution547.hpp"
    "include/leetcode/Solution572.hpp"
    "include/leetcode/Solution713.hpp"
    "include/leetcode/Solution844.hpp"
    "include/leetcode/Solution986.hpp"
    "include/leetcode/Solution1091.hpp"
)

set( SOURCES
    "app/main.cpp"

    "src/leetcode/Solution11.cpp"
    "src/leetcode/Solution15.cpp"
    "src/leetcode/Solution82.cpp"
    "src/leetcode/Solution117.cpp"
    "src/leetcode/Solution130.cpp"
    "src/leetcode/Solution146.cpp"
    "src/leetcode/Solution153.cpp"
    "src/leetcode/Solution162.cpp"
    "src/leetcode/Solution200.cpp"
    "src/leetcode/Solution209.cpp"
    "src/leetcode/Solution438.cpp"
    "src/leetcode/Solution547.cpp"
    "src/leetcode/Solution572.cpp"
    "src/leetcode/Solution713.cpp"
    "src/leetcode/Solution844.cpp"
    "src/leetcode/Solution986.cpp"
    "src/leetcode/Solution1091.cpp"
)

treat_all_warnings_as_errors()

add_executable( ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)
add_executable( uni::leetcode ALIAS ${PROJECT_NAME} )

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install( TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
