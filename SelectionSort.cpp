#include <iostream>
using namespace std;

void choose(int* arr, int n)
{
    int min, tmp;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}
