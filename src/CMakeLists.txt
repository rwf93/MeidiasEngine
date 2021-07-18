add_executable(${PROJECT_NAME}
	${INCLUDE_DIR}/stdafx.h

	${SOURCE_DIR}/main.c 

	${SOURCE_DIR}/window.c 
	${INCLUDE_DIR}/window.h

	${SOURCE_DIR}/render/ogl/render_ogl.c
	${INCLUDE_DIR}/render/ogl/render_ogl.h

	${INCLUDE_DIR}/util.h
)

source_group("Source Files/opengl/" FILES ${SOURCE_DIR}/render/ogl/render_ogl.c)
source_group("Header Files/opengl/" FILES ${INCLUDE_DIR}/render/ogl/render_ogl.h)

target_precompile_headers(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR}/stdafx.h)

target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:>
)
