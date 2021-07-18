#ifndef RENDER_VK_H
#define RENDER_VK_H

#define VK_USE_PLATFORM_WIN32_KHR
#include <vulkan/vulkan.h>

struct vk_renderer_impl_context
{
	VkInstance instance;
	VkPhysicalDevice physical_device;
	VkDevice device;
	VkSurfaceKHR surface;
	VkSwapchainKHR swapchain;

	const char* instance_extensions[64];
	uint32_t instance_extensions_count;

	char* validation_layers[64];
	uint32_t validation_layers_count;
	
	char* device_extensions[64];
	uint32_t device_extensions_count;
};

struct vk_renderer_impl_context* render_context;

void render_vulkan_setup();
void render_vulkan_destroy();

#endif // !RENDER_H
