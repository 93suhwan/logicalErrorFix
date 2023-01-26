#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5;
const double pi = acos(-1.0);
struct Point {
  double x, y;
  void Scan() { scanf("%lf %lf", &x, &y); }
} ver[MAXN + 5];
struct msg {
  double ang;
  int v;
  bool operator==(const msg &a) { return ang == a.ang && v == a.v; }
  void Print() { printf("%.7lf %d\n", ang, v); }
} ope[4 * MAXN + 5];
int Tail;
int n, K;
bool cmp(msg a, msg b) { return (a.ang == b.ang ? a.v > b.v : a.ang < b.ang); }
double len(Point a) { return sqrt(a.x * a.x + a.y * a.y); }
int Check(double r) {
  int sum = 0;
  Tail = 0;
  for (int i = 1; i <= n; i++) {
    if (ver[i].x == 0 && ver[i].y == 0) {
      ++sum;
      continue;
    }
    double d = len(ver[i]);
    if (d > 2 * r) continue;
    double theta = acos(d / (2 * r));
    double delta = atan2(ver[i].y, ver[i].x);
    double L = delta - theta, R = delta + theta;
    if (L < 0) {
      L += 2 * pi;
      R += 2 * pi;
    }
    if (R <= 2 * pi) {
      ope[++Tail] = msg{L, 1};
      ope[++Tail] = msg{R, -1};
    } else {
      ope[++Tail] = msg{L, 1};
      ope[++Tail] = msg{2 * pi, -1};
      ope[++Tail] = msg{0, 1};
      ope[++Tail] = msg{R - 2 * pi, -1};
    }
  }
  sort(ope + 1, ope + Tail + 1, cmp);
  int ret = sum;
  for (int i = 1; i <= Tail; i++) {
    sum += ope[i].v;
    ret = max(ret, sum);
  }
  return ret;
}
int main() {
  scanf("%d %d", &n, &K);
  for (int i = 1; i <= n; i++) ver[i].Scan();
  double L = 0, R = 2e5;
  for (double mid; R - L > 1e-8;) {
    mid = (L + R) / 2.0;
    if (Check(mid) >= K)
      R = mid;
    else
      L = mid;
  }
  printf("%.7lf\n", R);
  return 0;
}
