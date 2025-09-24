cmake_minimum_required(VERSION 3.10)

project(Demos)
include(cmake/CPM.cmake)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Config types" FORCE)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(MSVC)
    add_compile_options("$<$<CONFIG:DEBUG>:/MTd>")
    add_compile_options("$<$<CONFIG:RELEASE>:/MT>")
    add_compile_options(/std:c++14)
    add_compile_options(/MP)
endif()

function(set_default_definitions TARGET)
    target_compile_definitions(${TARGET} PRIVATE
        HAVE_LIBC
        GLEW_STATIC
        SDL_HAPTIC_DISABLED
        SDL_JOYSTICK_DISABLED
        "$<$<CONFIG:DEBUG>:DEMOS_DEBUG>"
    )
endfunction()

function(set_default_includes TARGET)
    target_include_directories(${TARGET} PRIVATE
        "${CMAKE_SOURCE_DIR}/src"
        "${CMAKE_SOURCE_DIR}/vendor" # TODO needed?
        "${CMAKE_SOURCE_DIR}/vendor/glew/1.13/include"
        "${CMAKE_SOURCE_DIR}/vendor/stb_truetype/1.11"
        "${CMAKE_SOURCE_DIR}/vendor/stb_image/2.15"
        "${CMAKE_SOURCE_DIR}/vendor/glm/0.9.8.4"
        "${CMAKE_SOURCE_DIR}/vendor/imgui"
    )
    target_include_directories(${TARGET} PRIVATE ${SDL2_SOURCE_DIR}/include)

    if(WIN32)
        find_package(Vulkan REQUIRED)
        target_include_directories(${TARGET} PRIVATE
            ${Vulkan_INCLUDE_DIRS}
            "${Vulkan_INCLUDE_DIRS}/vulkan"
        )
    endif()
endfunction()

function(add_app TARGET SOURCES)
    file(GLOB SRC ${SOURCES})
    source_group("" FILES ${SRC})
    add_executable(${TARGET} ${SRC})
    set_default_includes(${TARGET})
    set_default_definitions(${TARGET})
    target_link_libraries(${TARGET} vendor common)

    if(MSVC)
        target_compile_options(${TARGET} PRIVATE /wd4267 /wd4244 /wd4312)
    endif()
endfunction()

add_subdirectory("vendor")
add_subdirectory("src/common")
add_subdirectory("src/stb_truetype")
add_subdirectory("src/transform")
add_subdirectory("src/skybox")
add_subdirectory("src/imgui")
