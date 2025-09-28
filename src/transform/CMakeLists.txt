add_app(transform_gl "gl/*.cpp;gl/*.h")

if(WIN32)
    add_app(transform_vk "vk/*.cpp;vk/*.h")
endif()