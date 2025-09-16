file(GLOB DEMOS_VENDOR_GLEW_SRC
    "glew/1.13/src/glew.c"
)

file(GLOB DEMOS_VENDOR_IMGUI_COMMON_SRC
    "imgui/*.cpp"
    "imgui/examples/imgui_impl_opengl3.cpp"
    "imgui/examples/imgui_impl_sdl.cpp"
)

if(WIN32)
    file(GLOB DEMOS_VENDOR_IMGUI_PLATFORM_SRC "imgui/examples/imgui_impl_vulkan.cpp")
endif()

source_group("glew" FILES ${DEMOS_VENDOR_GLEW_SRC})
source_group("imgui" FILES ${DEMOS_VENDOR_IMGUI_COMMON_SRC} ${DEMOS_VENDOR_IMGUI_PLATFORM_SRC})

add_library(Vendor STATIC
    ${DEMOS_VENDOR_GLEW_SRC}
    ${DEMOS_VENDOR_IMGUI_COMMON_SRC} ${DEMOS_VENDOR_IMGUI_PLATFORM_SRC}
)

find_package(OpenGL REQUIRED)

CPMAddPackage(
    NAME SDL2
    GITHUB_REPOSITORY libsdl-org/SDL
    GIT_TAG release-2.32.2
)

target_link_libraries(Vendor ${OPENGL_LIBRARY} ${DEMOS_VENDOR_PLATFORM_LIBS} SDL2::SDL2)

target_include_directories(Vendor PRIVATE
    "."
    "glew/1.13/include"
    "imgui"
)

set_target_properties(Vendor PROPERTIES FOLDER vendor)

if(WIN32)
    find_package(Vulkan REQUIRED)

    target_include_directories(Vendor PRIVATE
        ${Vulkan_INCLUDE_DIRS}
        "${Vulkan_INCLUDE_DIRS}/vulkan"
    )

    set(DEMOS_VENDOR_PLATFORM_LIBS
        ${Vulkan_LIBRARIES}
        winmm.lib
        imm32.lib
        version.lib
    )
elseif(APPLE)
    find_library(DEMOS_VENDOR_CARBON_LIB Carbon)
    find_library(DEMOS_VENDOR_IOKIT_LIB IOKit)
    find_library(DEMOS_VENDOR_FORCEFEEDBACK_LIB ForceFeedback)
    find_library(DEMOS_VENDOR_COCOA_LIB Cocoa)
    find_library(DEMOS_VENDOR_AUDIOUNIT_LIB AudioUnit)
    find_library(DEMOS_VENDOR_COREAUDIO_LIB CoreAudio)
    find_library(DEMOS_VENDOR_COREVIDEO_LIB CoreVideo)
    find_library(DEMOS_VENDOR_COREFOUNDATION_LIB CoreFoundation)

    set(DEMOS_VENDOR_PLATFORM_LIBS
        ${DEMOS_VENDOR_CARBON_LIB}
        ${DEMOS_VENDOR_IOKIT_LIB}
        ${DEMOS_VENDOR_FORCEFEEDBACK_LIB}
        ${DEMOS_VENDOR_COCOA_LIB}
        ${DEMOS_VENDOR_AUDIOUNIT_LIB}
        ${DEMOS_VENDOR_COREAUDIO_LIB}
        ${DEMOS_VENDOR_COREVIDEO_LIB}
        ${DEMOS_VENDOR_COREFOUNDATION_LIB}
    )
endif()

set_default_definitions(Vendor)
