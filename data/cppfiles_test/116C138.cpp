#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i;
  cin >> n;
  vector<long long> v(n);
  for (i = (0); i < (n); i++) cin >> v[i];
  long long ans = 0;
  vector<long long> dp1(n + 2, 0);
  vector<long long> dp2(n + 2, 0);
  for (auto x : v) {
    if (x == 0) {
      dp1[1] = ((2 * dp1[1]) % 998244353LL + 1) % 998244353LL;
      dp2[1] = (2 * dp2[1]) % 998244353LL;
    } else if (x == 1) {
      dp1[2] = ((dp1[2] + dp1[1]) % 998244353LL + dp1[2]) % 998244353LL;
      dp2[0] = ((2 * dp2[0]) % 998244353LL + 1) % 998244353LL;
      dp2[2] = (2 * dp2[2]) % 998244353LL;
    } else {
      dp1[x + 1] = ((2 * dp1[x + 1]) % 998244353LL + dp1[x]) % 998244353LL;
      dp2[x - 1] = ((2 * dp2[x - 1]) % 998244353LL + dp1[x - 1]) % 998244353LL;
      dp2[x + 1] = (2 * dp2[x + 1]) % 998244353LL;
    }
  }
  for (i = (0); i < (n + 1); i++) ans = (ans + dp1[i]) % 998244353LL;
  for (i = (0); i < (n + 1); i++) ans = (ans + dp2[i]) % 998244353LL;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
