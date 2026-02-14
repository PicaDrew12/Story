file(GLOB_RECURSE ENGINE_SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_library(filesystem ${ENGINE_SOURCES})

target_include_directories(filesystem PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
