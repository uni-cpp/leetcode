
project( leetcode )

set( HEADERS
    "include/leetcode/Solution153.hpp"
    "include/leetcode/Solution162.hpp"
)

set( SOURCES
    "app/main.cpp"

    "src/leetcode/Solution153.cpp"
    "src/leetcode/Solution162.cpp"
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
