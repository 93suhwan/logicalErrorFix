#include <bits/stdc++.h>
using namespace std;
long long dp[int(1e5 + 2)][2];
int a[int(1e5 + 2)];
vector<int> v[2];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int mod = 998244353;
  int t;
  cin >> t;
  while (t--) {
    v[0].clear();
    v[1].clear();
    for (int i = 0; i < int(1e5 + 2); i++) dp[i][0] = dp[i][1] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      int one = i % 2;
      dp[a[i]][one] = 1;
      v[one].push_back(a[i]);
      for (auto x : v[1 - one]) {
        int k = a[i] / x;
        if (a[i] % x != 0) k++;
        int x_ = a[i] / k;
        if (dp[x_][one] == 0) v[one].push_back(x_);
        dp[x_][one] += dp[x][1 - one];
        ans = (ans + (i + 1) * dp[x][1 - one] * (k - 1)) % mod;
        dp[x][1 - one] = 0;
      }
      v[1 - one].clear();
    }
    cout << ans << "\n";
  }
}
