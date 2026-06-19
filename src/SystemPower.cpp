# include <M5Unified.h>
# include <SystemPower.h>

void SystemPower::init() {

    M5.Power.setChargeCurrent(MAX_CHARGING_POWER);
}

void SystemPower::update() {

    if (M5.Power.isCharging()) {
        M5.Power.setLed(LED_BRIGHTNESS);

    } else {
        M5.Power.setLed(0);

        int level = M5.Power.getBatteryVoltage();

        if ( level > 2500 && level < 3300) {
            M5.Power.powerOff();
        }
    }

    sleepCheck(10000); // delay set to 3s for developpment
}

void SystemPower::sleepCheck(unsigned long delayMs) {

    if (M5.BtnA.isReleased() && M5.BtnB.isReleased()) {
        
        if (millis() - lastActionTime > delayMs) {
            M5.Display.setBrightness(0);
            M5.Display.sleep();

            gpio_wakeup_enable(GPIO_NUM_37, GPIO_INTR_LOW_LEVEL);
            gpio_wakeup_enable(GPIO_NUM_39, GPIO_INTR_LOW_LEVEL);
            esp_sleep_enable_gpio_wakeup();
            
            esp_light_sleep_start();

            M5.Display.wakeup();
            M5.Display.setBrightness(128);

            lastActionTime = millis();
        }

    } else {
        lastActionTime = millis();
    }
}
