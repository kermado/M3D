CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Project name.
PROJECT(M3D)

# CMake module path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Library name.
SET(LIBRARY_NAME M3D)

# Options
OPTION(TESTS "Build all unit tests" ON)
OPTION(COVERALLS "Enable generation and sending of coveralls data" false)
OPTION(COVERAGE "Enable generation of code coverage" false)

# Output directories.
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set project include & source root directory path variables.
SET(INC_ROOT ${PROJECT_SOURCE_DIR}/include/M3D)
SET(SRC_ROOT ${PROJECT_SOURCE_DIR}/source/M3D)

# Include headers.
INCLUDE_DIRECTORIES(${INC_ROOT})

# Files.
SET(LIBRARY_SRCS
	${INC_ROOT}/Vector2.hpp
	${SRC_ROOT}/Vector2.cpp

	${INC_ROOT}/Vector3.hpp
	${SRC_ROOT}/Vector3.cpp

	${INC_ROOT}/Vector4.hpp
	${SRC_ROOT}/Vector4.cpp

	${INC_ROOT}/Quaternion.hpp
	${SRC_ROOT}/Quaternion.cpp

	${INC_ROOT}/Matrix2.hpp
	${SRC_ROOT}/Matrix2.cpp

	${INC_ROOT}/Matrix3.hpp
	${SRC_ROOT}/Matrix3.cpp

	${INC_ROOT}/Matrix4.hpp
	${SRC_ROOT}/Matrix4.cpp
)

# Use C++11 in all cases.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Coveralls
INCLUDE(CodeCoverage)
INCLUDE(Coveralls)
IF ((COVERALLS OR COVERAGE) AND CMAKE_BUILD_TYPE STREQUAL "Debug")
	MESSAGE(STATUS "Will generate coverage data")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
	SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
	SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

	IF (COVERAGE)
		setup_target_for_coverage(coverage M3DTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} coverage)
	ENDIF()

	IF (COVERALLS)
		setup_target_for_coveralls(coveralls M3DTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
	ENDIF()
ENDIF()

# Unit tests.
IF (TESTS)
	INCLUDE(CTest)
	ADD_SUBDIRECTORY(tests)
ENDIF()

# Create a static library.
ADD_LIBRARY(${LIBRARY_NAME} STATIC ${LIBRARY_SRCS})

# Install.
INSTALL(TARGETS ${LIBRARY_NAME} DESTINATION lib)
INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/include/M3D
		DESTINATION include
		PATTERN ".svn" EXCLUDE
		PATTERN ".DS_Store" EXCLUDE)
