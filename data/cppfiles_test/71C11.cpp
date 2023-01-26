#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y;
  bool operator<(const node a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
  bool operator==(const node a) const { return x == a.x && y == a.y; }
} mp[200005], ts;
long double dis(int i, int j) {
  node a = mp[i], b = mp[j];
  long long sx = a.x - b.x, sy = a.y - b.y;
  return sqrt(sx * sx + sy * sy);
}
long double dis(vector<int> v) {
  int las = 0;
  long double s = 0;
  for (auto it = v.begin(); it != v.end(); it++) {
    if (las) s += dis(las, *it);
    las = *it;
  }
  return s;
}
int n, st;
bool chk(node a, node b, node s) {
  return (a.y - s.y) * (b.x - s.x) == (b.y - s.y) * (a.x - s.x);
}
int main() {
  scanf("%d%d", &n, &st);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &mp[i].x, &mp[i].y);
  if (n == 3) {
    int xx = 1 + (st == 1), yy = 2 + (st <= 2);
    printf("%.9Lf", min(dis(st, xx) + dis(xx, yy), dis(st, yy) + dis(yy, xx)));
  }
  ts = mp[st];
  sort(mp + 1, mp + n + 1);
  n = unique(mp + 1, mp + n + 1) - mp - 1;
  if (!chk(mp[2], mp[3], mp[1]) && !chk(mp[2], mp[4], mp[1]) &&
      !chk(mp[3], mp[4], mp[1]))
    swap(mp[1], mp[n]);
  else if (!chk(mp[1], mp[3], mp[2]) && !chk(mp[1], mp[4], mp[2]) &&
           !chk(mp[3], mp[4], mp[2]))
    swap(mp[2], mp[n]);
  else
    for (int i = 3; i <= n; i++)
      if (!chk(mp[1], mp[2], mp[i])) swap(mp[i], mp[n]);
  sort(mp + 1, mp + n);
  st = find(mp + 1, mp + n + 1, ts) - mp;
  if (st == n)
    printf("%.9Lf", dis(1, n - 1) + min(dis(1, n), dis(n - 1, n)));
  else {
    long double ans = 1e18;
    for (int i = 1; i <= n - 2; i++)
      ans = min(
          {dis({st, i, 1, n, i + 1, n - 1}), dis({st, i + 1, n - 1, n, i, 1}),
           dis({st, i, n}) + dis(1, n - 1) + min(dis(n, 1), dis(n, n - 1)),
           dis({1, i, n, i + 1, n - 1}) + min(dis(st, 1), dis(st, n - 1)),
           ans});
    printf("%.9Lf",
           min(min(dis(st, 1) + dis(n - 1, n), dis(st, n - 1) + dis(1, n)) +
                   dis(1, n - 1),
               ans));
  }
  return 0;
}
