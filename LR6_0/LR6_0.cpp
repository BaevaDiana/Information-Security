
#include  <iostream>   
#include <vector>  
#include <string>
#include <ctime>
using namespace std;

//Составить программу, которая проверяет, верно ли что компьютерная система CS = (n, m, A, LS, LO) соответствует критерию безопасности Белла – Лападулы.

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, m; // число субъектов(программ обработчиков) n и число объектов(содержат информацию) m 
	cout << "Введите число субъектов и объектов через строку" << endl;
	cin >> n >> m;
	int inp = 0;
	int i, j;

	vector < vector <string> > RW(n, vector <string>(m));
	vector <int> LS(n); // уровни допуска субъектов S
	vector <int> LO(m); // уровень секретности объектов O
	srand(time(0));
	cout << "Генерация RW" << endl;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			if (inp == 0)
				cin >> RW[i][j];

		}
	cout << "Вывод сгенерированной матрицы на права записи и чтения" << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << RW[i][j] << ' ';
		cout << endl;
	}
	cout << "Генерация LS" << endl;

	for (i = 0; i < n; i++)
	{
		if (inp == 0)
			cin >> LS[i];
	}
	cout << "Генерация LO" << endl;

	for (i = 0; i < m; i++)
	{
		if (inp == 0)
			cin >> LO[i];

	}
	cout << "Вывод сгенерированного массива уровней допуска субъектов S" << endl;

	for (i = 0; i < n; i++)
		cout << LS[i] << " ";

	cout << endl;
	cout << "Вывод сгенерированного массива уровней секретности объектов O" << endl;

	for (i = 0; i < m; i++)
		cout << LO[i] << " ";
	cout << endl;

	bool ok = true;
	for (i = 0; i < n; i++)
	{
		if (ok == false)
			break;
		for (j = 0; j < m; j++)
		{
			// > w - ok
			// <= r - ok
			// <= w - neok
			// > r - neok
			if (!((LS[i] >= LO[j] && RW[i][j] == "W") || (LS[i] <= LO[j] && RW[i][j] == "R")))
			{
				ok = false;
				break;
			}
		}
	}
	if (ok)
		cout << "Система соответствует критерию безопасности Белла - Лападулы" << endl;
	else
		cout << "Система НЕ соответствует критерию безопасности Белла - Лападулы" << endl;
}