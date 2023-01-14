#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10000;

struct Point {
    double x, y;
} point[maxn];

int n;

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmpX(Point a, Point b) {
    return a.x < b.x;
}

bool cmpY(Point a, Point b) {
    return a.y < b.y;
}

pair<Point, Point> findClosestPair(int left, int right) {
    if (left == right) return make_pair(point[left], point[left]);
    if (left + 1 == right) return make_pair(point[left], point[right]);

    int mid = (left + right) / 2;
    auto left_pair = findClosestPair(left, mid);
    auto right_pair = findClosestPair(mid + 1, right);

    double d = min(dist(left_pair.first, left_pair.second), dist(right_pair.first, right_pair.second));
    Point mid_point = point[mid];
    pair<Point, Point> ans = left_pair;
    if (dist(right_pair.first, right_pair.second) < d) ans = right_pair;

    Point strip[right - left + 1];
    int j = 0;
    for (int i = left; i <= right; i++) {
        if (abs(point[i].x - mid_point.x) < d) {
            strip[j++] = point[i];
        }
    }

    sort(strip, strip + j, cmpY);

    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && strip[k].y - strip[i].y < d; k++) {
            if (dist(strip[i], strip[k]) < d) {
                d = dist(strip[i], strip[k]);
                ans = make_pair(strip[i], strip[k]);
            }
        }
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> point[i].x >> point[i].y;
    }

    sort(point, point + n, cmpX);

    auto ans = findClosestPair(0, n - 1);
    cout << ans.first.x << " " << ans.first.y << endl;
    cout << ans.second.x << " " << ans.second.y << endl;
    cout << dist(ans.first, ans.second) << endl;
    return 0;
}