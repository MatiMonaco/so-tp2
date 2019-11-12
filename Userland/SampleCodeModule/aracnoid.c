#include <aracnoid.h>

static void render();
static void update();
static void loadLevel();
static void play();
static void keyHandler();

#define SCREEN_WIDTH getScreenWidth()
#define SCREEN_HEIGHT getScreenHeight()

#define DEFAULT_RECT_WIDTH 30
#define DEFAULT_RECT_HEIGHT 15
#define DEFAULT__PLAYER_X_POS  ((SCREEN_WIDTH / 2) - (DEFAULT_RECT_WIDTH) / 2)
#define DEFAULT__PLAYER_Y_POS (SCREEN_HEIGHT - DEFAULT_RECT_HEIGHT)
#define DEFAULT_PLAYER_COLOR 0xFFFFFF


#define DEFAULT_BALL_RADIUS 10
#define DEFAULT_BALL_COLOR 0xFF0000
#define DEFAULT_BALL_X_POS (DEFAULT__PLAYER_X_POS + (DEFAULT_RECT_WIDTH / 2))
#define DEFAULT_BALL_Y_POS (DEFAULT__PLAYER_Y_POS - (DEFAULT_BALL_RADIUS / 2))






static Game game;
static Rectangle player;
static Circle ball;
static uint64_t running = 0;

void newGame(){
	player.x = DEFAULT__PLAYER_X_POS;
	player.y = DEFAULT__PLAYER_Y_POS;
	player.width =DEFAULT_RECT_WIDTH;
	player.height = DEFAULT_RECT_HEIGHT;
	player.color = DEFAULT_PLAYER_COLOR;

	ball.radius = DEFAULT_BALL_RADIUS;
	ball.x = DEFAULT_BALL_X_POS;
	ball.y = DEFAULT_BALL_Y_POS;
	ball.color = DEFAULT_BALL_COLOR;

	loadLevel();
	running = 1;
	play();
}

static void loadLevel(){

}



static void play(){
		while(running){
			keyHandler();
			update();
			render();
		}
}

static void keyHandler(){



}

static void update(){

}

static void render(){

}


Game save(){

	return  game;
}
void load(Game *  save){

}




