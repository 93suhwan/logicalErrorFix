#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T, N, K, u, v;
  cin >> T;
  while (T--) {
    cin >> N >> K;
    long long ret = 0;
    vector<int> adj[N + 1];
    for (int i = 0; i < N - 1; i++) {
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
      if (adj[i].size() < K) continue;
      vector<pair<long long, int> > bfs;
      vector<int> vis;
      vis.resize(N + 1);
      vis[i] = 1;
      for (int n : adj[i]) {
        bfs.push_back(pair<long long, int>(n, n));
      }
      while (!bfs.empty()) {
        unordered_map<int, int> sz;
        vector<pair<long long, int> > step;
        for (pair<long long, int> j : bfs) {
          sz[j.second]++;
          vis[j.first] = 1;
          for (int n : adj[j.first]) {
            if (!vis[n]) step.push_back(pair<long long, int>(n, j.second));
          }
        }
        if (sz.size() < K) {
          break;
        }
        int second = sz.size();
        vector<int> all;
        for (auto i : sz) {
          all.push_back(i.second);
        }
        long long dp[second + 1][K + 1];
        for (int i = 0; i <= second; i++) {
          for (int j = 0; j <= K; j++) {
            dp[i][j] = (j == 0);
          }
        }
        for (int i = 1; i <= second; i++) {
          for (int j = 1; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j != 0) dp[i][j] += dp[i - 1][j - 1] * all[i - 1];
            dp[i][j] %= mod;
          }
        }
        ret += dp[second][K];
        ret %= mod;
        swap(step, bfs);
      }
    }
    cout << (K == 2 ? (N) * (N - 1) / 2 : ret) << '\n';
  }
  return 0;
}
