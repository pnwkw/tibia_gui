add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME} PRIVATE main.cpp hook_functions.cpp gui_core.cpp gui_class.cpp static_class_functions.cpp)
target_compile_definitions(${PROJECT_NAME} PRIVATE TIBIA_8_6_1)
