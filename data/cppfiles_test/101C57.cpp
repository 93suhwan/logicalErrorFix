#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, mi, ma;
void solve() {
  long long k;
  cin >> n >> m >> k;
  long long x;
  set<long long> l, r;
  vector<long long> a, b, p;
  for (int i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
    l.insert(x);
  }
  for (int i = 0; i < m; i++) {
    cin >> x;
    b.push_back(x);
    r.insert(x);
  }
  long long y, ans = 0;
  vector<long long> u(n + 5, 0), v(m + 5, 0);
  map<long long, long long> u1[n + 5], v1[m + 5];
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    if (l.find(x) != l.end()) {
      if (r.find(y) != r.end()) continue;
      long long st = 0, dr = m - 1;
      long long h;
      while (st <= dr) {
        h = (st + dr) / 2;
        if (h == m - 1) break;
        if (b[h] < y && b[h + 1] > y) break;
        if (b[h] < y)
          st = h + 1;
        else
          dr = h - 1;
      }
      ans += v[h] - v1[h][x];
      v1[h][x]++;
      v[h]++;
      continue;
    }
    long long st = 0, dr = n - 1;
    long long h;
    while (st <= dr) {
      h = (st + dr) / 2;
      if (h == n - 1) break;
      if (a[h] < x && a[h + 1] > x) break;
      if (a[h] < x)
        st = h + 1;
      else
        dr = h - 1;
    }
    ans += u[h] - u1[h][y];
    u[h]++;
    u1[h][y]++;
    continue;
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
