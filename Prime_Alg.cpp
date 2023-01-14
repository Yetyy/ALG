#include <iostream>
using namespace std;

const int maxn = 10005;

int n, m;
int d[maxn], p[maxn], w[maxn][maxn];

void prim() {
	bool used[maxn];
	for (int i = 1; i <= n; i++) {
		d[i] = INT_MAX;
		used[i] = false;
	}
	d[1] = 0;
	p[1] = -1;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 1; j <= n; j++) {
            if (!used[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (d[v] == INT_MAX) {
            cout << "Graph is not connected." << endl;
            return;
        }
        used[v] = true;
        if (p[v] != -1) {
            cout << v << " " << p[v] << " " << d[v] << endl;
        }
        for (int to = 1; to <= n; to++) {
            if (w[v][to] < d[to]) {
                d[to] = w[v][to];
                p[to] = v;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        w[x][y] = w[y][x] = z;
    }

    prim();

    return 0;
}
