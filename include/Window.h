# pragma once

# include <iostream>
# include <string>

# include <M5Unified.h>

# include "Widget.h"

/**
 * @brief Manages the Windows for the WindowManager class to hold the widgets
 */
class Window {


    public:

        // The title of the window displayed at the top of the screen
        std::string title;

        // The icon of the window displayed in the menu
        std::string icon;

        /**
         * @brief Adds a widget to the list of widgets of the window in order to be rendered
         * 
         * @param widget The widget to add into the window
         */
        void addWidget(Widget widget);
        
        /**
         * @brief Renders the window and displays the widgets
         * 
         * @note This will only render the widgets with their visibility set to true
         */
        void show();

        /**
         * @brief Hides the window from the screen
         */
        void hide();

    private:

        static const int MAX_WIDGETS = 10;
        Widget* widgets[MAX_WIDGETS];
};