#include <iostream>
using namespace std;

//prototypes
void setup();
void draw();
void input();
void logic();

//variables
bool gameOver;
int x;
int y;
int fruitX;
int fruitY;
int score;

//size of the play field
const int WIDTH = 20;
const int HEIGHT = 20;

//enumarations
enum direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
direction dir;


int main() {
	setup();
	
	while (!gameOver) {
		draw();
		input();
		logic();
	}


	return 0;
}

void setup() {
	gameOver = false;
	dir = STOP;

	//place snake in the middle of the map
	x = WIDTH / 2;
	y = HEIGHT / 2;
	fruitX = rand() % WIDTH;
	fruitY = rand() % HEIGHT;

}

void draw() {
	system("cls"); //this clears the console
	
	for (int top = 0; top < WIDTH+1; top++) {
		cout << "#";
	}
	cout << endl;

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (x == 0)
				cout << "#";
			else
				cout << " ";

			if (x == WIDTH - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int bot = 0; bot < WIDTH+1; bot++) {
		cout << "#";
	}
	cout << endl;

}

void input() {


}

void logic() {


}