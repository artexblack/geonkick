# FindCairo.cmake

if(CMAKE_SYSTEM_NAME MATCHES Windows)

    message(STATUS "Find Cairo for Windows/MSYS2/UCRT64...")

    find_path(
        CAIRO_INCLUDE_DIRS
        NAMES cairo/cairo.h
        PATHS
            /ucrt64/include
            /ucrt64/include/cairo
    )

    find_library(
        CAIRO_LIBRARIES
        NAMES cairo
        PATHS
            /ucrt64/lib
    )

else()

    message(STATUS "Find Cairo for GNU/Linux...")

    find_path(CAIRO_INCLUDE_DIRS NAMES cairo/cairo.h)

    find_library(CAIRO_LIBRARIES NAMES cairo)

endif()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(
    Cairo
    DEFAULT_MSG
    CAIRO_INCLUDE_DIRS
    CAIRO_LIBRARIES
)

message(STATUS "CAIRO_INCLUDE_DIRS=${CAIRO_INCLUDE_DIRS}")
message(STATUS "CAIRO_LIBRARIES=${CAIRO_LIBRARIES}")

mark_as_advanced(CAIRO_INCLUDE_DIRS CAIRO_LIBRARIES)
