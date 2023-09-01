cmake_minimum_required(VERSION 2.9 FATAL_ERROR)

project(C)

set(CMAKE_PREFIX_PATH  /Users/mac/Documents/software/geant4-v11.0.4-install ${CMAKE_PREFIX_PATH})

option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()


include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(cherenkova cherenkova.cc ${sources} ${headers})
target_link_libraries(cherenkova ${Geant4_LIBRARIES})

add_custom_target(C DEPENDS cherenkova)