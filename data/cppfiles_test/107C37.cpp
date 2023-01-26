#include <bits/stdc++.h>
using namespace std;
const int N = 205;
struct point {
  int x, y;
  point() {}
  point(int _x, int _y) { x = _x, y = _y; }
  point operator-(const point& b) const { return point(x - b.x, y - b.y); }
};
pair<long long, long long> add(pair<long long, long long> a,
                               pair<long long, long long> b) {
  return {a.first + b.first, a.second + b.second};
}
long long cross(point a, point b) { return 1ll * a.x * b.y - 1ll * a.y * b.x; }
point a[N];
pair<long long, long long> f[N][N];
int n, K;
bool check(long long x) {
  for (int len = 3; len <= n; ++len)
    for (int l = 1; l + len - 1 <= n; ++l) {
      int r = l + len - 1;
      f[l][r] = {-1e9, 0};
      for (int k = l + 1; k < r; ++k) {
        pair<long long, long long> c = add(f[l][k], f[k][r]);
        c.second += cross(a[k] - a[l], a[r] - a[l]);
        if (c.second >= x) c.second = 0, c.first++;
        f[l][r] = max(f[l][r], c);
      }
    }
  return f[1][n].first >= K;
}
signed main() {
  cin >> n >> K;
  ++K;
  for (int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
  long long l = 0, r = 1e18;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l;
}
