#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void bruteForce(Point* points, int n) {
    double min_dist = INFINITY;
    Point p1, p2;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(points[i], points[j]);
            if (dist < min_dist) {
                min_dist = dist;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }
    cout << "Closest points: (" << p1.x << "," << p1.y << ") and (" << p2.x << "," << p2.y << ")" << endl;
    cout << "Distance: " << min_dist << endl;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;
    Point* points = new Point[n];
    cout << "Enter the coordinates of the points:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    bruteForce(points, n);
    return 0;
}