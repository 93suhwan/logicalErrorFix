#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 105;
const int INF = 1000000000;
const long long MOD = 1000000007LL;
int n, k;
vector<int> g[MAX_N];
int byDist[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N];
long long fact[MAX_N];
long long invFact[MAX_N];
long long binPow(long long a, long long x) {
  if (x == 0) return 1LL;
  if (x % 2 != 0) return (a * binPow(a, x - 1LL)) % MOD;
  long long halfPow = binPow(a, x / 2LL);
  return (halfPow * halfPow) % MOD;
}
void dfs(int u, int p, int d, int startI) {
  byDist[startI][d]++;
  for (int v : g[u])
    if (v != p) dfs(v, u, d + 1, startI);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fact[0] = 1;
  for (int i = 1; i < MAX_N; i++) fact[i] = (fact[i - 1] * i) % MOD;
  for (int i = 0; i < MAX_N; i++) invFact[i] = binPow(fact[i], MOD - 2LL);
  int tests;
  cin >> tests;
  while (tests--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    if (k == 2) {
      long long c = (fact[n] * invFact[2]) % MOD;
      c = (c * invFact[n - 2]) % MOD;
      cout << c << '\n';
      continue;
    }
    long long result = 0;
    for (int i = 0; i < n; i++) {
      if ((int)g[i].size() < k) continue;
      for (int j = 0; j < (int)g[i].size(); j++)
        for (int d = 0; d < n; d++) byDist[j][d] = 0;
      for (int j = 0; j < (int)g[i].size(); j++) dfs(g[i][j], i, 1, j);
      for (int d = 1; d < n; d++) {
        for (int j = 0; j <= (int)g[i].size(); j++)
          for (int jj = 0; jj <= (int)g[i].size(); jj++) dp[j][jj] = 0;
        dp[0][0] = 1LL;
        for (int j = 0; j < (int)g[i].size(); j++)
          for (int jj = 0; jj < (int)g[i].size(); jj++) {
            dp[j + 1][jj] = (dp[j + 1][jj] + dp[j][jj]) % MOD;
            dp[j + 1][jj + 1] =
                (dp[j + 1][jj + 1] + dp[j][jj] * byDist[j][d]) % MOD;
          }
        result = (result + dp[(int)g[i].size()][k]) % MOD;
      }
    }
    cout << result << '\n';
  }
  return 0;
}
