#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 5;
bool vis[maxn];
int pre[maxn], dp[maxn], dp2[maxn];
vector<int> g[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    auto chk = [&](int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; };
    for (int i = 0; i < n * m; ++i) g[i].clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        int x = i, y = j;
        if (c == 'L') --y;
        if (c == 'R') ++y;
        if (c == 'U') --x;
        if (c == 'D') ++x;
        if (chk(x, y)) {
          g[x * m + y].push_back(i * m + j);
        }
      }
    }
    for (int i = 0; i < n * m; ++i) {
      dp[i] = 0;
      dp2[i] = i;
      pre[i] = -1;
      vis[i] = 0;
    }
    int tm = 0, ans = 0;
    for (int i = 0; i < n * m; ++i) {
      if (vis[i]) continue;
      ++tm;
      vector<int> loop;
      function<int(int)> dfs = [&](int u) -> int {
        int ret = 0;
        vis[u] = tm;
        for (int v : g[u]) {
          if (vis[v]) {
            if (vis[v] == tm) {
              int p = u;
              while (p != v) {
                loop.push_back(p);
                p = pre[p];
              }
              loop.push_back(v);
              ret = 1;
            } else {
              if (dp[v] + 1 > dp[u]) {
                dp[u] = dp[v] + 1;
                dp2[u] = dp2[v];
              }
            }
            continue;
          }
          pre[v] = u;
          if (dfs(v) == 0) {
            if (dp[v] + 1 > dp[u]) {
              dp[u] = dp[v] + 1;
              dp2[u] = dp2[v];
            }
          } else {
            ret = 1;
          }
        }
        return ret;
      };
      dfs(i);
      for (int j : loop) dp[j] += loop.size() - 1;
    }
    int mx = -1, x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (dp[i * m + j] > mx) {
          mx = dp[i * m + j];
          x = dp2[i * m + j] / m;
          y = dp2[i * m + j] % m;
        }
      }
    }
    cout << x + 1 << " " << y + 1 << " " << mx + 1 << endl;
  }
}
