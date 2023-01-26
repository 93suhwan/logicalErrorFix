#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
const long long MAXN = 2e5 + 5;
void solve() {
  long long n, cnt = 1, res = 0;
  cin >> n;
  for (long long i = 1; i <= n; i++, cnt++) {
    long long x;
    cin >> x;
    if (x > cnt) {
      res += (x - cnt);
      cnt += (x - cnt);
    }
  }
  cout << res << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  long long _ = 1;
  cin >> _;
  for (_; _--;) {
    solve();
  }
  return 0;
}
