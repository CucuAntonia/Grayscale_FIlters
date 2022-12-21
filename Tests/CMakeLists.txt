cmake_minimum_required(VERSION 3.0)

project(Tests)

set(LibrarySources
	Teste_ImageProcessingApp.cpp
)

#add_executable(${PROJECT_NAME} ${LibrarySources})
add_library(${PROJECT_NAME} SHARED ${LibrarySources})

#Find OpenCV
if( NOT OpenCV_FOUND )
	find_package(OpenCV REQUIRED)
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
message("OpenCV found")
#Find Qt
if( NOT Qt5Widgets_FOUND )
	find_package(Qt5Widgets REQUIRED)
endif()
message("Qt found")
target_link_libraries(${PROJECT_NAME} 
		      Algorithms.lib
		      Utils.lib
		      Qt5::Widgets 
		      ${OpenCV_LIBS}
	              )
message("Link libs")
#Link this project with the runtime output dir.
target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
message("Before add test")
add_test(
  NAME ${PROJECT_NAME}
  COMMAND vstest.console.exe Tests.dll
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>
  )


message("After add test")
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin"
        LIBRARY DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/lib"
		)

