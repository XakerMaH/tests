#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <windows.h>
#include <stdlib.h>

using namespace std;
void instructions(const vector<char>& ins);
void game();
bool first();
void player(vector<char>& plTurn);
void ii(vector<char> test, vector<char>& change);
bool check(string ent, const vector<char>& boardCh);
bool checkPl(const vector<char>& pl, int numb);
char win(const vector<char>& checkW);
void show(const vector<char>& sh);
int n;
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
	vector<char> board = { '1', '2','3','4','5','6','7','8','9' };

	instructions(board);
	player(board);
	player(board);
	player(board);
	cout << win(board) << " wins!";
}

char win(const vector<char>& checkW)
{
	char Win = '1';
	for (int i = 0; i < 7; i += 3)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (Win != checkW[i + j] and (i + j) > 0)
			{
				Win = '1';
				break;
			}
			else
			{
				Win = checkW[i + j];
			}
		}
		if (!isdigit(Win))
		{
			break;
		}
	}
	if (isdigit(Win))
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 7; j += 3)
			{
				if (Win != checkW[i + j] and i + j != 0)
				{
					Win = '0';
					break;
				}
				Win = checkW[i + j];
			}
			if (!isdigit(Win))
			{
				break;
			}
		}
	}
	if (isdigit(Win))
	{
		for (int i = 0; i < 3; i += 2)
		{
			for (int j = 0; j < 9; j += 8)
			{
				Win = checkW[j - i];
			}
			if (!isdigit(Win))
			{
				break;
			}
		}
	}
	return Win;
}
void ii(vector<char> test, vector<char>& change)
{
	system("cls");
	instructions(change);
}

void player(vector<char>& plTurn)
{
	string enter;
	do
	{
		cout << "\nВыберете поле: ";
		cin >> enter;
	} while (check(enter, plTurn));

	plTurn[n - 1] = 'X';
	system("cls");
	instructions(plTurn);

}
bool checkPl(const vector<char>& pl, int numb)
{
	bool can = true;
	if ((numb < 0 or numb > 8) or (pl[numb] == 'X' or pl[numb] == 'O'))
	{
		can = false;
	}
	return can;
}

bool check(string ent, const vector<char>& boardCh)
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
	if (!checkPl(boardCh, n - 1))
	{
		error = true;
	}
	return error;
}

void instructions(const vector<char>& ins)
{
	cout << "\nДобро пожаловать в 'Крестики-Нолики'\n";
	cout << "Здесь вам придётся сразиться с могущественной машиной\n" << endl;
	show(ins);
	cout << "\n\nЧтобы сделать ход, выберете поле из предложенных выше и введите его номер\n";
}

void show(const vector<char>& sh)
{
	cout << "\n";
	for (int i = 0; i < 7; i += 3)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
				cout << "\n\t\t" << sh[i + j] << " |";
			if (j == 1)
				cout << " " << sh[i + j] << " |";
			if (j == 2)
			{
				cout << " " << sh[i + j];
			}
		}
		if (i < 6)
		{
			cout << "\n\t\t---------";
		}
	}
	cout << "\n";
}