cmake_minimum_required(VERSION 3.5)
project(homewatch)
set(CMAKE_BUILD_TYPE "DEBUG")
find_package( OpenCV REQUIRED )

include_directories(
    ${PROJECT_SOURCE_DIR}/controllers
    ${PROJECT_SOURCE_DIR}/model
)

file( GLOB_RECURSE MODEL_HPPS ${PROJECT_SOURCE_DIR}/model/*.hpp ) 
file( GLOB_RECURSE MODEL_CPPS ${PROJECT_SOURCE_DIR}/model/*.cpp )

file( GLOB_RECURSE CONTROLLERS_HPPS ${PROJECT_SOURCE_DIR}/controllers/*.hpp ) 
file( GLOB_RECURSE CONTROLLERS_CPPS ${PROJECT_SOURCE_DIR}/controllers/*.cpp )

message(${MODEL_HPPS})

add_executable( app 
                ${MODEL_CPPS} ${CONTROLLERS_CPPS} 
                ${MODEL_HPPS} ${CONTROLLERS_HPPS}
                main.cpp )

target_link_libraries( app ${OpenCV_LIBS} )

