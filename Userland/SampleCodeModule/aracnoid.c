#include <aracnoid.h>
#include <stdio.h>
#include <callSyscall.h>
static void render();
static void update();
static void loadLevel();
static void play();

static void keyHandler(char key);
static void checkBallCollisions();
static int checkRectCollision(Rectangle rec);
static void moveBall();
static void movePlayer();
static void renderWalls();

static uint64_t sleep(int ticks);


#define SCREEN_WIDTH getScreenWidth()
#define SCREEN_HEIGHT getScreenHeight()

#define DEFAULT_RECT_WIDTH  100
#define DEFAULT_RECT_HEIGHT 25
#define DEFAULT__PLAYER_X_POS  ((SCREEN_WIDTH / 2) - (DEFAULT_RECT_WIDTH) / 2)
#define DEFAULT__PLAYER_Y_POS (SCREEN_HEIGHT - DEFAULT_RECT_HEIGHT)
#define DEFAULT_PLAYER_COLOR 0xFFFFFF
#define DEFAULT_PLAYER_X_SPEED 20


#define DEFAULT_BALL_RADIUS 8
#define DEFAULT_BALL_COLOR 0xFFFFFF
#define DEFAULT_BALL_X_POS (DEFAULT__PLAYER_X_POS + (DEFAULT_RECT_WIDTH / 2))
#define DEFAULT_BALL_Y_POS (DEFAULT__PLAYER_Y_POS - (2 * DEFAULT_BALL_RADIUS))
#define DEFAULT_BALL_X_SPEED -9
#define DEFAULT_BALL_Y_SPEED -9

typedef struct PlayerStruct{
	Rectangle r;
	int xSpeed;
}Player;

typedef struct BallStruct{
	Circle c;
	int xSpeed;
	int ySpeed;
}Ball;

typedef struct WallStruct{
	Rectangle r;
	int hit ;
}Wall;

static Game game;
static Player player;
static Ball ball;
static uint64_t running = 0;
static  uint8_t RIGHT,LEFT;
static int rows = 3, cols = 3;
static Wall walls[3][3];




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

	running = 1;

	play();
}

static void loadLevel(){

	uint64_t colors[] = {0XFFFFFF,0xFF1111};
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols;j++){
			Rectangle r = {100 + i*200 + 100,100 + j*100 + 100,DEFAULT_RECT_HEIGHT,DEFAULT_RECT_WIDTH,colors[j%2]};
			Wall w = {r,0};
			 walls[i][j] = w;
		}
	}
}



static void play(){

		drawRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0x000000);

		update();
		loadLevel();
		while(running){
		char key;
			while((key = getchar()) != 'x'){
				//render();
				keyHandler(key);
				update();
				renderWalls();
				sleep(1);
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
	
	checkRectCollision(player.r);
	for(int i = 0; i< rows;i++){
		for(int j = 0; j < cols; j++){
				Wall wall = walls[i][j];
				int hit;
				if(wall.hit == 0){
					hit = checkRectCollision(wall.r);
					if(hit == 1){
						walls[i][j].hit = 1;
						drawRect(wall.r.x, wall.r.y, wall.r.width,wall.r.height,0x000000);
					}
				}
			
		}
		}
	return;
	
}
static void renderWalls(){
	for(int i = 0; i< rows;i++){
		for(int j = 0; j < cols; j++){
				Wall wall = walls[i][j];
				if(wall.hit == 0){
					drawRect(wall.r.x, wall.r.y, wall.r.width,wall.r.height,wall.r.color);
				}else{
					drawRect(wall.r.x, wall.r.y, wall.r.width,wall.r.height,0x000000);
				}
			
		}
	}
}

static int checkRectCollision(Rectangle rec){
	int ballX = ball.c.x;
	int ballY = ball.c.y;
	int radius = ball.c.radius;
	//UP AND DOWN
	if(ballX >= rec.x && ballX <= rec.x + rec.width){
		int isDown = (ballY + radius >= rec.y + rec.height) && (ballY - radius <= rec.y + rec.height);
		int isUp =  ballY - radius <= rec.y && ballY + radius >= rec.y ;
		if(isDown || isUp){
			ball.ySpeed *=-1;
			return 1;
		}
		
	}
	//LEFT AND RIGHT
	if(ballY >= rec.y && ballY <= rec.y + rec.height){
		int isLeft = (ballX - radius <= rec.x) && (ballX + radius >= rec.x);
		int isRight = (ballX + radius >= rec.x + rec.width) && (ballX - radius <= rec.x + rec.width);
		if(isLeft || isRight){
			ball.xSpeed *=-1;
			return 1;
		}
	
	}
	
	return 0;


}
static void movePlayer(){


	if(LEFT && player.r.x >  player.xSpeed){
		player.r.x -= player.xSpeed;
	
		int pos = player.r.x + player.r.width;
		drawRect(pos,player.r.y,player.xSpeed,player.r.height,0x000000);
		}
	if(RIGHT && player.r.x + player.r.width < SCREEN_WIDTH - player.xSpeed){
		player.r.x += player.xSpeed;
		
			int pos = player.r.x - player.xSpeed;
		drawRect(pos,player.r.y,player.xSpeed,player.r.height,0x000000);
	
	}
	drawRect(player.r.x, player.r.y, player.r.width,player.r.height,player.r.color);

}

static uint64_t sleep(int ticks){
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



