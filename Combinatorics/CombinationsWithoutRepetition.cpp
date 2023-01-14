#include <iostream>
#include <math.h>

int** CreateArr(int n, int k) {
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[k];
    return a;
}

using namespace std;
int main()
{
    int n, k; cin >> n; cin >> k;

    int** a = CreateArr(n, k);
    for (int i = 0; i < n; i++)
        a[i][0] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j < k; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];

    /*for(int i=0; i<n; i++){
        cout<<"\n";
        for(int j=0; j< k; j++)
            cout<<a[i][j];
    }*/
    cout << a[n - 1][k - 1];
}