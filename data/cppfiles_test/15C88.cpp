#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, d[N], k, vis[N][N], dp[N][N], id, mod = 1e9 + 7, cnt[N][N];
vector<int> adj[N], v;
void dfs(int node, int par, int parCh) {
  if (parCh) {
    cnt[parCh][d[node]]++;
  }
  for (auto ch : adj[node]) {
    if (ch == par) continue;
    d[ch] = d[node] + 1;
    if (node == par)
      dfs(ch, node, ch);
    else
      dfs(ch, node, parCh);
  }
}
int solve(int i, int rem) {
  if (!rem) return 1;
  if (i == (int)v.size()) return 0;
  if (vis[i][rem] == id) return dp[i][rem];
  vis[i][rem] = id;
  int ans = solve(i + 1, rem);
  if (v[i]) ans = (ans + 1ll * v[i] * solve(i + 1, rem - 1)) % mod;
  return dp[i][rem] = ans;
}
void clear() {
  for (int i = 0; i <= n; i++) {
    adj[i].clear();
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << '\n';
      clear();
      continue;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      memset(d, 0, sizeof(d));
      memset(cnt, 0, sizeof(cnt));
      dfs(i, i, 0);
      for (int ds = 1; ds <= n; ds++) {
        v.clear();
        for (int ch = 1; ch <= n; ch++) {
          v.push_back(cnt[ch][ds]);
        }
        id++;
        ans = (ans + solve(0, k)) % mod;
      }
    }
    cout << ans << '\n';
    clear();
  }
  return 0;
}
