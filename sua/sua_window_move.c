#include "sua.h"

void	sua_window_move(t_xvar *xvar, int x, int y)
{
	XMoveWindow(xvar->display, xvar->window, x, y);
	return ;
}
