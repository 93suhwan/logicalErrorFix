#include <bits/stdc++.h>
using namespace std;
const int N = 4000000 + 10;
int nex[N], dis[N];
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n * m + 1; i++) dis[i] = -1, nex[i] = 0;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    auto id = [&](int x, int y) {
      if (x < 0 || x >= n || y < 0 || y >= m) return 0;
      return x * m + y + 1;
    };
    map<char, pair<int, int> > dir;
    dir['R'] = {0, 1};
    dir['L'] = {0, -1};
    dir['U'] = {-1, 0};
    dir['D'] = {1, 0};
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        int v = id(i + dir[s[i][j]].first, j + dir[s[i][j]].second);
        nex[id(i, j)] = id(i + dir[s[i][j]].first, j + dir[s[i][j]].second);
      }
    function<int(int)> dfs = [&](int u) {
      if (u == 0) return 0;
      if (dis[u] != -1) return dis[u];
      return dis[u] = dfs(nex[u]) + 1;
    };
    vector<int> visit(n * m + 1, false);
    pair<int, int> ans = {-1, -1};
    for (int i = 1; i <= n * m; i++)
      if (not visit[i]) {
        int x = i;
        while (!visit[x]) {
          visit[x] = i;
          x = nex[x];
        }
        if (x == 0 || visit[x] != i) continue;
        int len = 0, y = x;
        do {
          len++;
          y = nex[y];
        } while (y != x);
        y = x;
        do {
          dis[y] = len;
          y = nex[y];
        } while (y != x);
      }
    for (int i = 1; i <= n * m; i++) {
      ans = max(ans, {dfs(i), i});
    }
    cout << (ans.second - 1) / m + 1 << " " << (ans.second - 1) % m + 1 << " "
         << ans.first << "\n";
  }
}
