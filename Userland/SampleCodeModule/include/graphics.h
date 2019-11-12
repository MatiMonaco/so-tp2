#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <stdint.h>


uint64_t drawRect(uint64_t x,uint64_t y,uint64_t width,uint64_t height,uint64_t color);
const uint64_t getScreenHeight();
const uint64_t getScreenWidth();
void clearScreen();


typedef struct rectangleStruct{
	uint64_t x,y,height,width,color;

}Rectangle;

typedef struct circleStruct{
	uint64_t x,y,radius,color;

}Circle;


#endif