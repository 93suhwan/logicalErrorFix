#include <bits/stdc++.h>
using namespace std;
const long long int mma = 1e6 + 10;
const long long int mod = 998244353;
vector<vector<long long int>> p;
long long int n, m;
bool solve(long long int x) {
  vector<bool> c(m);
  bool check = 0;
  for (int i = 0; i < n; i++) {
    long long int cf = 0;
    for (int j = 0; j < m; j++) {
      if (p[i][j] >= x) {
        cf++;
        c[j] = 1;
      }
    }
    if (cf > 1) check = 1;
  }
  if (!check) {
    return 0;
  }
  bool checkagain = 0;
  for (bool b : c)
    if (!b) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int dp1[n + 2], dp2[n + 2];
    fill(dp1, dp1 + n + 2, 0);
    fill(dp2, dp2 + n + 2, 0);
    dp1[0] = 1;
    long long int ans = -1;
    for (int j = 0; j < n; j++) {
      long long int x;
      cin >> x;
      dp1[x + 1] = (2 * (dp1[x + 1]));
      dp1[x + 1] = (dp1[x + 1] + dp1[x]);
      if (x > 0) {
        dp2[x - 1] = (2 * (dp2[x - 1]));
        dp2[x - 1] = (dp2[x - 1] + dp1[x - 1]);
        dp2[x - 1] %= mod;
      }
      dp2[x + 1] = (2 * (dp2[x + 1]));
      dp2[x + 1] %= mod;
      dp1[x + 1] %= mod;
    }
    for (int i = 0; i < n + 2; i++) {
      ans += dp1[i];
      ans += dp2[i];
      if (ans >= mod) ans -= mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
