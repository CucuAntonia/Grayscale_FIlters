cmake_minimum_required(VERSION 3.0)
project(ImageProcessingApp)

#CMake will handle the Qt rcc code generator automatically, i.e. without having to use commands like QT4_ADD_RESOURCES()
set(CMAKE_AUTORCC ON)

set( AppSources
	main.cpp
)

QT5_ADD_RESOURCES(RESOURCE_QRC ${INTERFACE_RESOURCES})

add_executable(${PROJECT_NAME} ${RESOURCE_QRC} ${AppSources})

#Find OpenCV
if( NOT OpenCV_FOUND )
	find_package(OpenCV REQUIRED)
endif()
	
#Find Qt package
if( NOT Qt5Gui_FOUND )
	find_package(Qt5Gui REQUIRED)
endif()

if( NOT Qt5Widgets_FOUND )
	find_package(Qt5Widgets REQUIRED)
endif()
	
#Automatically add the current source and build directories to the include path.
set(CMAKE_INCLUDE_CURRENT_DIR ON)
	
add_dependencies(${PROJECT_NAME}
	Algorithms
	Utils
	UserInterface
	Tests
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/Sources/Algorithms
	${CMAKE_SOURCE_DIR}/Sources/Utils
	${CMAKE_SOURCE_DIR}/Sources/UserInterface
	${CMAKE_SOURCE_DIR}/Tests
	${OpenCV_INCLUDE_DIRS}
	
)

#Link this project with the runtime output dir.
target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

target_link_libraries(${PROJECT_NAME} 
	Algorithms.lib
	Utils.lib
	UserInterface.lib
	Tests.lib
	Qt5::Gui
	Qt5::Widgets
	${OpenCV_LIBS}
)

#put all images into the resource directory
	install(DIRECTORY "${CMAKE_SOURCE_DIR}/Resources" DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage")

#put all images into the resource directory
	install(DIRECTORY "${CMAKE_SOURCE_DIR}/Tests/Data" DESTINATION "${CMAKE_BINARY_DIR}/bin")

#Set the install package for OpenCV
  	install (FILES $<TARGET_FILE:opencv_world> DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin" )

#Set the install package for QT
  install (FILES $<TARGET_FILE:Qt5::Widgets> 
		 $<TARGET_FILE:Qt5::Gui>
	 	 DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin" )


install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin"
        LIBRARY DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/lib"
		)


