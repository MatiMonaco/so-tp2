#ifndef SCREENDRIVER_H
#define SCREENDRIVER_H

#include <stdint.h>
void drawChar(char character,int fontColor, int backgroundColor);
void newline();
void deleteChar();
void drawString(const char *string);
void drawStringWithColor(const char *string, int fontColor, int backgroundColor);
uint64_t drawRect(unsigned int x, unsigned int y,unsigned int width, unsigned int height, int color);
unsigned int getScreenWidth();
unsigned int getScreenHeight();
uint64_t drawCircle(unsigned int x, unsigned int y, int radius, int color);
#endif