
add_executable(mpiexec main_mpiexec.c)
add_executable(mpicc main_mpicc.c argcheck.c argcheck.h)
add_executable(mpicxx main_mpicxx.c argcheck.c argcheck.h)
add_executable(mpif90 main_mpif90.c argcheck.c argcheck.h)
add_library(mpi mpi.c mpi.h)

target_include_directories(mpi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS mpi mpicc mpicxx mpif90 mpiexec EXPORT mpistub-targets
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib)
install(FILES mpi.h mpif.h DESTINATION include)
install(EXPORT mpistub-targets DESTINATION lib/cmake)
