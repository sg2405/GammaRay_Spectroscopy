cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(gamma_ray)

find_package(Geant4 REQUIRED ui_all vis_all)
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cc)
file (GLOB MACRO_FILES "scripts/*.mac")
file (COPY ${MACRO_FILES} DESTINATION ${CMAKE_BINARY_DIR}/)

add_executable(gamma_ray sim.cc ${sources})
target_link_libraries(gamma_ray ${Geant4_LIBRARIES})

add_custom_target(Tutorial DEPENDS gamma_ray)