cmake_minimum_required(VERSION 3.16)
project(my_project LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_subdirectory(filesystem)
add_subdirectory(engine)


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(my_project ${SOURCES})

target_include_directories(my_project PRIVATE include)

target_link_libraries(my_project PRIVATE engine)

# Copy all .cfg files from config/ to the build directory
file(GLOB CONFIG_FILES "${CMAKE_SOURCE_DIR}/config/*.cfg")

foreach(cfg ${CONFIG_FILES})
    add_custom_command(
        TARGET my_project POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${cfg}
                ${CMAKE_BINARY_DIR}
    )
endforeach()
