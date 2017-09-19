

add_library(mpistub mpi.c mpi.h)

target_include_directories(mpistub PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS mpistub EXPORT mpistub-targets
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
install(FILES mpi.h DESTINATION include)
install(EXPORT mpistub-targets DESTINATION lib/cmake)
