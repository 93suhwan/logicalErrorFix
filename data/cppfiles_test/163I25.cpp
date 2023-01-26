#include <bits/stdc++.h>
#pragma GCC optimize("O4,unroll-loops,no-stack-protector")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long po(long long xx, long long yy) {
  if (yy == 0) return 1;
  if (yy == 1) return xx % 1000000007;
  long long zz = po(xx % 1000000007, yy / 2);
  long long ww = (zz * zz) % 1000000007;
  if (yy % 2 == 1) return (ww * xx % 1000000007) % 1000000007;
  return ww;
}
struct state {
  int x, y, dx, dy;
  state(int a, int b, int c, int d) {
    x = a;
    y = b;
    dx = c;
    dy = d;
  }
};
bool operator<(state a, state b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  if (a.dx != b.dx) return a.dx < b.dx;
  return a.dy < b.dy;
}
map<state, int> vis;
long long val(long long a, long long b) {
  return (a % 1000000007) * po(b % 1000000007, 1000000007 - 2) % 1000000007;
}
vector<int> v;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    v.clear();
    vis.clear();
    int n, m, x, y, gx, gy, p;
    cin >> n >> m >> x >> y >> gx >> gy >> p;
    long long P = val(p, 100), Q = val(100 - p, 100);
    int dx = 1, dy = 1;
    if (x == n || x == 1) dx = -dx;
    if (y == m || y == 1) dy = -dy;
    int ox = x, oy = y, odx = dx, ody = dy;
    int cnt = 0, cyc = 0, ii = 0;
    for (int i = 1;; i++) {
      if (x == n) dx = -1;
      if (x == 1) dx = 1;
      if (y == m) dy = -1;
      if (y == 1) dy = 1;
      int last = vis[state(x, y, dx, dy)];
      if (last != 0) {
        cyc = i - last;
        ii = last;
        break;
      }
      vis[state(x, y, dx, dy)] = i;
      if (x == gx || y == gy) {
        cnt++;
        v.push_back(i);
      }
      if (x == n) dx = -1;
      if (x == 1) dx = 1;
      if (y == m) dy = -1;
      if (y == 1) dy = 1;
      x += dx;
      y += dy;
    }
    long long ans = 0;
    int len = v.size();
    for (int i = 0; i < len; i++) {
      long long left, right;
      long long leftup = v[i] * P % 1000000007 * po(Q, i) % 1000000007;
      long long leftdn = 1 - po(Q, cnt) + 1000000007;
      long long rightup = cyc * P % 1000000007 * po(Q, i) % 1000000007 *
                          po(Q, cnt) % 1000000007;
      long long rightdn = (1 - po(Q, cnt) + 1000000007) *
                          (1 - po(Q, cnt) + 1000000007) % 1000000007;
      left = val(leftup, leftdn);
      right = val(rightup, rightdn);
      ans += (left + right) % 1000000007;
      ans %= 1000000007;
    }
    cout << "#";
    cout << (ans - val(1, 1) + 1000000007) % 1000000007 << "\n";
  }
}
