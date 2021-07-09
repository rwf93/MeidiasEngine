add_executable(${PROJECT_NAME}
	${SOURCE_DIR}/stdafx.h

	${SOURCE_DIR}/main.c 

	${SOURCE_DIR}/window.c 
	${SOURCE_DIR}/window.h

	${SOURCE_DIR}/render.c 
	${SOURCE_DIR}/render.h

	${SOURCE_DIR}/util.h
)

target_precompile_headers(${PROJECT_NAME} PRIVATE ${SOURCE_DIR}/stdafx.h)

target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/wd5105 /wd5103 /wd4026 /wd4706 /wd4047 /wd4024 /W4 /WX>
)
