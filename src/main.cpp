#include <M5Unified.h>

void setup() {
    auto cfg = M5.config();
    cfg.internal_imu = true;
    M5.begin(cfg);

    M5.Display.setRotation(1);
    M5.Display.setTextSize(1);
    M5.Display.print("Hello Plus!");
}

void loop() {
    M5.update();
}