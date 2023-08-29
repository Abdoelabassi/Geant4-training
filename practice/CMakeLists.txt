cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(Cherenkova)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(cherenkova cherenkova.cc ${sources} ${headers})
target_link_libraries(cherenkova ${Geant4_LIBRARIES})

add_custom_target(Cherenkova DEPENDS cherenkova)