add_app(transform_gl "gl/*.cpp;gl/*.h")
set_target_properties(transform_gl PROPERTIES FOLDER src)

if(WIN32)
    add_app(transform_vk "vk/*.cpp;vk/*.h")
    set_target_properties(transform_vk PROPERTIES FOLDER src)
endif()