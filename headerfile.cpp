#include "headerfile.hpp"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
void game_name() //for coloring of GAME NAME
{
	string gn = "Candy Crush";
	HANDLE g = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 11; i++)
	{
		switch (gn[i])
		{
		case 'C':
			SetConsoleTextAttribute(g, 4);
			break;
		case 'a':
			SetConsoleTextAttribute(g, 1);
			break;
		case 'n':
			SetConsoleTextAttribute(g, 2);
			break;
		case 'd':
			SetConsoleTextAttribute(g, 6);
			break;
		case 'y':
			SetConsoleTextAttribute(g, 13);
			break;
		case ' ':
			SetConsoleTextAttribute(g, 7);
			break;
		case 'r':
			SetConsoleTextAttribute(g, 3);
			break;
		case 'u':
			SetConsoleTextAttribute(g, 8);
			break;
		case 's':
			SetConsoleTextAttribute(g, 10);
			break;
		case 'h':
			SetConsoleTextAttribute(g, 5);
			break;
		}
		cout << gn[i];
	}
	SetConsoleTextAttribute(g, 7);
}

void first_easy_board(char board[8][8]) //first time board displayed in easy mode
{
	candies(board);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " __________________________ \n";
	cout << "|                          | \n";
	cout << "|       "; 
	game_name();
	cout << "        |\n";
	cout << "|__________________________| \n";
	cout << "\n     1  2  3  4  5  6  7  8   \n";
	cout << " __________________________ \n\n";
	for (int i = 0; i < 8; i++)
	{
		SetConsoleTextAttribute(h, 7);
		cout << i + 1 << " |";
		for (int j = 0; j < 8; j++)
		{
			switch (board[i][j])
			{
			case '#':
				SetConsoleTextAttribute(h, 4);
				break;
			case '@':
				SetConsoleTextAttribute(h, 1);
				break;
			case '$':
				SetConsoleTextAttribute(h, 2);
				break;
			case '%':
				SetConsoleTextAttribute(h, 6);
				break;
			case '&':
				SetConsoleTextAttribute(h, 13);
				break;
			}
			cout << "  " << board[i][j];
		}
		SetConsoleTextAttribute(h, 7);
		cout << " |" << endl;
	}
	cout << " __________________________ ";
}
void first_hard_board(char board[10][10])  //first time board displayed for Hard Mode
{
	candies_hard(board);
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " _________________________________ \n";
	cout << "|                                 | \n";
	cout << "|           Candy Crush           |\n";
	cout << "|_________________________________| \n";
	cout << "\n     1  2  3  4  5  6  7  8  9  10   \n";
	cout << " _________________________________ \n\n";
	for (int i = 0; i < 10; i++)
	{
		SetConsoleTextAttribute(h, 7);
		if (i == 9)
		{
			cout << i + 1 << "|";
		}
		else
		{
			cout << i + 1 << " |";
		}

		for (int j = 0; j < 10; j++)
		{
			switch (board[i][j])
			{
			case '#':
				SetConsoleTextAttribute(h, 4);
				break;
			case '@':
				SetConsoleTextAttribute(h, 1);
				break;
			case '$':
				SetConsoleTextAttribute(h, 2);
				break;
			case '%':
				SetConsoleTextAttribute(h, 6);
				break;
			case '&':
				SetConsoleTextAttribute(h, 13);
				break;
			case '+':
				SetConsoleTextAttribute(h, 3);
				break;
			case '=':
				SetConsoleTextAttribute(h, 5);
				break;
			case '*':
				SetConsoleTextAttribute(h, 8);
				break;
			}

			if (j == 9)
			{
				cout << "  " << board[i][j];
			}
			else
			{
				cout << "  " << board[i][j];
			}
		}
		SetConsoleTextAttribute(h, 7);
		cout << " |" << endl;
	}
	cout << " _________________________________ ";
}
void candies_hard(char board[10][10])  //for first time storing candies to hard mode
{
	srand(time(0));
	char candies_hard[] = { '#','@','$','%','&','+','*','='};
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = candies_hard[rand() % 8];
			if ((j > 1) && (board[i][j] == board[i][j - 1]) && (board[i][j] == board[i][j - 2]))
			{
				j--;
			}
			if ((i > 1) && (board[i][j] == board[i - 1][j]) && (board[i][j] == board[i - 2][j]))
			{
				i--;
			}
		}
	}
}
void candies_hard_generator(char board[10][10]) //for generating candies at vacant spaces in hard mode
{
	srand(time(0));
	char candies_hard[] = { '#','@','$','%','&','+','*','=' };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == '0')
			{
				board[i][j] = candies_hard[rand() % 8];
			}
			if ((j > 1) && (board[i][j] == board[i][j - 1]) && (board[i][j] == board[i][j - 2]))
			{
				j--;
			}
			if ((i > 1) && (board[i][j] == board[i - 1][j]) && (board[i][j] == board[i - 2][j]))
			{
				i--;
			}
		}
	}
}
void board_hard(char board[10][10],int count)  //general used board for hard mode
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " _________________________________ \n";
	cout << "|                                 | \n";
	cout << "|           Candy Crush           |\n";
	if (count < 10)
	{
		cout << "|           Score : 0" << count << "            | \n";
	}
	else
	{
		cout << "|           Score : " << count << "            | \n";
	}
	cout << "|_________________________________| \n";
	cout << "\n     1  2  3  4  5  6  7  8  9  10   \n";
	cout << " _________________________________ \n\n";
	for (int i = 0; i < 10; i++)
	{
		SetConsoleTextAttribute(h, 7);
		if (i == 9)
		{
			cout << i + 1 << "|";
		}
		else
		{
			cout << i + 1 << " |";
		}
		
		for (int j = 0; j < 10; j++)
		{
			switch (board[i][j])
			{
			case '#':
				SetConsoleTextAttribute(h, 4);
				break;
			case '@':
				SetConsoleTextAttribute(h, 1);
				break;
			case '$':
				SetConsoleTextAttribute(h, 2);
				break;
			case '%':
				SetConsoleTextAttribute(h, 6);
				break;
			case '&':
				SetConsoleTextAttribute(h, 13);
				break;
			case '+':
				SetConsoleTextAttribute(h, 3);
				break;
			case '=':
				SetConsoleTextAttribute(h, 5);
				break;
			case '*':
				SetConsoleTextAttribute(h, 8);
				break;
			case '0':
				SetConsoleTextAttribute(h, 24);
				break;
			}
			
			if (j == 9)
			{
				cout << "  " << board[i][j];
			}
			else
			{
				cout << "  " << board[i][j];
			}
		}
		SetConsoleTextAttribute(h, 7);
		cout << " |" << endl;
	}
	cout << " _________________________________ ";
}
void candies(char board[8][8])  //first time storing candies in Easy board
{
	srand(time(0));
	char candies[] = { '#','@','$','%','&' };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = candies[rand() % 5];
			if ((j > 1) && (board[i][j] == board[i][j - 1]) && (board[i][j] == board[i][j - 2]))
			{
				j--;
			}
			if ((i > 1) && (board[i][j] == board[i - 1][j]) && (board[i][j] == board[i - 2][j]))
			{
				i--;
			}
		}
	}
}
void candies_generator(char board[8][8])  //frequently generating candies in easy mode at vacant spaces
{
	srand(time(0));
	char candies[] = { '#','@','$','%','&' };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == '0')
			{
				board[i][j] = candies[rand() % 5];
			}
			if ((j > 1) && (board[i][j] == board[i][j - 1]) && (board[i][j] == board[i][j - 2]))
			{
				j--;
			}
			if ((i > 1) && (board[i][j] == board[i - 1][j]) && (board[i][j] == board[i - 2][j]))
			{
				i--;
			}
		}
	}
}
void board_easy(char board[8][8],int count)  //generally used board for easy mode
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << " __________________________ \n";
	cout << "|                          | \n";
	cout << "|       Candy Crush        |\n";
	if (count < 10)
	{
		cout << "|       Score : 0" << count << "         |\n";
	}
	else
	{
		cout << "|       Score : " << count << "         |\n";
	}
	cout << "|__________________________| \n";
	cout << "\n     1  2  3  4  5  6  7  8   \n";
	cout << " __________________________ \n\n";
	for (int i = 0; i < 8; i++)
	{
		SetConsoleTextAttribute(h, 7);
		cout <<i+1<< " |";
		for (int j = 0; j < 8; j++)
		{
			switch (board[i][j])
			{
			case '#':
				SetConsoleTextAttribute(h, 4);
				break;
			case '@':
				SetConsoleTextAttribute(h, 1);
				break;
			case '$':
				SetConsoleTextAttribute(h, 2);
				break;
			case '%':
				SetConsoleTextAttribute(h, 6);
				break;
			case '&':
				SetConsoleTextAttribute(h, 13);
				break;
			case '0':
				SetConsoleTextAttribute(h, 24);
				break;
			}
			if (j == 7)
			{
				cout << "  " << board[i][j];
			}
			else
			{
				cout << "  " << board[i][j];
			}
		}
		SetConsoleTextAttribute(h, 7);
		cout << " |" << endl;
	}
	cout << " __________________________ ";
}

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
bool keys_easy(int row,int col,char board[8][8])  //keys swapping function for easy mode
{
	row = row - 1;
	col = col - 1;
	bool swapping = true;
	bool wrong = false;
	int c = 0;
	while (swapping==true)
	{
		c = 0;
		switch (c = _getch()) {
		case KEY_UP:
			if (row > 0)
			{
				if (((board[row][col] == board[row - 1][col - 1]) && (board[row][col] == board[row - 1][col + 1])) || ((board[row][col] == board[row - 1][col + 1]) && (board[row][col] == board[row - 1][col + 2])) || ((board[row][col] == board[row - 1][col - 1]) && (board[row][col] == board[row - 1][col - 2])) || ((board[row][col] == board[row - 1][col]) && (board[row][col] == board[row - 2][col])))
				{
					char original = board[row][col];
					board[row][col] = board[row - 1][col];
					board[row - 1][col] = original;
					swapping = false;
				}
				else if ((board[row - 1][col] == board[row][col + 1] && board[row - 1][col] == board[row][col + 2]) || (board[row - 1][col] == board[row][col - 1] && board[row - 1][col] == board[row][col - 2]) || (board[row - 1][col] == board[row + 1][col] && board[row - 1][col] == board[row + 2][col]) || (board[row - 1][col] == board[row][col - 1] && board[row - 1][col] == board[row][col + 1]))
				{
					char original = board[row - 1][col];
					board[row - 1][col] = board[row][col];
					board[row][col] = original;
					swapping = false;
				}
				else
				{
					cout << "\nWrong Move!\n";
					swapping = false;
					wrong = true;
				}
			}
			else
			{
				cout << "\nWrong Move!\n";
				swapping = false;
				wrong = true;
			}
			break;
		case KEY_DOWN:
			if (row != 8 - 1)
			{
				if ((board[row][col] == board[row + 2][col] && board[row][col] == board[row + 3][col]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 1][col + 2]) || (board[row][col] == board[row + 1][col - 1] && board[row][col] == board[row + 1][col - 2]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 1][col - 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row + 1][col];
					board[row + 1][col] = original;
					swapping = false;
				}
				else if ((board[row + 1][col] == board[row - 1][col] && board[row + 1][col] == board[row - 2][col]) || (board[row + 1][col] == board[row][col - 1] && board[row + 1][col] == board[row][col - 2]) || (board[row + 1][col] == board[row][col + 1] && board[row + 1][col] == board[row][col + 2]) || (board[row + 1][col] == board[row][col - 1] && board[row + 1][col] == board[row][col + 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row - 1][col];
					board[row - 1][col] = original;
					swapping = false;
				}
				else
				{
					cout << "\nWrong Move!\n";
					swapping = false;
					wrong = true;
				}
			}
			else
			{
				cout << "\nWrong Move!\n";
				swapping = false;
				wrong = true;
			}
			break;
		case KEY_LEFT:
			if (col != 0)
			{
				if ((board[row][col] == board[row][col - 2] && board[row][col] == board[row][col - 3]) || (board[row][col] == board[row + 1][col - 1] && board[row][col] == board[row + 2][col - 1]) || (board[row][col] == board[row - 1][col - 1] && board[row][col] == board[row - 2][col - 1]) || (board[row][col] == board[row - 1][col - 1] && board[row][col] == board[row + 1][col - 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row][col - 1];
					board[row][col - 1] = original;
					swapping = false;
				}
				else if ((board[row][col - 1] == board[row][col + 1] && board[row][col - 1] == board[row][col + 2]) || (board[row][col - 1] == board[row - 1][col] && board[row][col - 1] == board[row - 2][col]) || (board[row][col - 1] == board[row + 1][col] && board[row][col - 1] == board[row + 2][col]) || (board[row][col - 1] == board[row][col] && board[row][col - 1] == board[row][col + 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row][col - 1];
					board[row][col - 1] = original;
					swapping = false;
				}
				else
				{
					cout << "\nWrong Move!\n";
					swapping = false;
					wrong = true;
				}
			}
			else
			{
				cout << "\nWrong Move!\n";
				swapping = false;
				wrong = true;
			}
			break;
		case KEY_RIGHT:
			if (col!= 8-1)
			{
				if ((board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row - 2][col + 1]) || (board[row][col] == board[row][col + 2] && board[row][col] == board[row][col + 3]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 2][col + 1]) || (board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row + 1][col + 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row][col + 1];
					board[row][col + 1] = original;
					swapping = false;
				}
				else if ((board[row][col + 1] == board[row][col - 1] && board[row][col + 1] == board[row][col - 2]) || (board[row][col + 1] == board[row - 1][col] && board[row][col + 1] == board[row - 2][col]) || (board[row][col + 1] == board[row + 1][col] && board[row][col + 1] == board[row + 2][col]) || (board[row][col + 1] == board[row][col] && board[row][col + 1] == board[row][col + 2]))
				{
					char original = board[row][col];
					board[row][col] = board[row][col + 1];
					board[row][col + 1] = original;
					swapping = false;
				}
				else
				{
					cout << "\nWrong Move!\n";
					swapping = false;
					wrong = true;
				}
			}
			else
			{
				cout << "\nWrong Move!\n";
				swapping = false;
				wrong = true;
			}
			break;
		}
	 }
	return wrong;
}

