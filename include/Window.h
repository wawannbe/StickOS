# pragma once

# include <iostream>
# include <string>

# include <vector>

# include <M5Unified.h>

# include "Widget.h"
# include "Text.h"

/**
 * @brief Manages the Windows for the WindowManager class to hold the widgets
 */
class Window {


    public:

        Window(const Window&) = delete; // No by-copy constructor
        Window& operator = (const Window&) = delete; // No by-copy affectation
        Window(Window&&) = delete; // No by-move constructor
        Window& operator = (Window&&) = delete; // No by-move affectation

        // The title of the window displayed at the top of the screen
        Text title;

        // The path of the icon of the window displayed in the menu
        std::string icon;

        // Default constructor
        Window();

        /**
         * @brief Constructor to create a new window
         * 
         * @param title The title to use for the window
         * @param icon The path to use for the icon
         */
        Window(std::string title, std::string icon);

        /**
         * @brief Adds a widget to the list of widgets of the window in order to be rendered
         * 
         * @param widget The widget to add into the window
         */
        void addWidget(Widget* widget);
        
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

        // The widgets the window contains
        std::vector<Widget*> widgets;
};