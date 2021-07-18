#include <stdafx.h>

#include <window.h>

#include <render/ogl/render_ogl.h>

// REQUIRED BY SDL AND VULKAN
const char* g_AppName = "Meidias";
const char* g_EngineName = "MeidiasEngine";

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("SDL Failed to init %s\n", SDL_GetError());
        exit(1);
    }

    setup_window();

    render_opengl_setup();

    while (window_container->running)
    {

        render_begin_ogl_frame();

        render_end_ogl_frame();

        handle_window_events();
    }

    render_opengl_destroy();

    destroy_window();

    return 0;
}