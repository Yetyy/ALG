#include <iostream>
#include <math.h>
using namespace std;
void Place(int* a, int k, int n, int r, bool* f) {
	if (r == k) {
		for (int i = 0; i < k; i++)
			cout << a[i];
		cout << '\n';
	}
	else {
		for (int i = 1; i < n; i++) {
			if (f[i] == false)
			{
				a[r] = i;
				f[i] = true;
				Place(a, k, n, r + 1, f);
				f[i] = false;
			}
		}
	}
}


int main()
{
	int n, k; cin >> n; cin >> k;
	bool* f = new bool[n];
	for (int i = 0; i < n; i++)
		f[i] = false;
	int* a = new int[k];
	Place(a, k, n, 0, f);
}