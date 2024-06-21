#include <Wire.h>
#include <U8g2lib.h>

// U8g2 constructor for SH1106
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
  displayCenteredText("Anonymouse (-:");
  u8g2.sendBuffer();
  delay(2000); // Pause for 2 seconds
}

void loop() {
  scrollTextLarge("UsamaHacker0!");
}

void displayCenteredText(const char* text) {
  int16_t textWidth = u8g2.getStrWidth(text);
  int16_t x = (u8g2.getDisplayWidth() - textWidth) / 2;
  int16_t y = (u8g2.getDisplayHeight() / 2) + 8; // Adjust vertical position
  
  for (size_t i = 0; i <= strlen(text); i++) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(x, y, text);
    u8g2.sendBuffer();
    delay(150); // Adjust delay for letter appearance speed
    textWidth = u8g2.getStrWidth(text);
    x = (u8g2.getDisplayWidth() - textWidth) / 2;
  }
}

void scrollTextLarge(const char* text) {
  int16_t textWidth = u8g2.getStrWidth(text) * 3; // Adjusting for larger font size
  for(int16_t x = u8g2.getDisplayWidth(); x >= -textWidth; x--) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB14_tr); // choose a suitable larger font
    u8g2.drawStr(x, (u8g2.getDisplayHeight() / 2) + 8, text); // Centered vertically
    u8g2.sendBuffer();
    delay(50); // Adjust delay for scrolling speed
  }
}
