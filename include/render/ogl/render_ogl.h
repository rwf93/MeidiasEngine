#ifndef RENDER_OGL_H
#define RENDER_OGL_H
struct ogl_renderer_impl_context
{
	SDL_GLContext sdl_gl_context;
};

struct ogl_renderer_impl_context* render_context;

void render_opengl_setup();
void render_begin_ogl_frame();
void render_end_ogl_frame();
void render_opengl_destroy();

#endif // RENDER_USE_OPENGL