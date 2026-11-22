cmake_minimum_required(VERSION 3.20)


# If no build type specified, fall back to debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    #utiltiy build for bundling builds together
    option(CMAKE_UNITY_BUILD "Set CMake unity builds to on" OFF) #this caused an error
    #Build time optimisations 
    ##ccache for caching builds 
    find_program(CCACHE_LOCATION ccache)
    if(CCACHE_LOCATION)
        set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_LOCATION}")
        set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_LOCATION}")
    endif()
endif()

project(P04_Library VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE ALL_CORE_SOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/core/src/*.cpp"
)



add_library(P04_Library STATIC
    ${ALL_CORE_SOURCE_FILES}
)

target_include_directories(P04_Library
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/core/include/"
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(P04_Library PRIVATE
        $<$<CONFIG:Release>:-O3>
    )
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU") #gnu expects this "libaray" of experimental features to be specified for whatever reason
    target_link_libraries(P04_Library PRIVATE stdc++exp)
endif()

target_compile_features(P04_Library PUBLIC cxx_std_20)


#qt interface 
find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(CMAKE_AUTOMOC ON)

add_executable(P04_App
    app/main.cpp
    app/mainwindow.h
    app/mainwindow.cpp
)
target_link_libraries(P04_App PRIVATE P04_Library Qt6::Widgets)

add_custom_command(TARGET P04_App POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_SOURCE_DIR}/wordlist.txt
        $<TARGET_FILE_DIR:P04_App>/wordlist.txt)