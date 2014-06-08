CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# Project name.
PROJECT(M3D)

# Library name.
SET(LIBRARY_NAME M3D)

# Options
OPTION(tests "Build all unit tests" ON)

# Output directories.
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set project include & source root directory path variables.
SET(INC_ROOT ${PROJECT_SOURCE_DIR}/include)
SET(SRC_ROOT ${PROJECT_SOURCE_DIR}/source)

# Include headers.
INCLUDE_DIRECTORIES(${INC_ROOT})

# Files.
SET(LIBRARY_SRCS
	${INC_ROOT}/Vector3.hpp
	${SRC_ROOT}/Vector3.cpp

	${INC_ROOT}/Vector4.hpp
	${SRC_ROOT}/Vector4.cpp

	${INC_ROOT}/Quaternion.hpp
	${SRC_ROOT}/Quaternion.cpp

	${INC_ROOT}/Matrix3.hpp
	${SRC_ROOT}/Matrix3.cpp

	${INC_ROOT}/Matrix4.hpp
	${SRC_ROOT}/Matrix4.cpp
)

# Use c++11 in all cases.
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

# Create a static library.
ADD_LIBRARY(${LIBRARY_NAME} STATIC ${LIBRARY_SRCS})

# Unit tests.
IF (tests)
	INCLUDE(CTest)
	ADD_SUBDIRECTORY(tests)
ENDIF()

# Install.
INSTALL(TARGETS ${LIBRARY_NAME} DESTINATION lib)
INSTALL(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
		DESTINATION include/M3D
		PATTERN ".svn" EXCLUDE
		PATTERN ".DS_Store" EXCLUDE)
