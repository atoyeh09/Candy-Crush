#include <iostream>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>
#include "headerfile.hpp"
using  namespace std;
char board[8][8];  //global easy mode board array
char hard[10][10]; //global hard mode board array
int main()
{
	//for enlarging the screen size
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 25;
	fontex.dwFontSize.Y = 25;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	//-------------------------------
	int menu;
	string name;
	char mode;
	bool flag = true;
	while (flag==true)
	{
		//Game Main Menu that calls multiple functions according to user selection
		system("Color E4");
		cout << " _____________________________________ \n";
		cout << "|                                     | \n";
		cout << "|       Candy Crush(Main Menu)        |\n";
		cout << "|_____________________________________| \n\n";
		cout << "Enter 1 to Play Game \n";
		cout << "Enter 2 to View Scores \n";
		cout << "Enter 3 to View Credits \n";
		cout << "Enter 4 to View Instructions \n";
		cout << "Enter 5 to Quit \n";
		cout << "Enter any number from above menu = ";
		cin >> menu;
		flag = false;
		int count = 0;
		int condition = menu;
		//----------------------------------------------------------------------
		if (condition == 1)
		{
			//game starting
			system("CLS");
			system("Color 07");
			cout << "Enter Player Name = ";
			cin >> name;
			cout << "Enter E for Easy Mode and H for Hard Mode = ";
			cin >> mode;
			bool wrong_check;
			int row, col;
			//code for easy mode
			if (mode == 'E' || mode == 'e')
			{
				int game = 1;
				while (game != 0)
				{
					bool refresh = false;
					if (count == 0 || refresh==true)
					{
						first_easy_board(board);
					}
					else
					{
						board_easy(board,count);
					}
					bool score_row = false, score_col = false, score_row_4 = false, score_col_4 = false;
					cout << "\nPress 0 to Refresh Board If no candies is matching ! ";
					cout << "\nEnter Row no = ";
					cin >> row;
					if (row == 0)
					{
						refresh = true;
						system("CLS");
					}
					else
					{
						cout << "Enter Col no = ";
						cin >> col;
						cout << "Press Keyboard Arrow keys to Swap it = ";
						wrong_check = keys_easy(row, col, board);
						if (wrong_check == false)
						{
							for (int i = 0; i < 8; i++)
							{
								for (int j = 0; j < 8; j++)
								{
									if ((j > 2) && (j < 8) && (board[i][j] == board[i][j - 1]) && (board[i][j] == board[i][j - 2]) && (board[i][j] == board[i][j - 3]))
									{
										board[i][j] = '0';
										board[i][j - 1] = '0';
										board[i][j - 2] = '0';
										board[i][j - 3] = '0';
										score_row_4 = true;
									}
									else if ((j > 1) && (j < 8) && (board[i][j] == board[i][j - 1]) && (board[i][j] == board[i][j - 2]) && (board[i][j] != board[i][j + 1]))
									{
										board[i][j] = '0';
										board[i][j - 1] = '0';
										board[i][j - 2] = '0';
										score_row = true;
									}
									if ((i > 2) && (i < 8) && (board[i][j] == board[i - 1][j]) && (board[i][j] == board[i - 2][j]) && (board[i][j] == board[i - 3][j]))
									{
										board[i][j] = '0';
										board[i - 1][j] = '0';
										board[i - 2][j] = '0';
										board[i - 3][j] = '0';
										score_col_4 = true;
									}
									else if ((i > 1) && (i < 8) && (board[i][j] == board[i - 1][j]) && (board[i][j] == board[i - 2][j]) && (board[i][j] != board[i + 1][j]))
									{
										board[i][j] = '0';
										board[i - 1][j] = '0';
										board[i - 2][j] = '0';
										score_col = true;
									}
								}
							}
							if (score_row == true && score_col == true)
							{
								count = count + 30;
							}
							else if (score_row == true)
							{
								count = count + 15;
							}
							else if (score_col == true)
							{
								count = count + 15;
							}
							else if (score_row_4 == true || score_col_4 == true)
							{
								count = count + 20;
							}
						}
						system("CLS");
						board_easy(board, count);
						chrono::seconds dura(2);
						this_thread::sleep_for(dura);
						system("CLS");
						candies_generator(board);
						cout << "\nEnter 0 to go to main menu or any other key to continue = ";
						cin >> game;
						if (game == 0)
						{
							ofstream fout;
							fout.open("easy.txt", ios::app);
							fout << "Player Name : " << name;
							fout << "\tScore : " << count << ".";
							flag = true;
							system("CLS");
						}
					}
				}
				//--------------------
				//code for Hard mode
			}else if(mode == 'H' || mode == 'h')
			{
				int game = 1;
				while (game != 0)
				{
					bool refresh = false;
					if (count == 0 || refresh==true)
					{
						first_hard_board(hard);
					}
					else
					{
						board_hard(hard,count);
					}
					bool score_row = false, score_col = false, score_row_4 = false, score_col_4 = false;
					cout << "\nPress 0 to Refresh Board If no candies is matching ! ";
					cout << "\nEnter Row no = ";
					cin >> row;
					if (row == 0)
					{
						refresh=true;
						system("CLS");
					}
					else
					{
						cout << "Enter Col no = ";
						cin >> col;
						cout << "Press Keyboard Arrow keys to Swap it = ";
						wrong_check = keys_hard(row, col, hard);
						if (wrong_check == false)
						{
							for (int i = 0; i < 10; i++)
							{
								for (int j = 0; j < 10; j++)
								{
									if ((j > 2) && (j < 10) && (hard[i][j] == hard[i][j - 1]) && (hard[i][j] == hard[i][j - 2]) && (hard[i][j] == hard[i][j - 3]))
									{
										hard[i][j] = '0';
										hard[i][j - 1] = '0';
										hard[i][j - 2] = '0';
										hard[i][j - 3] = '0';
										score_row_4 = true;
									}
									else if ((j > 1) && (j < 10) && (hard[i][j] == hard[i][j - 1]) && (hard[i][j] == hard[i][j - 2]) && (hard[i][j] != hard[i][j + 1]))
									{
										hard[i][j] = '0';
										hard[i][j - 1] = '0';
										hard[i][j - 2] = '0';
										score_row = true;
									}
									if ((i > 2) && (i < 10) && (hard[i][j] == hard[i - 1][j]) && (hard[i][j] == hard[i - 2][j]) && (hard[i][j] == hard[i - 3][j]))
									{
										hard[i][j] = '0';
										hard[i - 1][j] = '0';
										hard[i - 2][j] = '0';
										hard[i - 3][j] = '0';
										score_col_4 = true;
									}
									else if ((i > 1) && (i < 10) && (hard[i][j] == hard[i - 1][j]) && (hard[i][j] == hard[i - 2][j]) && (hard[i][j] != hard[i + 1][j]))
									{
										hard[i][j] = '0';
										hard[i - 1][j] = '0';
										hard[i - 2][j] = '0';
										score_col = true;
									}
								}
							}
							if (score_row == true && score_col == true)
							{
								count = count + 25;
							}
							else if (score_row == true)
							{
								count = count + 15;
							}
							else if (score_col == true)
							{
								count = count + 15;
							}
							else if (score_row_4 == true || score_col_4 == true)
							{
								count = count + 20;
							}
						}
						system("CLS");
						board_hard(hard, count);
						chrono::seconds dura(2);
						this_thread::sleep_for(dura);
						system("CLS");
						candies_hard_generator(hard);
						cout << "\nEnter 0 to go to main menu or any other key to continue = ";
						cin >> game;
						if (game == 0)
						{
							ofstream fout;
							fout.open("hard.txt", ios::app);
							fout << "Player Name : " << name;
							fout << "\tScore : " << count << ".";
							flag = true;
							system("CLS");
						}
					}
				}
			}
			//--------------------------
			else
			{
				cout << "\nInvalid Move!\n";
			}
		}
		//calling scores function
		else if (condition == 2)
		{
			system("CLS");
			system("Color E4");
			scores();
			flag = true;
		}
		//callling credentials function
		else if (condition == 3)
		{
			system("CLS");
			system("Color F5");
			credentials();
			flag = true;
		}
		//calling instructions function
		else if (condition == 4)
		{
			system("CLS");
			system("Color D6");
			instructions();
			flag = true;
		}
	}
	
	return 0;
}
