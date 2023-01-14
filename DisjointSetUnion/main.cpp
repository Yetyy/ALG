#include <iostream>
#include "DSU.h"

int main() {

    DSU n1(7);

    n1.unite(1, 2);
    n1.unite(3, 4);
    n1.unite(1, 4);

    int t = 1;
    for (size_t i = 1; i < 7; i++)
    {
        if (n1.sameSet(t, i))
            std::cout << i;
    }
    std::cin.get();
    return 0;
}
