#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long INF = 1e18;
void solve() {
  long long n;
  string ans, s;
  cin >> n >> s;
  ans = s;
  long long f = 0;
  for (long long i = 1; i < n - 2; i++) {
    cin >> s;
    if (ans[ans.size() - 1] == s[0]) {
      ans += s[1];
    } else {
      ans += s;
      f = 1;
    }
  }
  if (!f) ans += "a";
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
