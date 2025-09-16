add_app(Transform_GL "gl/*.cpp;gl/*.h")
set_target_properties(Transform_GL PROPERTIES FOLDER src)

if(WIN32)
    add_app(Transform_VK "vk/*.cpp;vk/*.h")
    set_target_properties(Transform_VK PROPERTIES FOLDER src)
endif()