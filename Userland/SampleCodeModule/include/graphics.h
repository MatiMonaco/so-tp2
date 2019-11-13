#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <stdint.h>


uint64_t drawRect(uint64_t x,uint64_t y,uint64_t width,uint64_t height,uint64_t color);
const uint64_t getScreenHeight();
const uint64_t getScreenWidth();
void init();
uint64_t drawCircle(uint64_t x,uint64_t y,uint64_t radius,uint64_t color);
typedef struct rectangleStruct{
	int x,y,height,width,color;

}Rectangle;

typedef struct circleStruct{
	int x,y,color;
	int radius;

}Circle;


#endif