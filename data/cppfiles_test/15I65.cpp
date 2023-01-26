#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[2000];
int binpow(long long base, long long pow) {
  if (pow == 0) return 1;
  long long half = binpow(base, pow / 2);
  long long ret = (half * half) % mod;
  if (pow % 2 == 1) ret *= base;
  return ret % mod;
}
long long choose(long long a, long long b) {
  if (a < 0 || b < 0 || a < b) return 0;
  long long ret = dp[a];
  long long denom = (dp[a - b] * dp[b]) % mod;
  ret *= binpow(denom, mod - 2);
  ret %= mod;
  return ret;
}
int main() {
  dp[0] = 1;
  for (int i = 1; i < 2000; i++) {
    dp[i] = (dp[i - 1] * i) % mod;
  }
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
      vector<int> bfs, vis;
      vis.resize(N + 1);
      vis[i] = 1;
      bfs.push_back(i);
      while (!bfs.empty()) {
        vector<int> step;
        for (int j : bfs) {
          for (int n : adj[j]) {
            if (!vis[n]) {
              step.push_back(n);
              vis[n] = 1;
            }
          }
        }
        ret += choose(step.size(), K);
        ret %= mod;
        swap(step, bfs);
      }
    }
    cout << ret << '\n';
  }
  return 0;
}
