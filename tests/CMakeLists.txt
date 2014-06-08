# Name for the unit tests target.
SET(PROJECT_TESTS_NAME ${PROJECT_NAME}Tests)

# Path to the unit test sources root directory.
SET(SRC_ROOT ${PROJECT_SOURCE_DIR}/tests)

# Include library headers.
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

# Unit test sources.
SET(TEST_SRCS
	${SRC_ROOT}/main.cpp
	${SRC_ROOT}/Vector3.cpp
	${SRC_ROOT}/Vector4.cpp
	${SRC_ROOT}/Quaternion.cpp
	${SRC_ROOT}/Matrix3.cpp
	${SRC_ROOT}/Matrix4.cpp
)

# Add the unit tests executable.
ADD_EXECUTABLE(${PROJECT_TESTS_NAME} ${TEST_SRCS})

# Link the unit tests executable with the library.
TARGET_LINK_LIBRARIES(${PROJECT_TESTS_NAME} ${LIBRARY_NAME})

ENABLE_TESTING()
ADD_TEST(UnitTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_TESTS_NAME})
