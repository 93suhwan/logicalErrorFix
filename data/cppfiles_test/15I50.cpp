#include <bits/stdc++.h>
#pragma GCC optimize("-Ofast", "-funroll-all-loops")
using namespace std;
const int MAXN = 1e2 + 10, mod = 1e9 + 7;
inline int add(int first, int second) {
  return first + second > mod ? first + second - mod : first + second;
}
inline int mul(int first, int second) { return 1ll * first * second % mod; }
int ch[MAXN][MAXN], dp[MAXN][MAXN];
vector<int> G[MAXN];
void dfs(int first, int prev, int d, int j) {
  ch[j][d] += 1;
  for (int(i) = (0); (i) < (G[first].size()); (i) += (1)) {
    if (G[first][i] == prev) continue;
    dfs(G[first][i], first, d + 1, j);
  }
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, t, k, ans, a, b;
  bool f;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ans = 0;
    for (int(i) = (1); (i) <= (n); (i) += (1)) G[i].clear();
    for (int(i) = (1); (i) < (n); (i) += (1)) {
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    if (k == 2) {
      cout << n * (n - 1) / 2 << '\n';
      continue;
    }
    for (int(i) = (1); (i) <= (n); (i) += (1)) {
      memset(ch, 0, sizeof(ch));
      for (int(j) = (0); (j) < (G[i].size()); (j) += (1)) {
        dfs(G[i][j], i, 1, j + 1);
      }
      for (int(z) = (1); (z) < (n); (z) += (1)) {
        memset(dp, 0, sizeof(dp));
        fill(dp[0], dp[0] + G[i].size(), 1);
        for (int(j) = (1); (j) <= (G[i].size()); (j) += (1)) {
          for (int(u) = (1); (u) <= (j); (u) += (1)) {
            dp[j][u] = add(dp[j][u], mul(dp[j - 1][u - 1], ch[j][z]));
          }
        }
        ans = add(ans, dp[G[i].size()][k]);
      }
    }
    cout << ans << '\n';
  }
}
