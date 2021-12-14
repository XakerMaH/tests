/*
����������:
1)����������
2)������� ����
	1. ������� ����� ����
		1) �������� char ������� ����� ��� ����
			1.1 ���� ��� � push.back i, ���������������� � char
		2) ���������� ������� ������������ �����
			2.1. � ���������� ������� ������ �� ����� ������ �����
			2.2. �������� ����� ���������
			2.3. ���� ���, ����������� ������ ������� ����� � ������������� ������
				3.1. �������� = ������ ������� 
				3.2. ���� �������� != ����� ������� 
				3.3 ++ ��������
				3.4. ���� �����
					1) ��� ������ ��������� �����:
					   0 | 1 | 2 
					   ---------
					   3 | 4 | 5
					   ---------
					   6 | 7 | 8
					2) �����: ��������* |, | ��������* |, | ��������* 

			2.4. ���� i != 3, �� �����: ---------
		
	2. ��� ������� ��� ������ �����
		2.2. while(���� �� ����� �� ��� ���)
			������ ������� ������?
			������ ���������� � ����������
			������ � �� �� ��� ����
	3. ������� ���� ������
		3.1. ���������� ����
		3.2. while(������� �������� �� �����������)
			{
				�������� ����
				���� = ����
			}
		3.3. ������ �������� � ������� �� ���������� 

	4. ��� ��
		4.1. ��� � �������� �� ���� ��������� ���������� 
			������ ����� � ��������� �� ������������ � ������
		4.2. ��� � �������� �� ���� ��������� ����������
			������ ������� � ��������� �� ������������ � ������
		4.3. ����� ���������� ����, ���� �������� ��� ��������� ������

	5. ������ �������� ����
		5.1. system("cls"); ����� ������ ���� � ����� ������� ����
	6. ������� �������� ���� �� �����������
	7. ������� �������� �� ������
	8. ���� � ������������ ������� � �������� ����
		1) ����
		2) �������� �� ������ ��������
		3) ����������� � ���������� ���������� �������� true ��� false
		4) ���� � �������� ���� ����������
	9. ������� ����������
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
			cout << "\n\n�� ������ ������� �����?(��/���): ";
			cin >> againT;
		} while (againT != "��" and againT != "���");

		if (againT == "��")
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
		cout << "\n�������� ����: ";
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
					cout << "����������� ��������\n";
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
					cout << "����������� ��������\n";
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
					cout << "����������� ��������\n";
				}
			}

		}
		else
		{
			error = true;
			cout << "����������� ��������\n";
		}

	return(error);
}

void instructions(const  vector<vector<string>>& ins)
{
	cout << "\n����� ���������� � '��������-������'\n";
	cout << "����� ��� ������� ��������� � �������������� �������\n" << endl;
	show(ins);
	cout << "\n\n����� ������� ���, �������� ���� �� ������������ ���� � ������� ��� �����\n";
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