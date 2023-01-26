#include <bits/stdc++.h>
using namespace std;
int n, k;
const double pi = acos(-1);
struct point {
  int x, y;
} a[100000 + 10];
double dist[100000 + 10];
double ang[100000 + 10];
pair<double, int> b[100000 * 2 + 10];
double sqr(double x) { return x * x; }
bool check(double r) {
  int i, cnt = 0, ret = 0, now = 0;
  for (i = 1; i <= n; i++) {
    if (dist[i] > 2 * r) continue;
    double dang = acos(dist[i] / 2 / r);
    double la = ang[i] - dang - (1e-8);
    double lb = ang[i] + dang + (1e-8);
    if (la < -pi) la += 2 * pi;
    if (lb >= pi) lb -= 2 * pi;
    if (la > lb) now++;
    b[++cnt] = {la, -1};
    b[++cnt] = {lb, 1};
  }
  sort(b + 1, b + cnt + 1);
  ret = max(ret, now);
  for (i = 1; i <= cnt; i++) {
    now -= b[i].second;
    ret = max(ret, now);
  }
  return ret >= k;
}
double bs(double l, double r) {
  for (int i = 0; i < 100; i++) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  return l;
}
int main() {
  scanf("%d%d", &n, &k);
  int i, x, y;
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    if (!x && !y) {
      n--, k--;
      i--;
      continue;
    }
    a[i] = {x, y};
    dist[i] = sqrt(sqr(x) + sqr(y));
    ang[i] = atan2(y, x);
  }
  printf("%.10f\n", bs(0, 200000));
}
