#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
std::vector<long long int> v[104];
long long int mark[104];
void dfs(long long int in, long long int d,
         std::map<long long int, long long int> &m) {
  long long int i, j;
  mark[in] = 1;
  m[d]++;
  d++;
  for (auto x : v[in]) {
    if (!mark[x]) {
      dfs(x, d, m);
    }
  }
}
long long int solve(std::vector<long long int> v, long long int k) {
  long long int i, j, n = ((long long int)v.size());
  if (n == 0) return 0;
  long long int dp[n + 2][k + 2];
  memset(dp, 0, sizeof(dp));
  for (i = 0; i < n; i++) {
    for (j = 1; j < k + 1; j++) {
      if (i == 0) {
        if (j == 1) dp[i][j] += v[i];
        break;
      }
      if (j == 1) {
        dp[i][j] += v[i] + dp[i - 1][j];
        dp[i][j] %= MOD;
      } else {
        dp[i][j] += v[i] * dp[i - 1][j - 1] % MOD;
        dp[i][j] += dp[i - 1][j];
        dp[i][j] %= MOD;
      }
    }
  }
  return dp[n - 1][k];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int test = 1;
  cin >> test;
  while (test--) {
    long long int n, k, i, j;
    cin >> n >> k;
    for (i = 0; i < n + 1; i++) v[i].clear();
    for (i = 0; i < n - 1; i++) {
      long long int a, b;
      cin >> a >> b;
      v[a].push_back(b);
      v[b].push_back(a);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << "\n";
      continue;
    }
    long long int ans = 0;
    for (i = 1; i < n + 1; i++) {
      for (j = 1; j < n + 1; j++) mark[j] = 0;
      mark[i] = 1;
      std::vector<long long int> t[n + 1];
      for (auto x : v[i]) {
        std::map<long long int, long long int> m;
        dfs(x, 1, m);
        for (auto y : m) {
          t[y.first].push_back(y.second);
        }
      }
      for (j = 1; j < n + 1; j++) {
        ans += solve(t[j], k);
        ans %= MOD;
      }
    }
    cout << ans << "\n";
  }
  cerr << "Time Taken:" << (float)clock() / CLOCKS_PER_SEC * 1000 << "ms"
       << "\n";
  return 0;
}
