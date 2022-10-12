cmake_minimum_required(VERSION 3.0)

project(PracticaSpring2022)

IF(CMAKE_CL_64)
		MESSAGE(STATUS "X64")
		
		set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/PracticaSpring2022_Binaries")
		set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
		set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
							 
	ENDIF()



add_subdirectory(Algorithms)
add_subdirectory(ImageProcessingApp)
add_subdirectory(Utils)
add_subdirectory(UserInterface)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}  ) 
	


							
SET(Qt_PACKAGES Qt5::Widgets
	Qt5::Core
	Qt5::Gui
	)

if(CMAKE_CL_64)
		message(STATUS "X64")
		SET(CMAKE_PREFIX_PATH  ${CMAKE_PREFIX_PATH} 
							"D:/Qt/5.15.2/msvc2019_64/lib/cmake/Qt5Widgets"     
							)
endif()	

# find OpenCV package
	FIND_PACKAGE(OpenCV REQUIRED)
	SET(OpenCV_STATIC OFF)
	
#set deafult opencv dir
	set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "D:/OpenCV/opencv/build" )
	
# find qt package
	find_package(Qt5Widgets REQUIRED)
	find_package(Qt5OpenGL REQUIRED)
	find_package(Qt5Concurrent REQUIRED)
	


if(CMAKE_CL_64)	

	install (FILES	$<TARGET_FILE:Qt5::Widgets> 
	 				$<TARGET_FILE:Qt5::Core>
					$<TARGET_FILE:Qt5::Gui>
	 		DESTINATION "${CMAKE_BINARY_DIR}/install/PracticaSpring2022/dependencies/QtPackage/dlls/x64/$<CONFIGURATION>" )

	install (FILES	 $<TARGET_FILE:opencv_world> DESTINATION "${CMAKE_BINARY_DIR}/install/PracticaSpring2022/dependencies/OpenCvPackage/dlls/x64/$<CONFIGURATION>" )

endif()
