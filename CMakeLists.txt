cmake_minimum_required (VERSION 3.14)

# Version Information ----------------------------------------
project (sum_of_subset)

# c++ STANDARD ----------------------------------------
set(CMAKE_CXX_STANDARD 17)

# Include Directories ----------------------------------------
include_directories("${PROJECT_SOURCE_DIR}/deps/utility_provider/include/"
"${PROJECT_SOURCE_DIR}/deps/opengl/include/")

# Add Subdirectory ----------------------------------------
add_subdirectory(src)

# Add Executable ----------------------------------------
add_executable(sum_of_subset main.cpp)

target_link_libraries(sum_of_subset SumOfSubset ${PROJECT_SOURCE_DIR}/deps/utility_provider/lib/libUtilityProvider.a)