#include <stdio.h>
#include "window.h"
#include "util.h"

extern const char* g_AppName;

void setup_window()
{
	window_container = malloc(sizeof(struct window));
	memset(window_container, 0, sizeof(struct window));
	
	CHECK_ERROR(
		!(window_container->window = SDL_CreateWindow(
			g_AppName,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			800, 600,
			SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN)),
		"SDL_CreateWindow Failure %s\n", SDL_GetError());

	window_container->running = 1;
}


void handle_window_events()
{
	SDL_PollEvent(&window_container->window_event);

	switch (window_container->window_event.type)
	{
	case SDL_QUIT:
		printf("Closing Window");
		window_container->running = 0;
		break;
	}
}

void destroy_window()
{
	SDL_DestroyWindow(window_container->window);
	free(window_container);
}
