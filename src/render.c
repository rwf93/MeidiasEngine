#include "stdafx.h"

#include "render.h"
#include "window.h"
#include "util.h"

extern const char* g_AppName;
extern const char* g_EngineName;
// used for instance and others (swapchain, device)
static void vk_setup_instance_extensions();
static void vk_setup_validation_layers();
static void vk_setup_instance();

void render_vulkan_setup()
{
	render_context = malloc(sizeof(struct vk_renderer_impl_context));
	CHECK_ERROR(!render_context,
		"Couldn't Allocate render_context");
	memset(render_context, 0, sizeof(render_context));
	

	vk_setup_instance_extensions();
	vk_setup_validation_layers();
	vk_setup_instance();
}

void vk_setup_instance_extensions()
{
	CHECK_ERROR(
		!SDL_Vulkan_GetInstanceExtensions(
			window_container->window,
			&render_context->instance_extensions_count,
			NULL),
		"SDL_Vulkan_GetInstanceExtensions failed (count) %s\n", SDL_GetError());

	CHECK_ERROR(
		!SDL_Vulkan_GetInstanceExtensions(
			window_container->window,
			&render_context->instance_extensions_count,
			&render_context->instance_extensions),
		"SDL_Vulkan_GetInstanceExtensions (instance_extensions) %s\n", SDL_GetError());
}

void vk_setup_validation_layers()
{
	const char* layers_we_want[] =
	{
		"VK_LAYER_KHRONOS_validation",
		"VK_LAYER_LUNARG_api_dump"
	};

	uint32_t instance_layer_count = 0;
	CHECK_ERROR(vkEnumerateInstanceLayerProperties(&instance_layer_count, NULL) != VK_SUCCESS,
		"Error at vkEnumerateInstanceLayerProperties (counting)");

	VkLayerProperties* instance_properties = malloc(sizeof(VkLayerProperties) * instance_layer_count);
	CHECK_ERROR(!instance_properties,
		"Couldn't allocate instance_properties");
	CHECK_ERROR(vkEnumerateInstanceLayerProperties(&instance_layer_count, instance_properties) != VK_SUCCESS,
		"vkEnumerateInstanceLayerProperties (instance properties)");

	for (uint32_t i = 0; i < ARRAY_SIZE(layers_we_want); i++)
	{
		uint32_t found = 0;
		for (uint32_t j = 0; j < instance_layer_count; j++)
		{
			if (!strcmp(layers_we_want[i], instance_properties[j].layerName))
			{
				found = 1;
				break;
			}
		}

		CHECK_ERROR(!found, 
			"Couldn't find validation layer %s", layers_we_want[i])
	}

	for (int i = 0; i < ARRAY_SIZE(layers_we_want); i++)
	{
		render_context->validation_layers[i] = (char*)layers_we_want[i];
	}
	
	render_context->validation_layers_count = ARRAY_SIZE(layers_we_want);

	free(instance_properties);
}

void vk_setup_instance()
{
	VkApplicationInfo app_info =
	{
		.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pNext = NULL,

		.pApplicationName = g_AppName,
		.applicationVersion = 1,

		.pEngineName = g_EngineName,
		.engineVersion = 1,
		.apiVersion = VK_API_VERSION_1_2,
	};

	VkInstanceCreateInfo instance_info =
	{
		.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.pNext = NULL,

		.flags = 0,

		.pApplicationInfo = &app_info,

		.enabledExtensionCount = render_context->instance_extensions_count,
		.ppEnabledExtensionNames = render_context->instance_extensions,

		.enabledLayerCount = render_context->validation_layers_count,
		.ppEnabledLayerNames = render_context->validation_layers,
	};

	CHECK_ERROR(vkCreateInstance(&instance_info, NULL, &render_context->instance) != VK_SUCCESS, 
		"vkCreateInstance Failure\n");
}

void render_vulkan_destroy()
{
	
	free(render_context);
}
