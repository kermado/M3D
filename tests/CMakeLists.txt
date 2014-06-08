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

# Find the boost test library.
FIND_PACKAGE(Boost COMPONENTS unit_test_framework REQUIRED)

# Add the unit tests executable.
ADD_EXECUTABLE(${PROJECT_TESTS_NAME} ${TEST_SRCS})

# Link the unit tests executable with the M3D and Boost Test libraries.
TARGET_LINK_LIBRARIES(${PROJECT_TESTS_NAME} ${LIBRARY_NAME})
TARGET_LINK_LIBRARIES(${PROJECT_TESTS_NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

# CTest setup.
ENABLE_TESTING()
ADD_TEST(UnitTests ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_TESTS_NAME})
