#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[300050];
int d[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char mp[505][505];
int ans[300050] = {0};
int id(int x, int y) { return (x - 1) * m + y; }
int cnt(int x, int y) {
  int res = 0;
  for (int i = 0; i < 4; i++) {
    int nx = x + d[i][0];
    int ny = y + d[i][1];
    if (mp[nx][ny] == '.') res++;
  }
  return res;
}
int f = 1;
void dfs(int x, int w) {
  ans[x] = w;
  for (int i = 0; i < v[x].size(); i++) {
    if (!ans[v[x][i]]) dfs(v[x][i], 5 - w);
    if (ans[v[x][i]] == ans[x]) f = 0;
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> mp[i] + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == 'X') {
        int res = cnt(i, j);
        if (res == 2) {
          ans[id(i, j)] = 5;
          int now = -1;
          for (int k = 0; k < 4; k++) {
            int nx = i + d[k][0];
            int ny = j + d[k][1];
            if (mp[nx][ny] == '.') {
              if (now == -1)
                now = id(nx, ny);
              else {
                v[now].push_back(id(nx, ny));
                v[id(nx, ny)].push_back(now);
              }
            }
          }
        } else if (res == 4) {
          ans[id(i, j)] = 10;
          v[id(i - 1, j)].push_back(id(i, j - 1));
          v[id(i - 1, j)].push_back(id(i, j + 1));
          v[id(i + 1, j)].push_back(id(i, j + 1));
          v[id(i + 1, j)].push_back(id(i, j - 1));
          v[id(i, j - 1)].push_back(id(i - 1, j));
          v[id(i, j + 1)].push_back(id(i - 1, j));
          v[id(i, j + 1)].push_back(id(i + 1, j));
          v[id(i, j - 1)].push_back(id(i + 1, j));
        } else if (res == 0) {
          ans[id(i, j)] = 0;
        } else if (res % 2 == 1) {
          printf("NO\n");
          return 0;
        }
      }
    }
  }
  f = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (mp[i][j] == '.' && !ans[id(i, j)]) dfs(id(i, j), 4);
    }
  }
  if (!f)
    cout << "NO" << endl;
  else {
    cout << "YES\n" << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) cout << ans[id(i, j)] << " ";
      cout << endl;
    }
  }
  return 0;
}
