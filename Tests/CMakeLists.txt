cmake_minimum_required(VERSION 3.0)

project("Tests")

set(LibrarySources
	Teste_ImageProcessingApp.cpp
)

add_library(${PROJECT_NAME} SHARED ${LibrarySources})

#Find OpenCV
if( NOT OpenCV_FOUND )
	find_package(OpenCV REQUIRED)
endif()

include_directories(${OpenCV_INCLUDE_DIRS})

#Find Qt
if( NOT Qt5Widgets_FOUND )
	find_package(Qt5Widgets REQUIRED)
endif()


#Automatically add the current source and build directories to the include path.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_link_libraries(${PROJECT_NAME} 
		      Algorithms.lib
		      Utils.lib
		      Qt5::Widgets 
		      ${OpenCV_LIBS}
	              )

#Link this project with the runtime output dir.
target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)


install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin"
        LIBRARY DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/lib"
		)

#put batch file that runs tests into the delivery package
	install (FILES "${CMAKE_CURRENT_SOURCE_DIR}/Scripts/run_tests.bat" DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage")