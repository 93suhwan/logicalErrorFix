#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
void fun(long long tt) {
  long long m, n;
  cin >> m >> n;
  string a;
  cin >> a;
  long long x = 0, y = 0;
  long long l = 0, r = 0, u = 0, d = 0;
  for (long long i = 0; i < a.size(); i++) {
    if (a[i] == 'L') {
      y--;
    } else if (a[i] == 'R') {
      y++;
    } else if (a[i] == 'D') {
      x--;
    } else {
      x++;
    }
    if (r - l + 1 == n) {
      if (y < l || y > r) break;
    } else {
      l = min(l, y);
      r = max(r, y);
    }
    if (u - d + 1 == m) {
      if (x > u || x < d) break;
    } else {
      u = max(u, x);
      d = min(d, x);
    }
  }
  cout << 1 + u << " " << 1 - l << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long tt = 1; tt <= t; tt++) {
    fun(tt);
  }
  return 0;
}
