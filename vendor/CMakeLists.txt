# 'Google_tests' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test source
add_subdirectory(googletest)
include_directories(googletest/googletest/include)
include_directories(googletest/googlemock/include)

include_directories(../src)
include_directories(../test/mock)
include_directories(../test/fake)
# 'Google_tests_run' is the target name
file(GLOB_RECURSE FAKE
	../test/fake/**
)
file(GLOB_RECURSE TESTS
	../test/main.cpp
	../test/test_**
)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

add_executable(Google_Tests_run ${FAKE} ${TESTS})  
target_link_libraries(Google_Tests_run pthread ${PROJ_NAME} gtest gmock gtest_main)

