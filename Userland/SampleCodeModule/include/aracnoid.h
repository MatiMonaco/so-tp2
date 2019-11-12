#ifndef ARACNOID_H
#define ARACNOID_H
#include <stdio.h>
#include <graphics.h>

typedef struct GameStruct{
	Rectangle  player;
	Circle ball;
	uint64_t time;
	uint64_t xspeed,yspeed;


}Game;

void start();
//GameStruct save();
void load(Game *  save);

#endif