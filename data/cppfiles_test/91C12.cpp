#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long n, a[N], dp[2][N], mod = 998244353;
bool vis[N];
vector<int> v[2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    long long mn = 1e9;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
      int idx = i % 2;
      dp[idx][a[i]] = 1;
      v[idx].clear();
      v[idx].push_back(a[i]);
      vis[a[i]] = 1;
      for (auto mn : v[idx ^ 1]) {
        int len = (a[i] + mn - 1) / mn;
        int new_mn = a[i] / len;
        dp[idx][new_mn] += dp[idx ^ 1][mn];
        ans += dp[idx ^ 1][mn] * (len - 1) * i;
        ans %= mod;
        if (!vis[new_mn]) v[idx].push_back(new_mn), vis[new_mn] = 1;
      }
      for (auto it : v[idx ^ 1]) dp[idx ^ 1][it] = 0;
      for (auto it : v[idx]) vis[it] = 0;
      v[idx ^ 1].clear();
    }
    for (auto it : v[0]) dp[0][it] = dp[1][it] = vis[it] = 0;
    for (auto it : v[1]) dp[0][it] = dp[1][it] = vis[it] = 0;
    cout << ans << '\n';
  }
  return 0;
}
