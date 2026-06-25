# pragma once

# include <M5Unified.h>

# include <iostream>
# include <string>

// Importing the parent class
# include "Widget.h"

/**
 * @brief Handles the text stuff
 * 
 * Heritates of the Widget abstract class
 */
class Text : public Widget {

    protected:

        // The content of the text field
        std::string text;

        // The text anchor
        textdatum_t alignment;
    
    public:

        /**
         * @brief Constructor of the text widget
         * 
         * @param x The x position of the text widget
         * @param y The y position of the text widget
         * @param alignment The datum to set in order to anchor the text
         */
        Text(std::string text, int x, int y, uint16_t color, textdatum_t alignment);

        /**
         * @brief Overrides the setVisible() function from the Widget class
         */
        void setVisible(bool visibility) override;

        /**
         * @brief Overrides the draw() function from the Widget class
         */
        void draw() override;

        /**
         * @brief Overrides the fill() function from the Widget class
         */
        void fill(uint16_t color) override;

};