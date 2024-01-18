#include "./includes/header.h"

void    flat_view(t_hooks *hooks)
{
    hooks->base_cartis[0] = 1;
    hooks->base_cartis[1] = 0;
    hooks->base_cartis[2] = 0;
    hooks->base_cartis[3] = 1;
    hooks->base_cartis[4] = 0;
    hooks->base_cartis[5] = 0;
}

void    iso_view(t_hooks *hooks)
{
    hooks->base_cartis[0] = .8;
	hooks->base_cartis[1] = .333;
	hooks->base_cartis[2] = -.8;
	hooks->base_cartis[3] = .333;
	hooks->base_cartis[4] = 0;
	hooks->base_cartis[5] = -.8;
}