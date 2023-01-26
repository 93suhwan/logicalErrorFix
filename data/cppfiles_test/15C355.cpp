#include <bits/stdc++.h>
using namespace std;
char a[11][20];
bool vis[11][20];
int n, m, k, num = 0, s = 0;
bool flag = 0;
int bfs(int i, int j) {
  int h = 1;
  while (1) {
    if (i - h >= 1 && j - h >= 1 && j - h <= m && a[i - h][j - h] == '*' &&
        a[i - h][j + h] == '*') {
      h++;
    } else {
      break;
    }
  }
  return h - 1;
}
void dfs(int i, int j, int h) {
  vis[i][j] = 1;
  for (int k = 1; k <= h; k++) {
    vis[i - k][j - k] = 1;
    vis[i - k][j + k] = 1;
  }
}
int main() {
  int cnt;
  cin >> cnt;
  while (cnt--) {
    num = 0, s = 0;
    cin >> n >> m >> k;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '*') {
          s++;
          int deep = bfs(i, j);
          if (deep >= k) {
            dfs(i, j, deep);
          }
        }
      }
    }
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '*' && vis[i][j] == 0) {
          flag = 0;
        }
      }
    }
    if (flag) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
