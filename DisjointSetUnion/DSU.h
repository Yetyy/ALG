#include <vector>
using std::vector;
class DSU {
private:
    vector<int> parent, rank;
    int findSet(int u) {
        return u == parent[u] ? u : (parent[u] = findSet(parent[u]));
    }

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    bool sameSet(int u, int v) {
        return findSet(u) == findSet(v);
    }

    void unite(int u, int v) {
        int pu = findSet(u), pv = findSet(v);
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pu] = pv;
            if (rank[pu] == rank[pv])
                rank[pv]++;
        }
    }
};