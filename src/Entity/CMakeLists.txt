add_library(EntityLib STATIC Entity.c Entity.h)

target_link_libraries(EntityLib PUBLIC raylib)

target_include_directories(EntityLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})