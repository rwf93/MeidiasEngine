#include <stdafx.h>
#include <window.h>

#include <render/ogl/render_ogl.h>

static void render_setup_attributes();
static void render_setup_sdl_context();
static void render_setup_glew();
static void render_setup_shaders();

void render_opengl_setup()
{
	render_context = malloc(sizeof(struct ogl_renderer_impl_context));
	CHECK_ERROR(!render_context,
		"Failed to allocate render_context\n");
	memset(render_context, 0, sizeof(render_context));

	render_setup_attributes();
	render_setup_sdl_context();
	render_setup_glew();
	render_setup_shaders();
}

void render_begin_ogl_frame()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void render_end_ogl_frame()
{
	SDL_GL_SwapWindow(window_container->window);
}

void render_setup_attributes()
{
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
}

void render_setup_sdl_context()
{
	CHECK_ERROR(!(render_context->sdl_gl_context = SDL_GL_CreateContext(window_container->window)),
		"Failed to get sdl_gl_context %s\n", SDL_GetError());
}

void render_setup_glew()
{
	glewInit();
}

void render_setup_shaders()
{

}

void render_opengl_destroy()
{
	SDL_GL_DeleteContext(render_context->sdl_gl_context);
	free(render_context);
}