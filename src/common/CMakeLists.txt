file(GLOB SRC "*.cpp" "*.h")
file(GLOB GL_SRC "gl/*.cpp" "gl/*.h")

if(WIN32)
    file(GLOB VK_SRC "vk/*.cpp" "vk/*.h")
endif()

source_group("" FILES ${SRC})
source_group("gl" FILES ${GL_SRC})
source_group("vk" FILES ${VK_SRC})

add_library(common ${SRC} ${GL_SRC} ${VK_SRC})
set_default_includes(common)
set_default_definitions(common)

if(MSVC)
    target_compile_options(common PRIVATE /wd4267 /wd4244 /wd4312)
endif()
