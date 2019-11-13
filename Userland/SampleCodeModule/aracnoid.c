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
static void clearScreen();

static uint64_t sleep(uint64_t ticks);


#define SCREEN_WIDTH getScreenWidth()
#define SCREEN_HEIGHT getScreenHeight()

#define DEFAULT_RECT_WIDTH  100
#define DEFAULT_RECT_HEIGHT 25
#define DEFAULT__PLAYER_X_POS  ((SCREEN_WIDTH / 2) - (DEFAULT_RECT_WIDTH) / 2)
#define DEFAULT__PLAYER_Y_POS (SCREEN_HEIGHT - DEFAULT_RECT_HEIGHT)
#define DEFAULT_PLAYER_COLOR 0xFFFFFF
#define DEFAULT_PLAYER_X_SPEED 20


#define DEFAULT_BALL_RADIUS 5
#define DEFAULT_BALL_COLOR 0xFFFFFF
#define DEFAULT_BALL_X_POS (DEFAULT__PLAYER_X_POS + (DEFAULT_RECT_WIDTH / 2))
#define DEFAULT_BALL_Y_POS (DEFAULT__PLAYER_Y_POS - (DEFAULT_BALL_RADIUS))
#define DEFAULT_BALL_X_SPEED -10
#define DEFAULT_BALL_Y_SPEED -10

typedef struct PlayerStruct{
	Rectangle r;
	int xSpeed;
}Player;

typedef struct BallStruct{
	Circle c;
	int xSpeed;
	int ySpeed;
}Ball;

static Game game;
static Player player;
static Ball ball;
static uint64_t running = 0;
static  uint8_t RIGHT,LEFT;



static void clearScreen(){
	drawRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0x000000);
}


void newGame(){
	player.r.x = DEFAULT__PLAYER_X_POS;
	player.r.y = DEFAULT__PLAYER_Y_POS;
	player.r.width =DEFAULT_RECT_WIDTH;
	player.r.height = DEFAULT_RECT_HEIGHT;
	player.r.color = DEFAULT_PLAYER_COLOR;
	player.xSpeed = (int)DEFAULT_PLAYER_X_SPEED;

	ball.c.radius = (int)DEFAULT_BALL_RADIUS;
	ball.c.x = DEFAULT_BALL_X_POS;
	ball.c.y = DEFAULT_BALL_Y_POS;
	ball.c.color = DEFAULT_BALL_COLOR;
	ball.xSpeed = (int)DEFAULT_BALL_X_SPEED;
	ball.ySpeed = (int)DEFAULT_BALL_Y_SPEED;
	init();
	loadLevel();
	running = 1;
	clearScreen();
	play();
}

static void loadLevel(){

}



static void play(){
		while(running){
		char key;
			while((key = getchar()) != 'x' && key != 0){
				//render();
				keyHandler(key);
				update();
				
				//sleep(1);
			}
			
		}
}

static void keyHandler(char key){
	
			if(key == 'a' || key == 'A'){
					LEFT = 1;
					RIGHT = 0;
				//player.r.x -= player.xSpeed;
				}else if(key == 'd' || key == 'D'){
					RIGHT = 1;
					LEFT = 0;
					//player.r.x += player.xSpeed;
				}else if(key == 'r' || key =='R'){
					newGame();
				}else{
					RIGHT = 0;
					LEFT = 0;
				}
				
	

}

static void update(){
		moveBall();
		movePlayer();
	/*	if(ball.c.y + ball.c.radius >= SCREEN_HEIGHT){
			running = 0;
		}*/
		
		
}

static void render(){
	//drawRect(player.r.x,player.r.y,player.r.width,player.r.height,player.r.color);
	drawCircle(ball.c.x, ball.c.y, ball.c.radius, ball.c.color);
}

static void moveBall(){
		drawCircle(ball.c.x, ball.c.y, ball.c.radius, 0x000000);
		if(ball.c.y - ball.c.radius <= 0){
			ball.c.y = ball.c.radius;
			ball.ySpeed *= -1;
		}
		if(ball.c.x - ball.c.radius <= 0){
			ball.c.x = ball.c.radius;
			ball.xSpeed *=-1;
		}else if(ball.c.x + ball.c.radius > SCREEN_WIDTH){
			ball.c.x = SCREEN_WIDTH - ball.c.radius;
			ball.xSpeed *=-1;
		}
		checkBallCollisions();
		ball.c.x += ball.xSpeed;
		ball.c.y += ball.ySpeed;
		drawCircle(ball.c.x, ball.c.y, ball.c.radius, ball.c.color);

		
}

static void checkBallCollisions(){
	return;
}

static void movePlayer(){


	if(LEFT && player.r.x >  player.xSpeed){
		player.r.x -= player.xSpeed;
		drawRect(player.r.x, player.r.y, player.r.width,player.r.height,player.r.color);
		int pos = player.r.x + player.r.width;
		drawRect(pos,player.r.y,player.xSpeed,player.r.height,0x000000);
	}
	if(RIGHT && player.r.x + player.r.width < SCREEN_WIDTH - player.xSpeed){
		player.r.x += player.xSpeed;
		drawRect(player.r.x, player.r.y, player.r.width,player.r.height,player.r.color);
		int pos = player.r.x - player.xSpeed;
		drawRect(pos,player.r.y,player.xSpeed,player.r.height,0x000000);
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



