#include <iostream>
#include <string>

bool correct(int* arr,int m)
{
	bool rule_1=false, rule_2=false;
	int i=0,count_1=0;
	while(!rule_1 && i<m-3)
	{
		if (arr[i] == 1 && arr[i + 1] == 1 && arr[i + 2] == 1)
			rule_1 = true;
		if (arr[i] == 1) count_1++;
	i++;
	}
	if (count_1 % 3 == 0) rule_2 = true;
	return rule_1 + rule_2;

}
void posl(int k,int* arr,int m)
{
	if (k == m)
	{
		bool print = false;
		if (correct(arr, m))
		for (int i = 0; i < m; i++)
		{
			std::cout << arr[i];
			print = true;
		}
		if (print) std::cout << "\n";

	}
	else
		for (int i = 0; i <= 1; i++)
		{
			arr[k] = i;
			posl(k + 1, arr,m);
		}
}

int main()
{
	int m = 0;
	std::cin >> m;
	int* arr = new int[m];
	for (int i = 0; i < m; i++)
		arr[i] = 0;
	posl(0,arr,m);
	std::cin.ignore(255);
	std::cin.get();
return 0;
}