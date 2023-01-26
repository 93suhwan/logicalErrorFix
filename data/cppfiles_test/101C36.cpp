#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void solve() {
  long long n, m, K;
  n = read();
  m = read();
  K = read();
  vector<long long> a(n), b(m);
  vector<pair<long long, long long> > c, d;
  for (long long i = 0; i < n; ++i) a[i] = read();
  for (long long i = 0; i < m; ++i) b[i] = read();
  for (long long i = 0; i < K; ++i) {
    long long x, y;
    x = read();
    y = read();
    long long f1 = binary_search(a.begin(), a.end(), x);
    long long f2 = binary_search(b.begin(), b.end(), y);
    assert(f1 || f2);
    if (f1 && f2) {
    } else if (f1) {
      long long _y = lower_bound(b.begin(), b.end(), y) - b.begin();
      c.push_back({x, _y});
    } else {
      long long _x = lower_bound(a.begin(), a.end(), x) - a.begin();
      d.push_back({_x, y});
    }
  }
  static map<long long, long long> ma[(long long)1e6 + 1],
      mb[(long long)1e6 + 1];
  static long long sa[(long long)1e6 + 1], sb[(long long)1e6 + 1];
  for (auto [x, _y] : c) {
    ma[_y][x]++;
    sa[_y]++;
  }
  for (auto [_x, y] : d) {
    mb[_x][y]++;
    sb[_x]++;
  }
  long long ans = 0;
  for (auto [x, _y] : c) {
    ans += sa[_y] - ma[_y][x];
  }
  for (auto [_x, y] : d) {
    ans += sb[_x] - mb[_x][y];
  }
  cout << ans / 2 << "\n";
  for (auto [x, _y] : c) {
    ma[_y].clear();
    sa[_y]--;
  }
  for (auto [_x, y] : d) {
    mb[_x].clear();
    sb[_x]--;
  }
}
int32_t main() {
  for (long long T = read(); T; T--) solve();
  return 0;
}
