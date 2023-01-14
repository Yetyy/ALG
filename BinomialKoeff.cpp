#include <iostream>
using namespace std;

// ������� ��� ���������� ������������ �������������
void binomialCoefficients(int n) {
    int C[n + 1][n + 1];

    // ������������� ������� ������
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = 0;
        }
    }

    // ���������� ������� ������������� ��������������
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

    // ����� ������������ �������������
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j
            j <= i; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    binomialCoefficients(n);

    return 0;
}