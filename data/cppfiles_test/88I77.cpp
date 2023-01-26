#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long N = 200005;
inline void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n + 2);
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  string ans = "NO";
  if (n % 2 == 0)
    ans = "YES";
  else {
    long long in = 0, de = 0;
    for (long long i = 2; i <= n; ++i) {
      in += (a[i] > a[i - 1]);
      de += (a[i] < a[i - 1]);
    }
    if ((in != n - 1) && (de != n - 1)) ans = "YES";
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