bool keys_hard(int row, int col, char board[10][10])  //keys swapping function for Hard mode
{
	row = row - 1;
	col = col - 1;
	bool swapping = true;
	bool wrong = false;
	int c = 0;
	while (swapping == true)
	{
		c = 0;
		switch (c = _getch()) {
		case KEY_UP:
			system(" cls ");
			if (row > 0)
			{
				if (((board[row][col] == board[row - 1][col - 1]) && (board[row][col] == board[row - 1][col + 1])) || ((board[row][col] == board[row - 1][col + 1]) && (board[row][col] == board[row - 1][col + 2])) || ((board[row][col] == board[row - 1][col - 1]) && (board[row][col] == board[row - 1][col - 2])) || ((board[row][col] == board[row - 1][col]) && (board[row][col] == board[row - 2][col])))
				{
					char original = board[row][col];
					board[row][col] = board[row - 1][col];
					board[row - 1][col] = original;
					swapping = false;
				}
				else if ((board[row - 1][col] == board[row][col + 1] && board[row - 1][col] == board[row][col + 2]) || (board[row - 1][col] == board[row][col - 1] && board[row - 1][col] == board[row][col - 2]) || (board[row - 1][col] == board[row + 1][col] && board[row - 1][col] == board[row + 2][col]) || (board[row - 1][col] == board[row][col - 1] && board[row - 1][col] == board[row][col + 1]))
				{
					char original = board[row - 1][col];
					board[row - 1][col] = board[row][col];
					board[row][col] = original;
					swapping = false;
				}
				else
				{
					cout << "\nWrong Move!\n";
					swapping = false;
					wrong = true;
				}
			}
			else
			{
				cout << "\nWrong Move!\n";
				swapping = false;
				wrong = true;
			}
			break;
		case KEY_DOWN:
			system(" cls ");
			if (row != 10 - 1)
			{
				if ((board[row][col] == board[row + 2][col] && board[row][col] == board[row + 3][col]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 1][col + 2]) || (board[row][col] == board[row + 1][col - 1] && board[row][col] == board[row + 1][col - 2]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 1][col - 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row + 1][col];
					board[row + 1][col] = original;
					swapping = false;
				}
				else if ((board[row + 1][col] == board[row - 1][col] && board[row + 1][col] == board[row - 2][col]) || (board[row + 1][col] == board[row][col - 1] && board[row + 1][col] == board[row][col - 2]) || (board[row + 1][col] == board[row][col + 1] && board[row + 1][col] == board[row][col + 2]) || (board[row + 1][col] == board[row][col - 1] && board[row + 1][col] == board[row][col + 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row - 1][col];
					board[row - 1][col] = original;
					swapping = false;
				}
				else
				{
					cout << "\nWrong Move!\n";
					swapping = false;
					wrong = true;
				}
			}
			else
			{
				cout << "\nWrong Move!\n";
				swapping = false;
				wrong = true;
			}
			break;
		case KEY_LEFT:
			system(" cls ");
			if (col != 0)
			{
				if ((board[row][col] == board[row][col - 2] && board[row][col] == board[row][col - 3]) || (board[row][col] == board[row + 1][col - 1] && board[row][col] == board[row + 2][col - 1]) || (board[row][col] == board[row - 1][col - 1] && board[row][col] == board[row - 2][col - 1]) || (board[row][col] == board[row - 1][col - 1] && board[row][col] == board[row + 1][col - 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row][col - 1];
					board[row][col - 1] = original;
					swapping = false;
				}
				else if ((board[row][col - 1] == board[row][col + 1] && board[row][col - 1] == board[row][col + 2]) || (board[row][col - 1] == board[row - 1][col] && board[row][col - 1] == board[row - 2][col]) || (board[row][col - 1] == board[row + 1][col] && board[row][col - 1] == board[row + 2][col]) || (board[row][col - 1] == board[row][col] && board[row][col - 1] == board[row][col + 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row][col - 1];
					board[row][col - 1] = original;
					swapping = false;
				}
				else
				{
					cout << "\nWrong Move!\n";
					swapping = false;
					wrong = true;
				}
			}
			else
			{
				cout << "\nWrong Move!\n";
				swapping = false;
				wrong = true;
			}
			break;
		case KEY_RIGHT:
			system(" cls ");
			if (col != 10 - 1)
			{
				system(" cls ");
				if ((board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row - 2][col + 1]) || (board[row][col] == board[row][col + 2] && board[row][col] == board[row][col + 3]) || (board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 2][col + 1]) || (board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row + 1][col + 1]))
				{
					char original = board[row][col];
					board[row][col] = board[row][col + 1];
					board[row][col + 1] = original;
					swapping = false;
				}
				else if ((board[row][col + 1] == board[row][col - 1] && board[row][col + 1] == board[row][col - 2]) || (board[row][col + 1] == board[row - 1][col] && board[row][col + 1] == board[row - 2][col]) || (board[row][col + 1] == board[row + 1][col] && board[row][col + 1] == board[row + 2][col]) || (board[row][col + 1] == board[row][col] && board[row][col + 1] == board[row][col + 2]))
				{
					char original = board[row][col];
					board[row][col] = board[row][col + 1];
					board[row][col + 1] = original;
					swapping = false;
				}
				else
				{
					cout << "\nWrong Move!\n";
					swapping = false;
					wrong = true;
				}
			}
			else
			{
				cout << "\nWrong Move!\n";
				swapping = false;
				wrong = true;
			}
			break;
		}
	}
	return wrong;
}

