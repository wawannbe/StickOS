# include <M5Unified.h>

# include "SystemPower.h"

# include "Widget.h"
# include "Text.h"

# include "Window.h"

// ====================< System modules declaration >====================
    
SystemPower powerModule;
Window winTest("Test", "");

void setup() {

    // ====================< Config >====================

    auto cfg = M5.config();

    cfg.internal_imu = false; // gyro
    cfg.internal_spk = true; // speaker
    cfg.internal_mic = false; // microphone

    cfg.clear_display = true; // clears the display on boot
    
    M5.begin(cfg);


    // ====================< System modules initialisation >====================
    
    powerModule.init();

    // setting the screen to landscape mode
    M5.Display.setRotation(1);
    M5.Display.setBrightness(128);
    M5.Display.setFont(&fonts::Font0);

    M5.Display.setTextColor(TFT_WHITE, TFT_BLACK); 
    M5.Display.setTextDatum(MC_DATUM);
}

void loop() {
    M5.update();

    powerModule.update();

    winTest.show();
}