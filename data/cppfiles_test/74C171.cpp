#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long N = 3e5 + 5, M = N * 2;
const double PI = acos(-1);
long long mod = 1e9 + 7;
long long n, m, k, S, T;
set<long long> ans;
long long a, b;
void solve() {
  ans.clear();
  cin >> a >> b;
  if ((a + b) % 2) {
    long long n = (a + b) / 2, m = n + 1;
    for (long long i = 0; i <= n and i <= a; ++i) {
      if (a - i <= m) ans.insert(n - i + a - i);
    }
    for (long long i = 0; i <= m and i <= a; ++i) {
      if (a - i <= n) ans.insert(m - i + a - i);
    }
    cout << ans.size() << "\n";
    for (auto first : ans) cout << first << ' ';
    cout << "\n";
  } else {
    long long n = (a + b) / 2;
    for (long long i = 0; i <= n and i <= a; ++i) {
      if (a - i <= n) ans.insert(n - i + a - i);
    }
    cout << ans.size() << "\n";
    for (auto first : ans) cout << first << ' ';
    cout << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
