cmake_minimum_required(VERSION 3.0)
project(ImageProcessingApp)

set( AppSources
	main.cpp
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
#set(CMAKE_PREFIX_PATH $ENV{QTDIR})
string(REPLACE ":" ";" CMAKE_PREFIX_PATH "$ENV{CMAKE_PREFIX_PATH}")
list(APPEND CMAKE_PREFIX_PATH "D:/QtCreator/5.15.2/msvc2019_64")
find_package(Qt5 COMPONENTS REQUIRED Core)
find_package(Qt5Widgets REQUIRED)
find_package(OpenCV REQUIRED)



add_executable(${PROJECT_NAME} ${AppSources} res.qrc)

add_dependencies(${PROJECT_NAME}
	Algorithms
	Utils
	UserInterface
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_SOURCE_DIR}/Algorithms
	${CMAKE_SOURCE_DIR}/Utils
	${CMAKE_SOURCE_DIR}/UserInterface
	
)


target_link_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

target_link_libraries(${PROJECT_NAME}
	Qt5::Widgets
	Algorithms.lib
	Utils.lib
	UserInterface.lib
	${OpenCV_LIBS}
	
)



