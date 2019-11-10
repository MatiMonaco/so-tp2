#ifndef SCREEN_DRIVER_H
#define SCREEN_DRIVER_H
#include <stdint.h>
void drawChar(char character,int fontColor, int backgroundColor);
void newline();
void deleteChar();
void drawString(const char *string);
void drawStringWithColor(const char *string, int fontColor, int backgroundColor);
void drawDec(uint64_t value);
void drawHexa(uint64_t value);
#endif