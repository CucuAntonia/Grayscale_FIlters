cmake_minimum_required(VERSION 3.0)

project(PracticaSpring2022)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../PracticaSpring2022_Binaries")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_subdirectory(Algorithms)
add_subdirectory(ImageProcessingApp)
add_subdirectory(Utils)
add_subdirectory(UserInterface)

#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}   
	
#ADD_DEFINITIONS(-DHAVE_CONFIG_H)	
#							)
#SET(Qt_PACKAGES Qt5::Widgets
#				Qt5::Core
#				Qt5::Gui
#				)



# find OpenCV package
#	FIND_PACKAGE(OpenCV REQUIRED)
#	SET(OpenCV_STATIC OFF)
	
#set deafult opencv dir
#	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "D:\OpenCV\opencv\build" )
	
# find qt package
#	find_package(Qt5Widgets REQUIRED)
#	find_package(Qt5OpenGL REQUIRED)
#	find_package(Qt5Concurrent REQUIRED)
	
#target_include_directories(PracticaSpring2022 PUBLIC ${OpenCV_INCLUDE_DIRS})
#TARGET_LINK_LIBRARIES(PracticaSpring2022  Qt5::Widgets ${OpenCV_LIBS})


