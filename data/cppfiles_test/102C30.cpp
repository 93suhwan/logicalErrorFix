#include <bits/stdc++.h>
using namespace std;
using T = pair<long long, long long>;
long long n, m;
string s;
T gpos(long long v) {
  long long x = 0, y = 0, u = 0, d = 0, l = 0, r = 0;
  for (long long i = 0; i <= v - 1; ++i) {
    auto &c = s[i];
    if (c == 'U')
      u = min(u, --x);
    else if (c == 'D')
      d = max(d, ++x);
    else if (c == 'L')
      l = min(l, --y);
    else if (c == 'R')
      r = max(r, ++y);
  }
  if (d - u >= n || r - l >= m) return {0, 0};
  return {1 - u, 1 - l};
}
void solve() {
  cin >> n >> m >> s;
  long long l = 1, r = s.size() + 1;
  while (l < r) {
    long long mid = l + r + 1 >> 1;
    long long v = gpos(mid).first;
    v ? l = mid : r = mid - 1;
  }
  auto [x, y] = gpos(l);
  if (!x)
    cout << "1 1\n";
  else
    cout << x << ' ' << y << '\n';
}
signed main() {
  cout.tie(0)->sync_with_stdio(0);
  long long _;
  for (cin >> _; _--;) solve();
  return 0;
}
