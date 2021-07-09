set(SDL2_INSTALL_DIR ${CMAKE_BINARY_DIR}/thirdparty/SDL)
set(SDL2_INCLUDE_DIR ${SDL2_INSTALL_DIR}/include)
set(SDL2_LINK_DIR ${SDL2_INSTALL_DIR}/lib)
set(SDL2_BIN_DIR ${SDL2_INSTALL_DIR}/bin)


ExternalProject_Add(SDL2
    PREFIX ${SDL2_INSTALL_DIR}
    URL "https://www.libsdl.org/release/SDL2-2.0.14.tar.gz"
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX:PATH=${SDL2_INSTALL_DIR}
)

add_custom_command(
        TARGET SDL2 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${SDL2_BIN_DIR}/SDL2d.dll
                ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/SDL2d.dll)

include_directories(${SDL2_INCLUDE_DIR})
add_dependencies(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} ${SDL2_LINK_DIR}/SDL2d.lib)
target_link_libraries(${PROJECT_NAME} ${SDL2_LINK_DIR}/SDL2maind.lib)