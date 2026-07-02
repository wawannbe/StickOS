# include <M5Unified.h>

# include <string>

# include "Window.h"
# include "Text.h"

Window::Window()
    : title("", 120, 0, TFT_GREY, TC_DATUM), icon("") {
}

Window::Window(std::string title, std::string icon)
    : title(title, 120, 0, TFT_GREY, TC_DATUM), icon(icon) {

    this->title.setVisible(true);

    this->addWidget(&this->title);
}

void Window::addWidget(Widget* widget) {
    this->widgets.push_back(widget);
}

void Window::show() {

    for (Widget* widget : this->widgets) {

        if (widget->isVisible) {
            widget->draw();
        }
    }
}

void Window::hide() {
    M5.Display.fillScreen(TFT_BLACK);
}