#include <bits/stdc++.h>
using namespace std;
const int M = 1e2 + 5;
const int mod = 1e9 + 7;
long long dp[M][M];
int k, n, freq[M][M];
vector<int> adj[M], dpV;
void DFS(int x, int p) {
  int i;
  freq[x][0] = 1;
  for (int y : adj[x]) {
    if (p ^ y) {
      DFS(y, x);
      for (i = 1; i < n; i++) freq[x][i] += freq[y][i - 1];
    }
  }
}
long long DP(int cur, int cnt) {
  if (cnt > k) return 0;
  if (cur == (int)dpV.size()) return (cnt == k);
  long long &ans = dp[cur][cnt];
  if (ans > -1) return ans;
  ans = DP(cur + 1, cnt);
  ans += dpV[cur] * DP(cur + 1, cnt + 1);
  return ans %= mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long ans;
  int i, j, t, x, y;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (i = 1; i <= n; i++) adj[i].clear();
    for (i = 1; i < n; i++) {
      cin >> x >> y;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    }
    if (k == 2)
      ans = (1ll * n * (n - 1)) / 2;
    else {
      ans = 0;
      for (i = 1; i <= n; i++) {
        memset(freq, 0, sizeof(freq));
        DFS(i, 0);
        for (j = 0; j < n - 1; j++) {
          dpV.clear();
          for (int it : adj[i]) {
            if (freq[it][j]) dpV.emplace_back(freq[it][j]);
          }
          if ((int)dpV.size() >= k) {
            memset(dp, -1, sizeof(dp));
            ans += DP(0, 0);
            if (ans >= mod) ans -= mod;
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
