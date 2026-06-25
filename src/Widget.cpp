# include <M5Unified.h>
# include "Widget.h"

Widget::Widget(int x, int y, uint16_t color) {
    this->x = x;
    this->y = y;

    this->color = color;

    this->isVisible = false; // visibility is set to false by default
}