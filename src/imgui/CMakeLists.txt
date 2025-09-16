add_app(ImGui_GL "gl/*.cpp;gl/*.h")
set_target_properties(ImGui_GL PROPERTIES FOLDER src)

if(WIN32)
    add_app(ImGui_VK "vk/*.cpp;vk/*.h")
    set_target_properties(ImGui_VK PROPERTIES FOLDER src)
endif()