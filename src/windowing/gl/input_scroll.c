#include "olafur.h"

void	scroll_callback(GLFWwindow *window, double x_offset, double y_offset)
{
	(void)window;
	(void)x_offset;
	if (y_offset > 0)
		increase_minimap_zoom(&g_man);
	else if (y_offset < 0)
		decrease_minimap_zoom(&g_man);
	return ;
}
