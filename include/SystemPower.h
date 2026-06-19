# pragma once

/**
 * @brief Manages the power and the sleep of the device
 */
class SystemPower {

    private:
        const int MAX_CHARGING_POWER = 100;
        const int LED_BRIGHTNESS = 128;

        unsigned long lastActionTime;

    public:
        /**
         * @brief Initialises the power module to the max charging power value in mAh
         * This is set to 100mAh by default to avoid device heating during long periods of time plugged
         * 
         * @note Needs to be called once in the setup()
         */
        void init();

        /**
         * @brief Turns on the Integrated LED of the board (GPIO10) if the device is charging
         * Powers off the device if its battery goes below 3.5v
         * Calls the sleepCheck(delay) function
         * 
         * @note Needs to be called in the loop()
         */
        void update();

        /**
         * @brief Puts the device in light sleep mode if no buttons have been used since the given delay
         * 
         * @param delayMs The delay after which the device will enter in sleep mode
         * Increasing this delay will increase battery usage
         * 
         * @note Automatically called in the update() function
         */
        void sleepCheck(unsigned long delayMs);
};