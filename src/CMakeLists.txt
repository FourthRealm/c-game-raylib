# Raylib
set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/raylib")
add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES
    IMPORTED_LOCATION "${RAYLIB_DIR}/libraylib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${RAYLIB_DIR}"
)

# Main executable
add_executable(Game main.c)

# Include raylib headers
target_include_directories(Game PRIVATE ${RAYLIB_INCLUDE_DIR})

# Link modules and raylib
target_link_libraries(Game PRIVATE
    raylib 
    ${RAYLIB_LIBRARY}
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
    "-framework OpenGL"
)