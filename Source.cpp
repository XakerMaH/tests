
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include<windows.h>
using namespace std;
void instructions(const vector < vector < string>>& ins);
void game();
bool first();
void player(vector < vector < string>>& plTurn);
void ii(vector < vector < string>> test, vector < vector < string>>& change);
bool check(string ent, const vector < vector < string>>& boardCh);
bool checkPl(vector < vector < string>>& pl, int rows, int cols);
bool win(const vector < vector < string>>& checkW);
bool lose(const vector < vector < string>>& checkW2);
void show(const vector < vector < string>>& sh);
int n;
int r;
int r2;
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool again;
	string againT;

	do
	{
		system("cls");
		game();
		do
		{
			cout << "\n\nВы хотите сыграть снова?(да/нет): ";
			cin >> againT;
		} while (againT != "да" and againT != "нет");

		if (againT == "да")
		{
			again = true;
		}
		else
		{
			again = false;
		}
	} while (again);

	return 0;
}

void game()
{
	vector < vector < string>> board = { {"1", "2", "3"},
										{"4", "5", "6"},
										{"7", "8", "9"} };

	instructions(board);
	player(board);
	ii(board, board);
	player(board);
	ii(board, board);
	player(board);
	ii(board, board);
	lose(board);
	if (lose(board))
	{
		cout << "you win";
	}
	if (win(board))
	{
		cout << "you lose";
	}
}

bool win(const vector < vector < string>>& checkW)
{
	bool iiWin = false;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (checkW[i][j] == "O")
			{
				iiWin = true;
			}
			else
			{
				iiWin = false;
				break;
			}
		}
		if (iiWin)
		{
			break;
		}
	}
	if (iiWin == false)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (checkW[j][i] == "O")
				{
					iiWin = true;
				}
				else
				{
					iiWin = false;
					break;
				}
			}
			if (iiWin)
			{
				break;
			}
		}
	}
	if (iiWin == false)
	{

		for (int i = 0; i < 3; ++i)
		{

			if (checkW[i][i] == "O")
			{
				iiWin = true;
			}
			else
			{
				iiWin = false;
				break;
			}
		}
	}
	if (iiWin == false)
	{
		int row = 2;
		for (int i = 0; i < 3; ++i)
		{

			if (checkW[row - i][i] == "O")
			{
				iiWin = true;
			}
			else
			{
				iiWin = false;
				break;
			}
		}
	}
	return iiWin;
}
bool lose(const vector < vector < string>>& checkW2)
{
	bool plWin = false;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (checkW2[i][j] == "X")
			{
				plWin = true;
			}
			else
			{
				plWin = false;
				break;
			}
		}
		if (plWin)
		{
			break;
		}
	}
	if (plWin == false)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (checkW2[j][i] == "X")
				{
					plWin = true;
				}
				else
				{
					plWin = false;
					break;
				}
			}
			if (plWin)
			{
				break;
			}
		}
	}
	if (plWin == false)
	{

		for (int i = 0; i < 3; ++i)
		{

			if (checkW2[i][i] == "X")
			{
				plWin = true;
			}
			else
			{
				plWin = false;
				break;
			}
		}
	}
	if (plWin == false)
	{
		int row = 2;
		for (int i = 0; i < 3; ++i)
		{

			if (checkW2[row - i][i] == "X")
			{
				plWin = true;
			}
			else
			{
				plWin = false;
				break;
			}
		}
	}
	return plWin;
}

