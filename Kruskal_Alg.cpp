#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100;

int n;
int dist[N][N], path[N][N];

int main()
{
    cin >> n;
    // Инициализация массива dist
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    // Инициализация массива path
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            path[i][j] = i;

    // Поиск кратчайших путей между всеми парами вершин
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    // Вывод результата
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}