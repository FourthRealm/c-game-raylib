add_executable(Game main.c Entity.c)

target_include_directories(Game PRIVATE ${CMAKE_SOURCE_DIR}/raylib)

target_link_libraries(Game PRIVATE ${CMAKE_SOURCE_DIR}/raylib/libraylib.a)

target_link_libraries(Game PRIVATE ${CMAKE_SOURCE_DIR}/raylib/libraylib.a
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework OpenGL"
)