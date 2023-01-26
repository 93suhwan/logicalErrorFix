#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e17 + 7;
int N, K;
struct Point {
  long long x, y, id;
};
Point a[200005];
vector<Point> online;
Point nonline;
void line(int u, int v) {
  int cnt = 0;
  int diff = -1;
  for (int i = 1; i <= (int)(N); ++i)
    if (i != u) {
      if ((a[i].y - a[u].y) * (a[v].x - a[u].x) !=
          (a[v].y - a[u].y) * (a[i].x - a[u].x)) {
        cnt++;
        diff = i;
      }
    }
  if (cnt != 1) return;
  online.clear();
  for (int i = 1; i <= (int)(N); ++i)
    if (i != diff) {
      online.push_back(a[i]);
    }
  sort(online.begin(), online.end(), [&](Point x, Point y) {
    if (x.x == y.x) return x.y < y.y;
    return x.x < y.x;
  });
  nonline = a[diff];
}
double dist(Point u, Point v) {
  return sqrt((double)(u.x - v.x) * (u.x - v.x) +
              (double)(u.y - v.y) * (u.y - v.y));
}
int main() {
  scanf("%d%d", &N, &K);
  for (int i = 1; i <= (int)(N); ++i)
    scanf("%lld%lld", &a[i].x, &a[i].y), a[i].id = i;
  line(1, 2);
  line(1, 3);
  line(2, 3);
  double ret = INF;
  int start = -1;
  for (int i = 0; i < (int)(online.size()); ++i) {
    if (online[i].id == K) start = i;
  }
  if (start == -1) {
    ret =
        min(dist(nonline, online.front()) + dist(online.front(), online.back()),
            dist(nonline, online.back()) + dist(online.front(), online.back()));
  } else {
    vector<Point> order;
    for (int i = start; i >= 0; --i) {
      order.push_back(online[i]);
    }
    for (int i = start + 1; i < online.size(); ++i) {
      order.push_back(online[i]);
    }
    double cd = dist(online[start], online.front()) +
                dist(online.front(), online.back());
    ret = min(ret, cd + dist(online.back(), nonline));
    for (int i = 0; i < (int)(order.size() - 1); ++i) {
      ret = min(ret, cd - dist(order[i], order[i + 1]) +
                         dist(order[i], nonline) + dist(nonline, order[i + 1]));
    }
    order.clear();
    for (int i = start; i < online.size(); ++i) {
      order.push_back(online[i]);
    }
    for (int i = start - 1; i >= 0; --i) {
      order.push_back(online[i]);
    }
    cd = dist(online[start], online.back()) +
         dist(online.front(), online.back());
    ret = min(ret, cd + dist(online.front(), nonline));
    for (int i = 0; i < (int)(order.size() - 1); ++i) {
      ret = min(ret, cd - dist(order[i], order[i + 1]) +
                         dist(order[i], nonline) + dist(nonline, order[i + 1]));
    }
  }
  printf("%.8lf\n", ret);
  return 0;
}
