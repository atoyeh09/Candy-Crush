#ifndef headerfile
#define headerfile
void game_name();
void candies(char board[8][8]);
void candies_generator(char board[8][8]);
void first_easy_board(char board[8][8]);
void first_hard_board(char board[10][10]);
void board_easy(char board[8][8],int count);
void candies_hard(char board[10][10]);
void candies_hard_generator(char board[10][10]);
void board_hard(char board[10][10], int count);
bool keys_easy(int row,int col, char board[8][8]);
bool keys_hard(int row, int col, char board[10][10]);
void scores();
void instructions();
void credentials();
#endif // !headerfile
