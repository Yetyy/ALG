#include <iostream>
using namespace std;

const int MAX_N = 100; // Максимальное количество предметов
int n;                // Количество предметов
int weight[MAX_N];    // Масса предметов
int value[MAX_N];     // Ценность предметов
int max_weight;       // Максимальная вместимость рюкзака

int* create_items(int n) {
    int* items = new int[n];
    return items;
}

int knapsack(int* items, int current_item, int remaining_weight) {
    if (current_item == n) {
        int total_value = 0;
        // Вычисляем общую ценность предметов в рюкзаке
        for (int i = 0; i < n; i++) {
            if (items[i] == 1) {
                total_value += value[i];
            }
        }
        return total_value;
    }
    int take = -1;
    if (remaining_weight >= weight[current_item]) {
        items[current_item] = 1;
        take = knapsack(items, current_item + 1, remaining_weight - weight[current_item]);
    }
    items[current_item] = 0;
    int not_take = knapsack(items, current_item + 1, remaining_weight);
    return max(take, not_take);
}

int main() {
    cin >> n;
    int* items = create_items(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
    cin >> max_weight;
    cout << "Максимальная ценность рюкзака: " << knapsack(items, 0, max_weight) << endl;
    delete[] items;
    return 0;
}

