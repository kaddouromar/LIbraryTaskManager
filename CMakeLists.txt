cmake_minimum_required(VERSION 3.10)
project(LibraryTaskManager)

# Enable testing
enable_testing()

# Add Google Test
include(FetchContent)


FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)



FetchContent_MakeAvailable(googletest)

# Create a library for the core functionality
add_library(LibraryCore
    book.cpp
    user.cpp
    task.cpp
)

# Ensure the LibraryCore library includes the current directory for headers
target_include_directories(LibraryCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Link Google Test with LibraryCore
target_link_libraries(LibraryCore PUBLIC gtest)

# Add the test executable
add_executable(test_LibraryTaskManager
    book_test.cpp
    user_test.cpp
    task_test.cpp
)

# Link the test executable to Google Test and the core library
target_link_libraries(test_LibraryTaskManager PRIVATE LibraryCore gtest gtest_main)

# Add tests
add_test(NAME LibraryTests COMMAND test_LibraryTaskManager)
