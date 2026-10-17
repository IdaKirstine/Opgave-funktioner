# This file downloads mtest to the project.
# To use it, just include the file in the top level CMakeLists.txt file, e.g.:
#   include(cmake/mtest.cmake)

# Setting this policy to NEW avoids a warning in newer versions of CMake.
cmake_policy(SET CMP0135 NEW)

# Installation of a testing framework - here the simple mtest.
include(FetchContent)
FetchContent_Declare(mtest
        URL https://github.com/MortenSchou/mtest/archive/refs/tags/v0.2.1.zip
        URL_HASH SHA256=1f3b5e0d685a7e7b8beca3c47c7bbcd23d932f46d68723a36bc270202f7a60f2
)
FetchContent_MakeAvailable(mtest)
