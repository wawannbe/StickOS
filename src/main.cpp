# include <M5Unified.h>
# include "SystemPower.h"

// ====================< System modules declaration >====================
    
SystemPower powerModule;

void setup() {

    // ====================< Config >====================

    auto cfg = M5.config();

    // setting some options to false by default to save power
    cfg.internal_imu = false; // gyro
    cfg.internal_spk = false; // speaker
    cfg.internal_mic = false; // microphone

    cfg.clear_display = true; // clears the display on boot
    
    M5.begin(cfg);


    // ====================< System modules initialisation >====================
    
    powerModule.init();

    // setting the screen to landscape mode
    M5.Display.setRotation(1);
    M5.Display.setBrightness(128);
    M5.Display.fillScreen(BLUE);
}

void loop() {
    M5.update();

    powerModule.update();

}