add_app(imgui_gl "gl/*.cpp;gl/*.h")

if(WIN32)
    add_app(imgui_vk "vk/*.cpp;vk/*.h")
endif()