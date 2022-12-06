#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;

// �� ũ��
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


// ��ü���� ����
void Setup()
{
	gameOver = false;
	// snake�� ������ �߰����� ����
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
	�� ����:
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
	cout << "========== �� �Ա� ���� =====================" << endl;
	cout << "1. Easy / 2. Normal(�غ���) / 3. Hard(�غ���)" << endl;

	cout << " " << endl;
	cout << " " << endl;

	cout << " ����Ű:" << endl;
	cout << " W : UP " << endl;
	cout << " S : DOWN " << endl;
	cout << " A : LEFT " << endl;
	cout << " D : RIGHT " << endl;
	cout << " " << endl;
	cout << " ���� ���: " << endl;
	cout << " 0 ���ڸ� �������� # ���ڸ� ������ �˴ϴ�. " << endl;
	cout << " *�� ����ġ�� ������ ����ǹǷ� �����Ͻñ� �ٶ��ϴ� " << endl;
	cout << " " << endl;
	cout << " ���̵� �Է�: ";
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
				cout << "�� �� ����ϼ���! ^^" << endl;
			}
			else if (score >= 11 && score <= 20)
			{
				cout << "��.. �� ������ �Ͻó� ���ϴ� ����" << endl;
			}
			else
				cout << "���� õ�� �ó׿�!!" << endl;


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