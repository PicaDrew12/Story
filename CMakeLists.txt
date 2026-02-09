cmake_minimum_required(VERSION 3.16)
project(my_project LANGUAGES CXX)

# Automatically collect all .cpp files
file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    src/*.cpp
)

# Automatically collect all headers (optional)
file(GLOB_RECURSE HEADERS
    CONFIGURE_DEPENDS
    include/*.h
    include/*.hpp
)

# Build an executable, not a library
add_executable(my_project
    ${SOURCES}
    ${HEADERS}   # optional; CMake uses headers automatically for IDE grouping
)

# Tell the compiler where to find headers
target_include_directories(my_project
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)
