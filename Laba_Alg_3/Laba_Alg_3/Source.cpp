#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
char kx, ky, pax, pay, pbx, pby;
int xx[8] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int yy[8] = { -1, 0, 1, -1, 0, 1, 1, -1 };
int min_l = 10;
void dfs(int** arr, int x, int y, int len)
{
	++len;
	for (int i = 0; i < 8; i++)//просмотреть 8 возможных позиций
	{
		if ((x + xx[i] > 0) && (x + xx[i] <= 8) && (y + yy[i] > 0) && (y + yy[i] <= 8) && (arr[x + xx[i]][y + yy[i]] == 0) && (len + 1 < min_l))//если есть смысл идти то
		{
			if ((x + xx[i] == pax) && (y + yy[i] == pay))
			{
				if (len+1 < min_l)
					min_l = len+1;
			}
			else//если не дошли до пешки
			{
				arr[x + xx[i]][y + yy[i]] = 1;//ќтметим клетку помеченной
				/*cout << len;
				cout << '\n';
				for (int i = 0; i < 9; i++)
				{
					for (int j = 0; j < 9; j++)
						cout << arr[i][j] << " ";
					cout << '\n';
				}
				cout << "\n**********************";*/
				dfs(arr, x + xx[i], y + yy[i], len);//вычисление длины пути и сравнение с min если попали в нужную точку
			}
		}
	}
	arr[x][y] = 0;
 }




int task()
{
	min_l = 10;
	bool* flag = new bool[64]{false};
	int a, b;
	int** m = new int*[9];
		for (int i = 0; i < 9; i++)
		{
			m[i] = new int[9];
			for (int j = 0; j < 9; j++)
				m[i][j] = 0;
		}
	
	m[pax - 1][pay + 1] = m[pax + 1][pay + 1] = 9;
	m[pbx - 1][pby + 1] = m[pbx + 1][pby + 1] = 9;
	dfs(m,kx, ky,-1);
	a = min_l;
	min_l = 10;
	//ƒо пешки ј король может добратьс€ минимум за а ходов, а до пешки B за b ходов.
	char t_pax= pax, t_pay= pay, t_pbx= pbx, t_pby= pby;
	pax = pbx; pay = pby;//путь от   до ¬
	dfs(m, kx, ky, -1);
	b = min_l;
	min_l = 10;
	kx = pbx; ky = pby;
	pax = t_pax; pay = t_pay;
	m[pbx - 1][pby + 1] = m[pbx + 1][pby + 1] = 0;// ¬ убита и не может атаковать
	dfs(m, kx, ky, -1);
	b += min_l;
	return a < b ? a : b;
}

int main() {
	fstream file("data.txt");
	for(int i=0; i<3; i++)
	{
		file >> kx >> ky >> pax >> pay >> pbx >> pby;//координаты корол€ и 2х пешек ј и B
		kx -= 'a'-1; ky -= '1'-1;
		pax -= 'a'-1; pay -= '1'-1;
		pbx -= 'a'-1; pby -= '1'-1;
		cout << task() << '\n';
	}

	std::cin.ignore();
	std::cin.get();
	
	return 0;
}