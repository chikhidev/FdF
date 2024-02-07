#include "includes/extra.h"

t_color parse_int(int color) {
    t_color c;

    c.r = (color >> 16) & 0xFF;
    c.g = (color >> 8) & 0xFF;
    c.b = color & 0xFF;
    return c;
}

int convert_color(t_color c) {
    return (c.r << 16 | c.g << 8 | c.b);
}

void draw_background(t_hooks *hooks) {
    int i;
    int j;
    t_color c = parse_int(BACKGROUND_TOP);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            c.r -= 0.0001;
            c.g -= 0.0001;
            c.b -= 0.0001;
            put_the_pixel(&hooks->img, j, i, convert_color(c));
        }
    }
}
