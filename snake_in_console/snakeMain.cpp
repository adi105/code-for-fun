#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
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
int tailX[100];
int tailY[100];
int tailLength = 0;

//size of the play field
const int WIDTH = 25;
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
		Sleep(50);
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

	for (int top = 0; top < WIDTH + 2; top++) {
		cout << setw(2) << "#";
	}
	cout << endl;

	for (int yCoord = 0; yCoord < HEIGHT; yCoord++) {
		for (int xCoord = 0; xCoord < WIDTH; xCoord++) {
			if (xCoord == 0)
				cout << setw(2) << "#";
			//prints the snake's position
			if (yCoord == y && xCoord == x)
				cout << setw(2) << "O";
			//prints the fruit
			else if (yCoord == fruitY && xCoord == fruitX)
				cout << setw(2) << "F";
			else {
				bool print = false;
				for (int t = 0; t < tailLength; t++) {
					if (tailX[t] == xCoord && tailY[t] == yCoord) {
						cout << setw(2) << "o";
						print = true;
					}
				}
				if (!print) {
					cout << setw(2) << " ";
				}
			}

			if (xCoord == WIDTH - 1)
				cout << setw(2) << "#";
		}
		cout << endl;
	}

	for (int bot = 0; bot < WIDTH + 2; bot++) {
		cout << setw(2) << "#";
	}
	cout << endl;
	cout << "Score:" << score << endl;

}

void input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void logic() {
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < tailLength; i++) {
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir) {

	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0) {
		gameOver = true;
	}
	for (int i = 0; i < tailLength; i++) {
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % WIDTH;
		fruitY = rand() % HEIGHT;
		tailLength++;
	}
}