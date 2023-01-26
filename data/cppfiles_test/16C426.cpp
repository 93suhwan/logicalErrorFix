#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e18;
long long mx = -1;
long long mn = 1e18;
long long calpow(long long a, long long b, long long md) {
  long long mul = 1;
  while (b > 0) {
    if (b & 1) {
      mul = ((a % md) * (mul % md)) % md;
      b--;
    } else {
      a = ((a % md) * (a % md)) % md;
      b /= 2;
    }
  }
  return mul;
}
void solve() {
  long long i, j, n, q, a, b, m, k, ct = 0, sum = 0, flag = 0;
  string s;
  cin >> n;
  cin >> s;
  string t = s;
  sort(t.begin(), t.end());
  for (long long i = (0); i < (s.size()); i++) {
    if (s[i] != t[i]) ct++;
  }
  cout << ct;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << clock() * 1000.0 / CLOCKS_PER_SEC << 'm' << 's';
  return 0;
}
