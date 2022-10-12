#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//дан гамильтонов граф - граф,содержащий гамильтонов цикл - цикл,который проходит через все вершины графа,причём один раз
//минимальное количество сирен в наборе, удовлетворяющее условиям безопасности - количество компонент связности 

vector<int> g[1000];//списки смежности
bool used[1000];
vector<int> comp;//вектор компонент связности
vector<int> power;//вектор вершин
int matrica[1000][1000];

//обход в глубину
void dfs(int v)
{
    used[v] = true;
    comp.push_back(v);
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        if (v == i)
            continue;
        int to = g[v][i];
        if (!used[to] && abs(power[v] - matrica[v][i]) >= 0)
        {
            if (power[v] < power[i] - power[v])
                power[v] = power[i] - power[v];
            dfs(to);
        }
    }
}

//поиск компонент связности
int find_comps(int n1) 
{
    int i,ans = 0;
    for (i = 0; i < n1; ++i)
        used[i] = false;
    for (i = 0; i < n1; ++i)
        if (!used[i]) 
        {
            comp.clear();
            dfs(i);
           //Вывод компонент связности
           //cout << "Component:";
            //for (size_t j = 0; j < comp.size(); ++j)
                //cout << ' ' << ++comp[j]; 
           //cout << endl;
        }
    ans = comp.size();
    return ans;
}

int main()
{
    ifstream input;
    ofstream output;
    input.open("alarm_in.txt");
    output.open("alarm_out.txt");

    int n1,i,a,b,c;
    if (!input.eof())
    {
        input >> n1;
        for (i = 0; i < n1; i++)
        {
            input >> a;
            power.push_back(a);
        }
    }
    while (!input.eof())
    {
        input >> a; 
        input >> b; 
        input >> c;
        g[a].push_back(b);
        matrica[a][b] = c;
    }
    input.close();
    output << find_comps(n1);
}
