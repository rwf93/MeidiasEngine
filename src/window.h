#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

struct window
{
	SDL_Window* window;
	SDL_Event window_event;

	int running;
};

struct window* window_container;

void setup_window();
void handle_window_events();
void destroy_window();

#endif