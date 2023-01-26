#include <bits/stdc++.h>
using namespace std;
const int N = 4000000, M = 2000;
int out[N + 5];
char a[M + 5][M + 5];
int n, m;
map<char, int> dir = {{'L', 0}, {'U', 1}, {'R', 2}, {'D', 3}};
int nx[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int get(int x, int y) {
  if (x <= 0 || y <= 0 || x > n || y > m)
    return -1;
  else
    return m * (x - 1) + y;
}
int len[N + 5];
bool vis[N + 5], loop[N + 5];
int dfs(int x) {
  if (len[x] != -1) return len[x];
  if (out[x] == -1) return len[x] = 1;
  if (vis[x]) {
    int temp = out[x];
    printf("%d\n", temp);
    int loop_len = 1;
    while (temp != x) {
      loop[temp] = 1;
      loop_len++;
      temp = out[temp];
    }
    temp = out[x];
    while (temp != x) {
      len[temp] = loop_len;
      temp = out[temp];
    }
    return len[x] = loop_len;
  }
  vis[x] = 1;
  int d = dfs(out[x]);
  vis[x] = 0;
  if (len[x] != -1)
    return len[x];
  else
    return len[x] = d + 1;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", a[i] + 1);
      for (int j = 1; j <= m; j++) {
        len[get(i, j)] = -1;
        out[get(i, j)] = get(i + nx[dir[a[i][j]]][0], j + nx[dir[a[i][j]]][1]);
      }
    }
    int ans = -1, x = 0, y = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        int now = get(i, j);
        int d = dfs(now);
        if (d > ans) {
          ans = d;
          x = i;
          y = j;
        }
      }
    printf("%d %d %d\n", x, y, ans);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        len[get(i, j)] = -1;
        out[get(i, j)] = -1;
        vis[get(i, j)] = 0;
        loop[get(i, j)] = 0;
      }
  }
  return 0;
}
