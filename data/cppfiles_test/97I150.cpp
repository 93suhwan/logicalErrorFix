#include <bits/stdc++.h>
using namespace std;
char s[505][505];
bool vis[505][505];
int id[505][505];
int ans[505][505];
vector<pair<pair<int, int>, int> > g[505][505];
int n, m;
void dfs(int i, int j, int idx) {
  vis[i][j] = 1;
  id[i][j] = idx;
  for (int l = -1; l <= 1; l++) {
    for (int r = -1; r <= 1; r++) {
      if (abs(l + r) == 1) {
        if (1 <= i + l && i + l <= n && 1 <= j + r && j + r <= m &&
            !vis[i + l][j + r]) {
          dfs(i + l, j + r, idx);
        }
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        int cnt = (s[i - 1][j] == '.') + (s[i + 1][j] == '.') +
                  (s[i][j - 1] == '.') + (s[i][j + 1] == '.');
        if (cnt % 2 == 1) {
          printf("NO\n");
          return 0;
        }
      }
    }
  }
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j]) continue;
      ++idx;
      dfs(i, j, idx);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        int cnt = (s[i - 1][j] == '.') + (s[i + 1][j] == '.') +
                  (s[i][j - 1] == '.') + (s[i][j + 1] == '.');
        if (s[i - 1][j] == '.' && s[i + 1][j] == '.' &&
            id[i - 1][j] != id[i + 1][j]) {
          g[i + 1][j].emplace_back(make_pair(make_pair(i - 1, j), 1));
          g[i - 1][j].emplace_back(make_pair(make_pair(i + 1, j), 1));
        } else if (s[i][j - 1] == '.' && s[i][j + 1] == '.' &&
                   id[i][j - 1] != id[i][j + 1]) {
          g[i][j + 1].emplace_back(make_pair(make_pair(i, j - 1), 1));
          g[i][j - 1].emplace_back(make_pair(make_pair(i, j + 1), 1));
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.') {
        if (s[i + 1][j] == '.') {
          g[i][j].emplace_back(make_pair(make_pair(i + 1, j), 0));
          g[i + 1][j].emplace_back(make_pair(make_pair(i, j), 0));
        }
        if (s[i][j + 1] == '.') {
          g[i][j].emplace_back(make_pair(make_pair(i, j + 1), 1));
          g[i][j + 1].emplace_back(make_pair(make_pair(i, j), 1));
        }
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  queue<pair<int, int> > q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.' && !vis[i][j]) {
        q.push(make_pair(i, j));
        vis[i][j] = 1;
        ans[i][j] = 1;
        while (!q.empty()) {
          int x = q.front().first, y = q.front().second;
          q.pop();
          for (int i = 0; i < g[x][y].size(); i++) {
            int x2 = g[x][y][i].first.first, y2 = g[x][y][i].first.second;
            int c = g[x][y][i].second;
            if (vis[x2][y2]) continue;
            vis[x2][y2] = 1;
            q.push(make_pair(x2, y2));
            if (c == 0)
              ans[x2][y2] = ans[x][y];
            else {
              if (ans[x][y] == 1)
                ans[x2][y2] = 4;
              else
                ans[x2][y2] = 1;
            }
          }
        }
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        for (int l = -1; l <= 1; l++) {
          for (int r = -1; r <= 1; r++) {
            if (abs(l + r) == 1) {
              if (1 <= i + l && i + l <= n && 1 <= j + r && j + r <= m &&
                  s[i + l][j + r] == '.') {
                ans[i][j] += ans[i + l][j + r];
              }
            }
          }
        }
      }
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
}
