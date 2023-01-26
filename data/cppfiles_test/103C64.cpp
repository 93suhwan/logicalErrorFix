#include <bits/stdc++.h>
#pragma gcc optimize("Ofast")
#pragma gcc target("avx2")
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  vector<int> nxt(128);
  nxt['L'] = 0, nxt['R'] = 1, nxt['U'] = 2, nxt['D'] = 3;
  vector<int> di{0, 0, -1, 1};
  vector<int> dj{-1, 1, 0, 0};
  while (t--) {
    int n, m;
    cin >> n >> m;
    auto valid = [&](int i, int j) {
      return i >= 0 && i < n && j >= 0 && j < m;
    };
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> in(n, vector<int>(m));
    using node = pair<int, pair<int, int>>;
    vector<vector<node>> dp(n, vector<node>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        int ni = i + di[nxt[a[i][j]]];
        int nj = j + dj[nxt[a[i][j]]];
        if (valid(ni, nj)) {
          ++in[ni][nj];
        }
        dp[i][j] = {0, {i, j}};
      }
    }
    node ans = {0, {-1, -1}};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (in[i][j] == 0) {
          q.emplace(i, j);
          ans = {dp[i][j].first + 1, dp[i][j].second};
        }
      }
    }
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      int ni = i + di[nxt[a[i][j]]];
      int nj = j + dj[nxt[a[i][j]]];
      if (valid(ni, nj)) {
        --in[ni][nj];
        dp[ni][nj] = max(dp[ni][nj], {dp[i][j].first + 1, dp[i][j].second});
        ans = max(ans, {dp[ni][nj].first + 1, dp[ni][nj].second});
        if (in[ni][nj] == 0) {
          q.emplace(ni, nj);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (in[i][j] > 0) {
          in[i][j] = 0;
          node mx = dp[i][j];
          int cnt = 1;
          int ni = i + di[nxt[a[i][j]]];
          int nj = j + dj[nxt[a[i][j]]];
          int pi = i, pj = j;
          while (ni != i || nj != j) {
            in[ni][nj] = 0;
            mx = max(mx, dp[ni][nj]);
            ++cnt;
            pi = ni, pj = nj;
            ni = pi + di[nxt[a[pi][pj]]];
            nj = pj + dj[nxt[a[pi][pj]]];
          }
          ans = max(ans, {mx.first + cnt, mx.second});
        }
      }
    }
    cout << ans.second.first + 1 << ' ' << ans.second.second + 1 << ' '
         << ans.first << '\n';
  }
}
