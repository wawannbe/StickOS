# pragma once

# include <M5Unified.h>

/**
 * @brief Encapsulates some of the M5.Display functions related to shaped in order
 * to use them as widgets
 */

class Widget {

    protected:

        // The coordinates of the widget
        int x, y;

        /**
         * The color of the widget
         * 
         * If the widget is a text, it will be its color
         * 
         * If the widget is a shape, it will be it's border color
         */
        uint16_t color;

        // Boolean used to determine if the widget needs to be displayed
        bool isVisible;

    public:

        /**
         * @brief Constructor for the abstract class
         * 
         * @param x The x position of the widget
         * @param y The y position of the widget
         * @param color The color to apply  to the widget
         * @param isVisible The visibility of the widget
         */
        Widget(int x, int y, uint16_t color);

        /**
         * @brief Sets the visibility of the widget
         */
        virtual void setVisible(bool visibility) = 0;

        /**
         * @brief Draws the widget
         */
        virtual void draw() = 0;

        /**
         * @brief Fills the given widget with the given color
         * 
         * @param color The color to use for the fill
         * 
         * @note If the widget is a text, it will set the given color
         * as the text background
         */
        virtual void fill(uint16_t color) = 0;

};