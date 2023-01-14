#include <iostream>
using namespace std;

const int MAX_N = 20; // Максимальное количество городов
int n;                // Количество городов
int dist[MAX_N][MAX_N]; // Матрица расстояний между городами

// Функция для выделения памяти для массива маршрута
int* create_route(int n) {
    int* route = new int[n];
    return route;
}

// Функция для вычисления длины маршрута
int get_route_length(int* route) {
    int length = 0;
    for (int i = 0; i < n - 1; i++) {
        length += dist[route[i]][route[i + 1]];
    }
    length += dist[route[n - 1]][route[0]]; 
    return length;
}

// Функция для генерации всех возможных маршрутов
void generate_routes(int* route, int current_city, int remaining_cities) {
    if (remaining_cities == 0) {
        // Выводим длину маршрута
        cout << "Длина маршрута: " << get_route_length(route) << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        bool city_visited = false;
        // Проверяем, был ли город уже посещен
        for (int j = 0; j < n - remaining_cities; j++) {
            if (route[j] == i) {
                city_visited = true;
                break;
            }
        }
        if (!city_visited) {
            route[n - remaining_cities] = i;
            generate_routes(route, i, remaining_cities - 1);
        }
    }
}

int main() {
    cin >> n;
    // Ввод матрицы расстояний между городами
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }
    int* route = create_route(n);
    generate_routes(route, 0, n);
    delete[] route;
    return 0;
}