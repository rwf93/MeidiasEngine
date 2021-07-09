#include "stdafx.h"

#include "window.h"
#include "render.h"
#include "util.h"

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

    render_vulkan_setup();

    while (window_container->running)
    {
        handle_window_events();
    }

    render_vulkan_destroy();

    destroy_window();

    return 0;
}