#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;

// 맵 크기
const int width = 30;
const int height = 10;
int x, y, fruitX, fruitY, score;
enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};
eDirection dir;


// 전체적인 구성
void Setup()
{
	gameOver = false;
	// snake의 시작은 중간부터 시작
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
enum GameSelect
{
	GAME_NONE,
	GAME_EASY,
	GAME_NORMAL,
	GAME_HARD
};

/*
	맵 형태:
	#####
	#   #
	#####
*/
void Draw()
{
	system("cls");
	// top wall
	for (int i = 0; i < width + 1; i++)
		cout << "*";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "*";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "#";
			else
				cout << " ";

			if (j == width - 1)
				cout << "*";
		}
		cout << endl;
	}
	// botton wall
	for (int i = 0; i < width + 1; i++)
		cout << "*";
	cout << endl;
	cout << "Score: " << score << endl;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
		case 'A':
			dir = LEFT;
			break;

		case 'd':
		case 'D':
			dir = RIGHT;
			break;

		case 'w':
		case 'W':
			dir = UP;
			break;

		case 's':
		case 'S':
			dir = DOWN;
			break;

		case 'x':
		case 'X':
			gameOver = true;
			break;

		}
	}
}
void Logic()
{
	switch (dir)
	{
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

	if (x > width || x < 0 || y >height || y < 0)
		gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score += 1;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

int main()
{

	int input;
	cout << "========== 별 먹기 게임 =====================" << endl;
	cout << "1. Easy / 2. Normal(준비중) / 3. Hard(준비중)" << endl;

	cout << " " << endl;
	cout << " " << endl;

	cout << " 방향키:" << endl;
	cout << " W : UP " << endl;
	cout << " S : DOWN " << endl;
	cout << " A : LEFT " << endl;
	cout << " D : RIGHT " << endl;
	cout << " " << endl;
	cout << " 게임 방법: " << endl;
	cout << " 0 숫자를 움직여서 # 문자를 먹으면 됩니다. " << endl;
	cout << " *에 붙이치면 게임이 종료되므로 주의하시기 바랍니다 " << endl;
	cout << " " << endl;
	cout << " 난이도 입력: ";
	cin >> input;


	Setup();

	while (!gameOver)
	{

		switch (input)
		{
		case GAME_EASY:
			while (!gameOver)
			{

				Draw();
				Input();
				Logic();

			}
			cout << " " << endl;
			cout << "Game Over" << endl;
			if (score >= 0 && score <= 10)
			{
				cout << "좀 더 노력하세요! ^^" << endl;
			}
			else if (score >= 11 && score <= 20)
			{
				cout << "오.. 좀 게임좀 하시나 봅니다 ㅎㅎ" << endl;
			}
			else
				cout << "게임 천재 시네요!!" << endl;


		case GAME_NORMAL:
			break;

		case GAME_HARD:

			break;
		}

	}
	cout << " " << endl;
	system("pause");
	system("pause");
	return 0;
}