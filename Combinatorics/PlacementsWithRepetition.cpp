#include <iostream>
#include <math.h>
using namespace std;
void Place(int* a, int k, int n, int r) {
	if (r == k) {
		for (int i = 0; i < k; i++)
			cout << a[i];
		cout << '\n';
	}
	else {
		for (int i = 1; i < n; i++) {
			a[r] = i;
			Place(a, k, n, r + 1);

		}
	}
}


int main()
{
	int n, k; cin >> n; cin >> k;

	int* a = new int[k];
	Place(a, k, n, 0);
}