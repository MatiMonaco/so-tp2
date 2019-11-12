#ifndef VIDEO_VM_H
#define VIDEO_VM_H
void init_VM_Driver();
void pintarPantalla();
void drawPixel(unsigned int x, unsigned int y, int color);
unsigned int getScreenHeight();
unsigned int getScreenWidth();
void drawCharAt(int x, int y, char character, int fontColor, int backgroundColor);
unsigned int getFrameBuffer();
unsigned int getScreenBPP();
#endif