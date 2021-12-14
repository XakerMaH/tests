/*
планировка:
1)Приветсвие
2)Процесс игры
	1. Функция одной игры
		1) создание char вектора доски для игры
			1.1 цикл фор с push.back i, преобразованного в char
		2) выполнение функции демонстрации доски
			2.1. в аргументах функции ссылка на конст вектор доски
			2.2. создание конст итератора
			2.3. цикл фор, находящийся внутри другого цикла и выполняющийся трижды
				3.1. итератор = началу вектора 
				3.2. пока итератор != концу вектора 
				3.3 ++ итератор
				3.4. тело цикла
					1) как должна выглядеть доска:
					   0 | 1 | 2 
					   ---------
					   3 | 4 | 5
					   ---------
					   6 | 7 | 8
					2) вывод: итератор* |, | итератор* |, | итератор* 

			2.4. если i != 3, то вывод: ---------
		
	2. бул функция кто первый ходит
		2.2. while(пока не введёт да или нет)
			хотите сходить первым?
			запись результата в переменную
			ретюрн в иф на ход бота
	3. Функция хода игрока
		3.1. переменная поля
		3.2. while(функция проверки на возможность)
			{
				выберете поле
				ввод = поле
			}
		3.3. замена элемента в векторе на переменную 

	4. Ход ии
		4.1. фор с проходом по всем элементам итератором 
			ставим нолик и проверяем на правильность и победу
		4.2. фор с проходом по всем элементам итератором
			ставим крестик и проверяем на правильность и победу
		4.3. выбор рандомного поля, если победить или проиграть нельзя

	5. замена игрового поля
		5.1. system("cls"); после начала игры и после каждого хода
	6. функция проверки хода на возможность
	7. функция проверки на победу
	8. цикл с возможностью повтора и функцией игры
		1) игра
		2) проверка на победу функцией
		3) возвращение в глобальную переменную значения true или false
		4) цикл с условием этой переменной
	9. функция инструкций
*/

#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;
void instructions(const  vector<vector<string>>& ins);
void game();
bool first();
void player(vector<vector<string>>& plTurn);
void ii();
bool check(string ent, const vector<vector<string>>& boardCh);
char win();
void show(const vector<vector<string>>& sh);
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
	vector<vector<string>> board = { {"1", "2", "3"},
									 {"4", "5", "6"},
									 {"7", "8", "9"} };

	instructions(board);
	player(board);

}

void player(vector<vector<string>>& plTurn)
{
	string enter;

	do
	{
		cout << "\nВыберете поле: ";
		cin >> enter;
	} while (check(enter, plTurn));

	plTurn[r][n - r2] = "X";
	system("cls");
	show(plTurn);

}

bool check(string ent, const vector<vector<string>>& boardCh)
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
				if (boardCh[0][n-1] != "X" and boardCh[1][n - 1] != "O")
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

void instructions(const  vector<vector<string>>& ins)
{
	cout << "\nДобро пожаловать в 'Крестики-Нолики'\n";
	cout << "Здесь вам придётся сразиться с могущественной машиной\n" << endl;
	show(ins);
	cout << "\n\nЧтобы сделать ход, выберете поле из предложенных выше и введите его номер\n";
}

void show(const vector<vector<string>>& sh)
{
	cout << "\n";
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 1 or j == 3 or j == 7)
			{
				cout << " " << sh[i][j] << " |";
			}

			else if (j % 3 == 0)
			{
				cout << "        " << sh[i][j] << " |";
			}
			else
			{
				cout << " " << sh[i][j];
			}

		}
		if (i < 2)
		{
			cout << "\n        ---------\n";
		}
	}
	cout << "\n";
}