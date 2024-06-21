#include <Wire.h>
#include <U8g2lib.h>

// U8g2 constructor for SH1106
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  u8g2.drawStr(0, 10, "Hello, world!");
  u8g2.sendBuffer();
  delay(2000); // Pause for 2 seconds
}

void loop() {
  scrollText("Scrolling Text Demo!");
}

void scrollText(const char* text) {
  int16_t textWidth = u8g2.getStrWidth(text);
  for(int16_t x = u8g2.getDisplayWidth(); x >= -textWidth; x--) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(x, (u8g2.getDisplayHeight() / 2), text); // Centered vertically
    u8g2.sendBuffer();
    delay(50); // Adjust delay for scrolling speed
  }
}
