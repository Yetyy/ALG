#include <iostream>
#include <set>
#include <utility>
using namespace std;

const int maxn = 10005;

typedef struct Point
{
    int x;
    int y;
} point;

point p[maxn];
set<pair<int, int> > s;
int n;

int judge(point p1, point p2, point p3)
{
    int flag = p1.x * p2.y + p3.x * p1.y + p2.x * p3.y - p3.x * p2.y - p2.x * p1.y - p1.x * p3.y;
    if (flag > 0) return 1;
    else if (flag == 0) return 2;
    else return 0;
}

int main()
{
    while (cin >> n && n)
    {
        for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

        s.clear();

        for (int i = 0; i < n; i++)
        {
            int t = 0;

            for (int j = 0; j < n; j++)
            {
                int flag = -1;
                if (i == j) continue;

                for (int k = 0; k < n; k++)
                {
                    if (k == i || k == j) continue;

                    if (flag == -1) flag = judge(p[i], p[j], p[k]);
                    else
                    {
                        int temp = judge(p[i], p[j], p[k]);
                        if (flag == temp || temp == 2) t = 1;
                        else
                        {
                            t = 0;
                            break;
                        }
                    }
                }

                if (t) s.insert(make_pair(p[j].x, p[j].y));
            }

            if (t) s.insert(make_pair(p[i].x, p[i].y));
        }

        set<pair<int, int> >::iterator it = s.begin();

        while (it != s.end())
        {
            printf("(%d, %d)\n", it->first, it->second);
            it++;
        }

    }

    return 0;
}
