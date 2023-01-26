#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3, M = 2e5 + 3;
const int MOD[4] = {998244353, 937184173, 999976829, 891375269};
string s, t, w;
int n, m, pw[4][N], hs[4][N], ht[4], Z[N + M];
int add(int x, int y, int k) {
  x += y;
  while (x >= MOD[k]) x -= MOD[k];
  while (x < 0) x += MOD[k];
  return x;
}
int mul(int x, int y, int k) { return (x * 1LL * y) % MOD[k]; }
tuple<int, int, int, int> get_hash(int l, int r) {
  int h[4] = {0, 0, 0, 0};
  for (int j = 0; j < 4; ++j)
    h[j] = add(hs[j][r], -mul(hs[j][l - 1], pw[j][r - l + 1], j), j);
  return {h[0], h[1], h[2], h[3]};
}
void init() {
  cin >> s >> t;
  n = s.size(), m = t.size();
  w = " " + t + s, s = " " + s, t = " " + t;
  for (int j = 0; j < 4; ++j) {
    pw[j][0] = 1;
    for (int i = 1; i <= n; ++i) pw[j][i] = mul(pw[j][i - 1], 10, j);
  }
  for (int j = 0; j < 4; ++j) {
    for (int i = 1; i <= n; ++i)
      hs[j][i] = add(s[i] - '0', mul(hs[j][i - 1], 10, j), j);
  }
  for (int j = 0; j < 4; ++j) {
    for (int i = 1; i <= m; ++i) ht[j] = add(t[i] - '0', mul(ht[j], 10, j), j);
  }
  Z[1] = n + m;
  int l = 1, r = 1;
  for (int i = 2; i <= n + m; ++i) {
    if (i > r) {
      l = r = i;
      while (r <= n + m && w[r] == w[r - l + 1]) ++r;
      Z[i] = r - l;
      r--;
    } else {
      int k = i - l + 1;
      if (Z[k] < r - i + 1)
        Z[i] = Z[k];
      else {
        r = i;
        while (r <= n + m && w[r] == w[r - l + 1]) ++r;
        Z[i] = r - l;
        r--;
      }
    }
  }
}
void solve() {
  init();
  for (int i = 1; i + 2 * (m - 1) - 1 <= n; ++i) {
    auto [x, y, z, p] = get_hash(i, i + m - 2);
    auto [x2, y2, z2, p2] = get_hash(i + m - 1, i + 2 * m - 3);
    x += x2, y += y2, z += z2, p += p2;
    if (x == ht[0] && y == ht[1] && z == ht[2] && p == ht[3]) {
      cout << i << ' ' << i + m - 2 << '\n'
           << i + m - 1 << ' ' << i + 2 * m - 3;
      return;
    }
  }
  for (int i = 1; i + m - 1 <= n; ++i) {
    auto [x, y, z, p] = get_hash(i, i + m - 1);
    if (m - Z[i + m] > 0) {
      if (i - m + Z[i + m] > 0) {
        auto [x2, y2, z2, p2] = get_hash(i - m + Z[i + m], i - 1);
        x += x2, y += y2, z += z2, p += p2;
        if (x == ht[0] && y == ht[1] && z == ht[2] && p == ht[3]) {
          cout << i - m + Z[i + m] << ' ' << i - 1 << '\n'
               << i << ' ' << i + m - 1;
          return;
        }
        x -= x2, y -= y2, z -= z2, p -= p2;
      }
      if (i + 2 * m - Z[i + m] - 1 <= n) {
        auto [x2, y2, z2, p2] = get_hash(i + m, i + 2 * m - Z[i + m] - 1);
        x += x2, y += y2, z += z2, p += p2;
        if (x == ht[0] && y == ht[1] && z == ht[2] && p == ht[3]) {
          cout << i << ' ' << i + m - 1 << '\n'
               << i + m << ' ' << i + 2 * m - Z[i + m] - 1;
          return;
        }
        x -= x2, y -= y2, z -= z2, p -= p2;
      }
    }
    if (m - Z[i + m] - 1 > 0) {
      if (i - m + Z[i + m] + 1 > 0) {
        auto [x2, y2, z2, p2] = get_hash(i - m + Z[i + m] + 1, i - 1);
        x += x2, y += y2, z += z2, p += p2;
        if (x == ht[0] && y == ht[1] && z == ht[2] && p == ht[3]) {
          cout << i - m + Z[i + m] + 1 << ' ' << i - 1 << '\n'
               << i << ' ' << i + m - 1;
          return;
        }
        x -= x2, y -= y2, z -= z2, p -= p2;
      }
      if (i + 2 * m - Z[i + m] - 2 <= n) {
        auto [x2, y2, z2, p2] = get_hash(i + m, i + 2 * m - Z[i + m] - 2);
        x += x2, y += y2, z += z2, p += p2;
        if (x == ht[0] && y == ht[1] && z == ht[2] && p == ht[3]) {
          cout << i << ' ' << i + m - 1 << '\n'
               << i + m << ' ' << i + 2 * m - Z[i + m] - 2;
          return;
        }
        x -= x2, y -= y2, z -= z2, p -= p2;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
