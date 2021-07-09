set(TLIB_INSTALL_DIR ${CMAKE_BINARY_DIR}/thirdparty/TeeLib)
set(TLIB_INCLUDE_DIR ${TLIB_INSTALL_DIR}/include)

ExternalProject_Add(TeeLib
    PREFIX ${TLIB_INSTALL_DIR}
    GIT_REPOSITORY "https://github.com/EclipseLord/TeeLib"
    CMAKE_ARGS 
        -DCMAKE_INSTALL_PREFIX:PATH=${TLIB_INSTALL_DIR}
)

include_directories(${TLIB_INCLUDE_DIR})
add_dependencies(${PROJECT_NAME} TeeLib)