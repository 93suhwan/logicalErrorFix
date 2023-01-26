#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int dp[2][100100], dp2[2][100100];
void clr(int pos, vector<int> &v) {
  for (auto x : v) dp[pos][x] = dp2[pos][x] = 0;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> val;
  int cur = 0, ans = 0;
  val.emplace_back(a[n - 1]);
  dp2[cur][a[n - 1]]++;
  for (int i = n - 2; i >= 0; i--) {
    cur ^= 1;
    vector<int> nval;
    for (auto x : val) {
      int dal = (a[i] + x - 1) / x;
      int cal = a[i] / dal;
      dp[cur][cal] =
          (dp[cur][cal] +
           ((dp[cur ^ 1][x] + 1LL * dp2[cur ^ 1][x] * (dal - 1) % mod) % mod) %
               mod) %
          mod;
      dp2[cur][cal] = (dp2[cur][cal] + dp2[cur ^ 1][x]) % mod;
      if (nval.size() == 0 || nval.back() != cal) nval.emplace_back(cal);
    }
    dp2[cur][a[i]] = (dp2[cur][a[i]] + 1) % mod;
    if (nval.size() == 0 || nval.back() != a[i]) nval.emplace_back(a[i]);
    for (auto x : nval) ans = (ans + dp[cur][x]) % mod;
    clr((cur ^ 1), val);
    val = nval;
  }
  clr(cur, val);
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
