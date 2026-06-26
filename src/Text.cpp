# include <M5Unified.h>

# include <iostream>
# include <string>

# include "Text.h"

Text::Text(std::string text, int x, int y, uint16_t color, textdatum_t alignment) : Widget(x, y, color) {
    this->text = text;
    this->alignment = alignment;

    this->isVisible = false; // set to false by default to avoid NullPointer
}

void Text::setVisible(bool visibility) {
    this->isVisible = visibility;
}

void Text::draw() {

    textdatum_t oldDatum = M5.Display.getTextDatum(); // saving the system datum

    M5.Display.setTextColor(this->color); // changing to the item color
    M5.Display.setTextDatum(this->alignment); // changing to the item datum

    M5.Display.drawString(this->text.c_str(), this->x, this->y);

    M5.Display.setTextColor(TFT_WHITE); // restoring the system color
    M5.Display.setTextDatum(oldDatum); // restoring the system datum
}

void Text::fill(uint16_t color) {

    textdatum_t oldDatum = M5.Display.getTextDatum(); // saving the system datum

    M5.Display.setTextColor(this->color, color); // changing to the item color
    M5.Display.setTextDatum(this->alignment); // changing to the item datum

    M5.Display.drawString(this->text.c_str(), this->x, this->y);

    M5.Display.setTextColor(TFT_WHITE, TFT_BLACK); // restoring the system color
    M5.Display.setTextDatum(oldDatum); // restoring the system datum
}