void ii(vector < vector < string>> test, vector < vector < string>>& change)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (checkPl(test, i, j))
			{
				test[i][j] = "O";
				if (win(test))
				{
					change[i][j] = "O";
				}
				else
				{
					test[i][j] = change[i][j];
				}
			}
		}
		if (win(change))
		{
			break;
		}
	}
	bool randm = false;
	bool W = win(change);
	if (W == false)
	{
		for (int i = 0; i < 3; ++i)
		{
			bool yes = false;
			for (int j = 0; j < 3; ++j)
			{
				if (checkPl(test, i, j))
				{
					test[i][j] = "X";
					if (lose(test))
					{
						change[i][j] = "O";
						test[i][j] = "O";
						yes = true;
						break;
					}
					else
					{
						test[i][j] = change[i][j];
						randm = true;
					}
				}
				else
				{
					test[i][j] = change[i][j];
					randm = true;
				}
			}
			if (yes)
			{
				randm = false;
				break;
			}
		}
	}
	if (randm and W == false)
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (change[i][j] == "O")
				{
					for (int il = i - 1; il < (i + 2); ++il)
					{
						for (int jl = j - 1; jl < (j + 2); ++jl)
						{
							if (checkPl(change, il, jl))
							{
								change[il][jl] = "O";
								il = 4;
								j = 3;
								i = 3;
								break;
							}
						}
					}
				}
				else
				{
					int a;
					int b;
					do
					{
						a = rand() % 3;
						b = rand() % 3;
					} while (change[a][b] == "X" or change[a][b] == "O");
					change[a][b] = "O";
					i = 3;
					j = 3;
				}
			}
		}
	}
	system("cls");
	instructions(change);
}

void player(vector < vector < string>>& plTurn)
{
	string enter;
	do
	{
		cout << "\nВыберете поле: ";
		cin >> enter;
	} while (check(enter, plTurn));

	plTurn[r][n - r2] = "X";
	system("cls");
	instructions(plTurn);

}
bool checkPl(vector < vector < string>>& pl, int rows, int cols)
{
	bool can = true;
	if ((rows > -1 and rows < 3) and (cols > -1 and cols < 3))
	{
		can = false;
	}
	if (pl[rows][cols] == "X" or pl[rows][cols] == "O")
	{
		can = false;
	}
	return can;
}

bool check(string ent, const vector < vector < string>>& boardCh)
{
	string::iterator checker;
	bool error;

	for (checker = ent.begin(); checker != ent.end(); ++checker)
	{

		if (isdigit(*checker))
		{
			error = false;
		}
		else
		{
			error = true;
			break;
		}
	}

	n = atoi(ent.c_str());

	if (n > 0 and n < 10)
	{
		if (n < 4)
		{
			r = 0;
			r2 = 1;
			if (boardCh[0][n - 1] != "X" and boardCh[1][n - 1] != "O")
			{
				error = false;
			}
			else
			{
				error = true;
				cout << "некоректное значение\n";
			}
		}
		else if (n < 7)
		{
			r = 1;
			r2 = 4;
			if (boardCh[1][n - 4] != "X" and boardCh[1][n - 4] != "O")
			{
				error = false;
			}
			else
			{
				error = true;
				cout << "некоректное значение\n";
			}
		}
		else
		{
			r = 2;
			r2 = 7;
			if (boardCh[2][n - 7] != "X" and boardCh[2][n - 7] != "O")
			{
				error = false;
			}
			else
			{
				error = true;
				cout << "некоректное значение\n";
			}
		}

	}
	else
	{
		error = true;
		cout << "некоректное значение\n";
	}

	return(error);
}

void instructions(const vector < vector < string>>& ins)
{
	cout << "\nДобро пожаловать в 'Крестики-Нолики'\n";
	cout << "Здесь вам придётся сразиться с могущественной машиной\n" << endl;
	show(ins);
	cout << "\n\nЧтобы сделать ход, выберете поле из предложенных выше и введите его номер\n";
}

void show(const vector < vector < string>>& sh)
{
	cout << "\n";
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 1)
			{
				cout << " " << sh[i][j] << " |";
			}

			else if (j == 0)
			{
				cout << "          " << sh[i][j] << " |";
			}
			else
			{
				cout << " " << sh[i][j];
			}

		}
		if (i < 2)
		{
			cout << "\n          —--------\n";
		}
	}
	cout << "\n";
}
