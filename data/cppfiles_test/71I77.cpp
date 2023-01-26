#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const double eps = 1e-10;
struct Point {
  int x, y, id;
} p1[N];
int n, m, s, p, l, r, a, b;
bool ok[N];
double ans, delta;
bool cmp(Point i, Point j) {
  if (i.x != j.x) return i.x < j.x;
  return i.y < j.y;
}
inline bool check(Point i, Point j, Point k) {
  return 1ll * (j.x - i.x) * (k.y - j.y) == 1ll * (k.x - j.x) * (j.y - i.y);
}
inline double dis(int i, int j) {
  return sqrt(1.0 * (p1[i].x - p1[j].x) * (p1[i].x - p1[j].x) +
              1.0 * (p1[i].y - p1[j].y) * (p1[i].y - p1[j].y));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &p1[i].x, &p1[i].y), p1[i].id = i;
  if (n == 3) {
    double tmp[3];
    ans = dis(1, 2) + dis(2, 3) + dis(3, 1);
    for (int i = 1, j = 0; i <= 3; ++i) {
      if (i != m) tmp[++j] = dis(i, m);
    }
    ans -= max(tmp[1], tmp[2]);
    printf("%lf\n", ans);
    return 0;
  }
  sort(p1 + 1, p1 + n + 1, cmp);
  for (int i = 1; i <= n; ++i)
    if (p1[i].id == m) s = i;
  p = 0;
  ok[1] = ok[n] = false;
  for (int i = 2; i < n; ++i) ok[i] = check(p1[i - 1], p1[i], p1[i + 1]);
  for (int i = 2; i < n; ++i)
    if (!ok[i - 1] && !ok[i] && !ok[i + 1]) p = i;
  if (!p) {
    if (!ok[2])
      p = 1;
    else
      p = n;
  }
  if (p != 1)
    a = 1;
  else
    a = 2;
  if (p != n)
    b = n;
  else
    b = n - 1;
  if (p != s) {
    if (s > 1 && s < n) {
      l = s - 1, r = s + 1;
      ans = dis(a, l) + dis(l, p) + dis(p, b) + dis(s, b);
      delta =
          dis(l, s) + dis(a, p) + dis(r, p) - dis(r, s) - dis(p, b) - dis(l, p);
      if (delta < -eps) ans += delta;
    } else if (s == 1) {
      r = s + 1;
      ans = dis(s, b) + dis(p, b);
      delta = dis(s, p) + dis(p, r) - dis(s, r) - dis(b, p);
      if (delta < -eps) ans += delta;
    } else {
      l = s - 1;
      ans = dis(s, a) + dis(p, a);
      delta = dis(s, p) + dis(p, l) - dis(s, l) - dis(a, p);
      if (delta < -eps) ans += delta;
    }
  } else
    ans = dis(a, b) + min(dis(a, p), dis(b, p));
  printf("%lf\n", ans);
  return 0;
}
