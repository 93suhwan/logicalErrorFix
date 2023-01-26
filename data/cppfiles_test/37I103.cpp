#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int gcd(long long int A, long long int B) {
  if (!B) return A;
  return gcd(B, A % B);
}
vector<vector<int>> adj(100005);
vector<int> dp(100005, 0);
bool dfs(int v, int u, int k) {
  int cur = 0;
  for (int x : adj[v]) {
    if (x == u) continue;
    cur += dfs(x, v, k);
  }
  if ((!v || (cur + 1) % k) && cur % k) dp[k] = 0;
  if (v && (cur + 1) % k == 0)
    return 1;
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n - 1; i++) {
      int v, u;
      cin >> v >> u;
      v--;
      u--;
      adj[v].push_back(u);
      adj[u].push_back(v);
    }
    n--;
    vector<int> fac = {1};
    dp[1] = 1;
    for (int i = 0; i < n; i++) {
      dp[1] *= 2;
      if (dp[1] >= (long long int)(1e9 + 7)) dp[1] -= (long long int)(1e9 + 7);
    }
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        dp[i] = 1;
        dfs(0, -1, i);
        fac.push_back(i);
        if (i * i != n) {
          dp[n / i] = 1;
          dfs(0, -1, n / i);
          fac.push_back(n / i);
        }
      }
    }
    if (n != 1) {
      dp[n] = 1;
      fac.push_back(n);
      dfs(0, -1, n);
    }
    sort(fac.begin(), fac.end());
    for (int i = (int)(fac.size()) - 1; i >= 0; i--) {
      for (int j = 2 * fac[i]; j <= n; j += fac[i]) {
        dp[fac[i]] -= dp[j];
      }
    }
    dp[1] += (long long int)(1e9 + 7);
    if (dp[1] >= (long long int)(1e9 + 7)) dp[1] -= (long long int)(1e9 + 7);
    for (int i = 1; i <= n + 1; i++) cout << dp[i] << " ";
    for (int x : fac) dp[x] = 0;
    cout << '\n';
  }
}
