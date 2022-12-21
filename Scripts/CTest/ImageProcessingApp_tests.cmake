include(${CTEST_SCRIPT_DIRECTORY}/cmakegui_config.cmake)

if(NOT DEFINED CTEST_PROJECT_NAME)
	message(FATAL_ERROR "CTEST_PROJECT_NAME not defined!")
endif()

CTEST_START(Experimental)
set(CTEST_CONFIGURE_COMMAND "${CMAKE_COMMAND}")
set(CTEST_CONFIGURE_COMMAND "${CTEST_CONFIGURE_COMMAND} \"-G${CTEST_CMAKE_GENERATOR}\"")
set(CTEST_CONFIGURE_COMMAND "${CTEST_CONFIGURE_COMMAND} \"${CTEST_SOURCE_DIRECTORY}\"")
CTEST_TEST(BUILD "${CTEST_BINARY_DIRECTORY}" RETURN_VALUE res)