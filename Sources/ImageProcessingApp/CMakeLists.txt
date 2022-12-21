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
		
add_dependencies(${PROJECT_NAME}
	Algorithms
	Utils
	UserInterface
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/Sources/Algorithms
	${CMAKE_SOURCE_DIR}/Sources/Utils
	${CMAKE_SOURCE_DIR}/Sources/UserInterface
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
	Qt5::Gui
	Qt5::Widgets
	${OpenCV_LIBS}
)

file(COPY "${CMAKE_SOURCE_DIR}/Tests/Data" DESTINATION "${CMAKE_BINARY_DIR}/bin")

#put all images into the resource directory
	install(DIRECTORY "${CMAKE_SOURCE_DIR}/Tests/Data" DESTINATION "${CMAKE_BINARY_DIR}/bin")


#put batch file that start the executable into the delivery package
	install (FILES "${CMAKE_SOURCE_DIR}/Scripts/Batch/start_application.bat" DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage")

#put batch file that run tests into the delivery package
	install (FILES "${CMAKE_SOURCE_DIR}/Scripts/Batch/run_tests.bat" DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage")

#put all images into the resource directory
	install(DIRECTORY "${CMAKE_SOURCE_DIR}/Resources" DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage")

#Set the install package for OpenCV
  	install (FILES $<TARGET_FILE:opencv_world> DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin" )

#Set the install package for QT
  install (FILES $<TARGET_FILE:Qt5::Widgets> 
		 $<TARGET_FILE:Qt5::Gui>
		 $<TARGET_FILE:Qt5::Core>
	 	 DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin" )


install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/bin"
        LIBRARY DESTINATION "${CMAKE_BINARY_DIR}/DeliveryPackage/lib"
		)



