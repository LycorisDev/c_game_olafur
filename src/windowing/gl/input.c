#include "olafur.h"

void		physical_key_callback(GLFWwindow *window, int key, int scancode,
				int action, int mods);
void		scroll_callback(GLFWwindow *window, double x_offset,
				double y_offset);
void		mouse_callback(GLFWwindow *window, int button, int action,
				int mods);
void		cursor_pos_callback(GLFWwindow *window, double xpos, double ypos);

static void	focus_callback(GLFWwindow* window, int focused);

void	init_input_handling(t_man *man)
{
	set_ivec2(&man->cursor, -1, -1);
	init_input_keys(man);
	glfwSetKeyCallback(man->window, physical_key_callback);
	glfwSetInputMode(man->window, GLFW_LOCK_KEY_MODS, GLFW_TRUE);
	glfwSetScrollCallback(man->window, scroll_callback);
	glfwSetMouseButtonCallback(man->window, mouse_callback);
	glfwSetCursorPosCallback(man->window, cursor_pos_callback);
	glfwSetWindowFocusCallback(man->window, focus_callback);
	return ;
}

/* This isn't triggered when grabbing the window decoration */
static void	focus_callback(GLFWwindow* window, int focused)
{
	(void)window;
	if (!focused)
		cancel_keys_in_game_state(&g_man);
	return ;
}
