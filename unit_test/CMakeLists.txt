# Cmake minimum required version number
cmake_minimum_required(VERSION 3.9)

# Set to use C++ 11
set (CMAKE_CXX_STANDARD 11)

#---------------------------------------------------------------------
# Google Test Framework

# Set google test folder
# It must be consistent with the "CMakeLists.txt.in" in "<Project>/unit_test" folder
set( MyUnitTestFolder "unit_test" )
set( GoogleTestWorkPath "${CMAKE_BINARY_DIR}/${MyUnitTestFolder}" )

# Download and unpack googletest at configure time
## Download file and create makefile
configure_file ( ${CMAKE_SOURCE_DIR}/${MyUnitTestFolder}/CMakeLists.txt.in 
				 googletest-download/CMakeLists.txt )
execute_process ( COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" ${GoogleTestWorkPath}/googletest-download
  				  RESULT_VARIABLE result
  				  WORKING_DIRECTORY ${GoogleTestWorkPath}/googletest-download )
if(result)
	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

## Build google test
execute_process( COMMAND ${CMAKE_COMMAND} --build ${GoogleTestWorkPath}/googletest-download
			     RESULT_VARIABLE result
				 WORKING_DIRECTORY ${GoogleTestWorkPath}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${GoogleTestWorkPath}/googletest-src
                 ${GoogleTestWorkPath}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
#if (CMAKE_VERSION VERSION_LESS 2.8.11)
#	include_directories("${gtest_SOURCE_DIR}/include")
#endif()

# Now simply link against gtest or gtest_main as needed. Eg
set(EXECUTABLE_OUTPUT_PATH ${GoogleTestWorkPath}/bin)

#---------------------------------------------------------------------
# Add executables
## Need to link with gtest_main
# Add all Executables
include_directories (${CMAKE_SOURCE_DIR}/src)

add_executable( algo_unit_test algo.t.cpp )
target_link_libraries( algo_unit_test gtest_main algo_datastructure_lib)

add_test(NAME algo_unit_test COMMAND algo_unit_test)



