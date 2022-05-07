
project( leetcode )

set( HEADERS
    "include/leetcode/Solution11.hpp"
    "include/leetcode/Solution15.hpp"
    "include/leetcode/Solution82.hpp"
    "include/leetcode/Solution153.hpp"
    "include/leetcode/Solution162.hpp"
    "include/leetcode/Solution209.hpp"
    "include/leetcode/Solution438.hpp"
    "include/leetcode/Solution713.hpp"
    "include/leetcode/Solution844.hpp"
    "include/leetcode/Solution986.hpp"
)

set( SOURCES
    "app/main.cpp"

    "src/leetcode/Solution11.cpp"
    "src/leetcode/Solution15.cpp"
    "src/leetcode/Solution82.cpp"
    "src/leetcode/Solution153.cpp"
    "src/leetcode/Solution162.cpp"
    "src/leetcode/Solution209.cpp"
    "src/leetcode/Solution438.cpp"
    "src/leetcode/Solution713.cpp"
    "src/leetcode/Solution844.cpp"
    "src/leetcode/Solution986.cpp"
)

# treat_all_warnings_as_errors()

add_executable( ${PROJECT_NAME}
    ${HEADERS}
    ${SOURCES}
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

install( TARGETS ${PROJECT_NAME}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
