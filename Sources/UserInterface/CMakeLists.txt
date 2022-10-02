cmake_minimum_required(VERSION 3.5)

project(UserInterface VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(LibrarySources
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
	
)


#QT5_ADD_RESOURCES(res.qrc)


add_definitions(-DUI_EXPORT)
add_library(${PROJECT_NAME} SHARED ${LibrarySources})



target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/Algorithms
	${CMAKE_SOURCE_DIR}/Utils
	
)
target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets
		      ${OpenCV_LIBS}	
		      Algorithms.lib
		      Utils.lib
		      )


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(UserInterface)
endif()
