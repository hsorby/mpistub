
add_executable(mpiexec main_mpiexec.c)
add_executable(mpicc main_mpicc.c argcheck.c argcheck.h)
add_executable(mpicxx main_mpicxx.c argcheck.c argcheck.h)
add_executable(mpif90 main_mpif90.c argcheck.c argcheck.h)
add_library(mpi mpi.c mpi.h)
add_library(mpifort mpi_stubs.f90)

target_include_directories(mpi PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(mpifort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS mpi mpifort mpicc mpicxx mpif90 mpiexec EXPORT mpistub-targets
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include/mpistub
    ARCHIVE DESTINATION lib/mpistub
    LIBRARY DESTINATION lib/mpistub)
install(FILES mpi.h mpif.h mpi_stubs_f90.h DESTINATION include/mpistub)
install(EXPORT mpistub-targets DESTINATION lib/mpistub)
