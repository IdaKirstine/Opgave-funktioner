cmake_minimum_required(VERSION 3.14)
project(opgaver_funktioner)

set(CMAKE_C_STANDARD 11)

add_executable(opgave-a opgave-a.c)
add_executable(opgave-b opgave-b.c)
add_executable(opgave-c opgave-c.c)
add_executable(opgave-d opgave-d.c)
 #Link math to this target, so functions in <math.h> are available.
add_executable(opgave-e opgave-e.c)

add_executable(opgave-g opgave-g.c)
#target_link_libraries(opgave-g m)  # Link math to this target, so functions in <math.h> are available.
add_executable(opgave-h opgave-h.c)

# opgave b
add_library(primes Primes.c)
#target_link_libraries((primes m))
target_link_libraries(opgave-b primes)

target_link_libraries(opgave-c primes)



