#include <aracnoid.h>
#include <stdio.h>
#include <callSyscall.h>
static void render();
static void update();
static void loadLevel();
static void play();

static void keyHandler(char key);
static void checkBallCollisions();
static void moveBall();
static void movePlayer();

static uint64_t sleep(uint64_t ticks);


#define SCREEN_WIDTH getScreenWidth()
#define SCREEN_HEIGHT getScreenHeight()

#define DEFAULT_RECT_WIDTH  100
#define DEFAULT_RECT_HEIGHT 25
#define DEFAULT__PLAYER_X_POS  ((SCREEN_WIDTH / 2) - (DEFAULT_RECT_WIDTH) / 2)
#define DEFAULT__PLAYER_Y_POS (SCREEN_HEIGHT - DEFAULT_RECT_HEIGHT)
#define DEFAULT_PLAYER_COLOR 0xFFFFFF
#define DEFAULT_PLAYER_X_SPEED 20


#define DEFAULT_BALL_RADIUS 25
#define DEFAULT_BALL_COLOR 0xFF0000
#define DEFAULT_BALL_X_POS (DEFAULT__PLAYER_X_POS + (DEFAULT_RECT_WIDTH / 2))
#define DEFAULT_BALL_Y_POS (DEFAULT__PLAYER_Y_POS - (DEFAULT_BALL_RADIUS / 2))
#define DEFAULT_BALL_X_SPEED 5
#define DEFAULT_BALL_Y_SPEED -5

typedef struct PlayerStruct{
	Rectangle r;
	uint64_t xSpeed;
}Player;

typedef struct BallStruct{
	Circle c;
	uint64_t xSpeed;
	uint64_t ySpeed;
}Ball;

static Game game;
static Player player;
static Ball ball;
static uint64_t running = 0;
static  uint8_t RIGHT,LEFT;



void newGame(){
	player.r.x = DEFAULT__PLAYER_X_POS;
	player.r.y = DEFAULT__PLAYER_Y_POS;
	player.r.width =DEFAULT_RECT_WIDTH;
	player.r.height = DEFAULT_RECT_HEIGHT;
	player.r.color = DEFAULT_PLAYER_COLOR;
	player.xSpeed = DEFAULT_PLAYER_X_SPEED;

	ball.c.radius = DEFAULT_BALL_RADIUS;
	ball.c.x = DEFAULT_BALL_X_POS;
	ball.c.y = DEFAULT_BALL_Y_POS;
	ball.c.color = DEFAULT_BALL_COLOR;
	ball.xSpeed = DEFAULT_BALL_X_SPEED;
	ball.ySpeed = DEFAULT_BALL_Y_SPEED;
	init();
	loadLevel();
	running = 1;
	play();
}

static void loadLevel(){

}



static void play(){
		while(running){
		char key;
			while((key = getchar()) != 'x'){
				keyHandler(key);
				update();
				render();
				//sleep(1);
			}
			
		}
}

static void keyHandler(char key){
	/*
			if(key == 'a' || key == 'A'){
					LEFT = 1;
					RIGTH = 0;
				}else if(key == 'd' || key == 'D'){
					RIGHT = 1;
					LEFT = 0;
				}else if(key == 'r' || key =='R'){
					newGame();
				}else{
					RIGHT = 0;
					LEFT = 0;
				}
				*/
	

}

static void update(){
	//	moveBall();
		movePlayer();
	/*	if(ball.c.y + ball.c.radius >= SCREEN_HEIGHT){
			running = 0;
		}*/
		
		
}

static void render(){
	clearScreen();
	drawRect(player.r.x,player.r.y,player.r.width,player.r.height,player.r.color);


}

static void moveBall(){

		if(ball.c.y - ball.c.radius < 0){
			ball.c.y = 0;
			ball.ySpeed *= -1;
		}
		if(ball.c.x < 0){
			ball.c.x = 0;
			ball.xSpeed *=-1;
		}else if(ball.c.x + ball.c.radius > SCREEN_WIDTH){
			ball.c.x = SCREEN_WIDTH - ball.c.radius;
			ball.xSpeed *=-1;
		}
		checkBallCollisions();
		ball.c.x += ball.xSpeed;
		ball.c.y += ball.ySpeed;
}

static void checkBallCollisions(){
	return;
}

static void movePlayer(){
	if(LEFT && player.r.x > 0){
		player.r.x -= player.xSpeed;
	}
	if(RIGHT && player.r.x + player.r.width < SCREEN_WIDTH){
		player.r.x += player.xSpeed;
	}
}

static uint64_t sleep(uint64_t ticks){
	return callSyscall(SLEEP,(void*)ticks,(void*)0,(void*)0,(void*)0,(void*)0,(void*)0);

}
/*
Game save(){

	return  game;
}

void load(Game *  save){
	return;
}
*/



