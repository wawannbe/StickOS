# include <M5Unified.h>
# include <SystemPower.h>

void SystemPower::init() {

    // limiting the mA to avoid heating and preserve battery life, do not exceed 190mAh
    M5.Power.setChargeCurrent(100);
}

void SystemPower::update() {

    if (M5.Power.isCharging()) {
        M5.Power.setLed(128); // ~half the power to limit battery usage and heating

    } else {
        M5.Power.setLed(0);

        // powers off the device if the battery level reaches below 3.5v
        if (M5.Power.getBatteryVoltage() < 3500) {
            M5.Power.powerOff();
        }
    }
}
