add_app(imgui_gl "gl/*.cpp;gl/*.h")
set_target_properties(imgui_gl PROPERTIES FOLDER src)

if(WIN32)
    add_app(imgui_vk "vk/*.cpp;vk/*.h")
    set_target_properties(imgui_vk PROPERTIES FOLDER src)
endif()