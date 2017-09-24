

cmake_minimum_required(VERSION 3.4 FATAL_ERROR)
project(mpistub VERSION 0.1.0 LANGUAGES C Fortran)

option(BUILD_SHARED_LIBS "Build shared library." ON)

add_subdirectory(src)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/mpistub-config.cmake "include(\"${CMAKE_CURRENT_LIST_DIR}/ClimbingStatsTargets.cmake\")")

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/mpistub-config.cmake DESTINATION lib/mpistub)
