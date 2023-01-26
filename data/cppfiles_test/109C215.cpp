#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const long long N = 3e5 + 10;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t, n;
  cin >> t;
  string s;
  while (t--) {
    cin >> n >> s;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long c = (long long)(s[i] - '0');
      if (c > 0) ans += c + (i != n - 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
