#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long MOD = 1e9 + 7;
int t, n, k, u, v;
vector<vector<int> > adj;
vector<int> dep, part;
void dfs(int i, int p, int d) {
  dep[i] = d;
  for (int nb : adj[i])
    if (nb != p) {
      part[nb] = part[i];
      dfs(nb, i, d + 1);
    }
}
long long calc(int i) {
  dep.clear();
  dep.resize(n, 0);
  part.clear();
  part.resize(n, i);
  for (int nb : adj[i]) {
    part[nb] = nb;
    dfs(nb, i, 1);
  }
  long long ans = 0;
  for (int d = (1); d < (n); ++d) {
    map<int, long long> freq;
    for (int i = (0); i < (n); ++i)
      if (dep[i] == d) freq[part[i]]++;
    if (freq.size() < k) break;
    vector<long long> vals;
    for (auto p : freq) vals.push_back(p.second);
    vector<vector<long long> > dp(vals.size(), vector<long long>(k, 0));
    dp[0][0] = vals[0];
    for (int i = (1); i < (vals.size()); ++i) {
      dp[i][0] = (vals[i] + dp[i - 1][0]) % MOD;
      for (int j = (1); j < (k); ++j) {
        dp[i][j] = (dp[i - 1][j] + vals[i] * dp[i - 1][j - 1]) % MOD;
      }
    }
    ans = (ans + dp[vals.size() - 1][k - 1]) % MOD;
  }
  return ans;
}
void solve() {
  cin >> n >> k;
  adj.clear();
  adj.resize(n);
  for (int i = (0); i < (n - 1); ++i) {
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (k == 2) {
    cout << n * (n - 1) / 2 << '\n';
    return;
  }
  long long ans = 0;
  for (int i = (0); i < (n); ++i) ans = (ans + calc(i)) % MOD;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    solve();
  }
}
