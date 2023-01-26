#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int maxn = 1e6 + 100;
const int md = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int a[1007][10007], ans;
int b[maxn];
bool vis[1007][1007];
bool cmp(int a, int b) { return a > b; }
int d[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int xx = x + d[i][0];
    int yy = y + d[i][1];
    if ((a[x][y] >> i) % 2 == 0 && vis[xx][yy] == 0) {
      vis[xx][yy] = 1;
      dfs(xx, yy);
      ans++;
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  int tot = 0;
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!vis[i][j]) {
        vis[i][j] = 1;
        ans = 1;
        dfs(i, j);
        b[++tot] = ans;
      }
    }
  }
  sort(b + 1, b + 1 + tot, cmp);
  for (int i = 1; i <= tot; i++) {
    if (i == 1)
      cout << b[i];
    else
      cout << " " << b[i];
  }
  return 0;
}
