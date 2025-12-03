add_library(GameEngineLib STATIC GameEngine.c GameEngine.h)

target_link_libraries(GameEngineLib PRIVATE raylib ConfigLib EntityLib RenderComponentLib)

target_include_directories(GameEngineLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})