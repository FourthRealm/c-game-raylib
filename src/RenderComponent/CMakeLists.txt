add_library(RenderComponentLib STATIC RenderComponent.h RenderComponent.c)

target_link_libraries(RenderComponentLib PRIVATE raylib EntityLib)

target_include_directories(RenderComponentLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})