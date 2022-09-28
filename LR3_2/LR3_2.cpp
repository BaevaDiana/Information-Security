//Написать программу, которая для заданной строки находит в ней подстроку, имеющую наибольшую разнообразность.
//Если таких строк несколько, то программа находит ту, которая является наименьшей в лексикографическом порядке.

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	string s; int i, j, count = 0, ind;
	ifstream f("input.txt");
	vector <int> res; //вектор индексов
	while (!f.eof())
	{
		getline(f, s);
		for (i = 0; i < s.size(); i++)
		{
			for (j = 1; j < s.size(); j++)//проверка на одинаковые символы
			{
				if (s[i] == s[j])
				{
					count++;
					ind = j;
				}
			}

			if (count == 0)
			{
				if (find(res.begin(), res.end(), ind) == res.end())
					res.push_back(i);
			}
			else
			{
				count = 0;
				if (find(res.begin(), res.end(), ind) == res.end())
					res.push_back(ind);
			}

		}
	}
	sort(res.begin(), res.end());//сортировка в лексикографическом порядке
	ofstream h("output.txt");
	for (i = 0; i < res.size(); i++)
	{
		h << s[res[i]];
	}
	f.close();
	h.close();
}

