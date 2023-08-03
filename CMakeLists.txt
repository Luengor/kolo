cmake_minimum_required(VERSION 3.5)
project(kolo)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Add all the source files
file(GLOB SOURCES CMAKE_CONFIGURE_DEPENDS
    "src/*.cpp"
    "src/*.hpp"
)

# Add memory sanitizer
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES})