void instructions()  //instructions of game
{
	cout << " _____________________________________ \n";
	cout << "|                                     | \n";
	cout << "|       Candy Crush(Instructions)     |\n";
	cout << "|_____________________________________| \n\n";
	int back;
	cout << "--CANDY CRUSH--\n";
	cout << "--Instructions--\n";
	cout << "* The initial objective of Candy Crush Saga is to earn a certain number of points within a certain number\n";
	cout <<	"  of moves.\n";
	cout << "* There are two modes in the game i.e Easy Mode & Hard Mode.\n";
	cout << "* Easy Mode has a Board of 8x8 and have 5 Candies. \n";
	cout << "* Similarly Hard Mode has a Board of 10x10 and have 7 Candies. \n";
	cout << "* You earned score of 15 when you match a single 3 candies row or column, a score of 20 when you match \n";
	cout << "  more than 3 candies, a score of 30 when you made a L shape with 3 candies in row as well as in column.\n";
	cout << "* You need to score maximum points by swapping candies and made a sequence of three characters either \n";
	cout << "  vertically or horizontally. \n";
	cout << "________________________________________________________________________________________________________________\n";
	cout << "Enter 0 to get Back to main menu = ";
	cin >> back;
	if (back == 0)
	{
		system("CLS");
	}
}
void credentials()  //credentials(By whom Game is made by) 
{
	cout << " _____________________________________ \n";
	cout << "|                                     |\n";
	cout << "|       Candy Crush(Credentials)      |\n";
	cout << "|_____________________________________|\n";
	cout << "|                                     |\n";
	cout << "|          Game Developed By          |\n";
	cout << "|    Gohar Ellahi && Atyab Khalid     |\n";
	cout << "|        22F-3636 && 22F-3655         |\n";
	cout << "|_____________________________________|\n";
	cout << "Enter 0 to get Back to main menu = ";
	int back;
	cin >> back;
	if (back == 0)
	{
		system("CLS");
	}
}
void scores()  //scores list of players sorted by type of modes
{
	char mode;
	int back;
	cout << "Enter E for Easy and H for Hard Mode = ";
	cin >> mode;
	if (mode == 'E' || mode == 'e')
	{
		system("Color 27");
		cout << " _____________________________________ \n";
		cout << "|                                     | \n";
		cout << "|    Candy Crush(Easy Mode Scores)    |\n";
		cout << "|_____________________________________| \n\n";
		ifstream fin;
		fin.open("easy.txt");
		if (!(fin.is_open()))
		{
			cout << "File cannot be opened.";
		}
		else
		{
			cout << "Easy Mode Marks List: \n\n";
			char ch;
			while (!fin.eof())
			{
				fin.get(ch); // using get() function
				if (!fin.eof())
				{
					if (ch != '.')
					{
						cout << ch;
					}
					else
					{
						cout << endl;
					}
				}
			}
			fin.close();
		}
	}else if (mode == 'H' || mode == 'h')
	{
		system("Color 47");
		cout << " _____________________________________ \n";
		cout << "|                                     | \n";
		cout << "|    Candy Crush(Hard Mode Scores)    |\n";
		cout << "|_____________________________________| \n\n";
		ifstream fin;
		fin.open("hard.txt");
		if (!(fin.is_open()))
		{
			cout << "File cannot be opened.";
		}
		else
		{
			cout << "Hard Mode Marks List: \n\n";
			char ch;
			while (!fin.eof())
			{
				fin.get(ch); // using get() function
				if (!fin.eof())
				{
					if (ch != '.')
					{
						cout << ch;
					}
					else
					{
						cout << endl;
					}
					
				}
					
			}
			fin.close();
		}
	}
	cout << "\nEnter 0 to get Back to main menu = ";
	cin >> back;
	if (back == 0)
	{
		system("CLS");
	}
}