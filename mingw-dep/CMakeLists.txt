
set(exe_name "DruidMingw-Dep")

##################################
#       Gather Dependencies      #
##################################

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")
# if (APPLE)
#     FIND_PACKAGE(Boost 1.58 COMPONENTS system-mt filesystem-mt thread-mt chrono program_options-mt serialization-mt REQUIRED)
# else()
#     FIND_PACKAGE(Boost 1.58 COMPONENTS system filesystem thread chrono program_options serialization REQUIRED)
# endif()
# if (BOOST_FOUND)
#     set(INCLUDE ${BOOST_INCLUDE_DIRS})
#     set(LIBRARY ${BOOST_LIBRARIES})
#     message("-- Found Boost")
#     message("--\t includes: ${INCLUDE}")
#     message("--\t libs: ${LIBRARY}")
# else ()
#     message(FATAL_ERROR "## Not Found - Boost")
# endif ()

# "-D_USE_MATH_DEFINES"
# "-DBOOST_USE_WINDOWS_H" # boost warning
# "-D_WIN32_WINNT=0x0601"

if (MINGW)
    set(LIBRARY
        mingw32
        ws2_32
    )
else()
    return()
endif()


##################################
#          Build Binary          #
##################################

FILE(GLOB_RECURSE source_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*
)
FILE(GLOB_RECURSE header_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h*
)

add_library(${exe_name}
    STATIC
    ${source_files}
    ${header_files}
)

target_link_libraries(${exe_name}
    ${LIBRARY}
)
target_include_directories(${exe_name}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${INCLUDE}
)
