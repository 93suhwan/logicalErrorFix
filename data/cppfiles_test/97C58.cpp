#include <bits/stdc++.h>
using namespace std;
int n, m;
char g[510][510];
int s[510][510], col[250010];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
int h[250010], e[250010 * 10], ne[250010 * 10], idx;
int tran(pair<int, int> p) { return (p.first - 1) * m + p.second; }
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void dfs(int u, int c) {
  col[u] = c;
  for (int i = h[u]; ~i; i = ne[i]) {
    int j = e[i];
    if (!col[j]) dfs(j, 5 - c);
  }
}
int main() {
  memset(h, -1, sizeof h);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
  bool flag = true;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (g[i][j] == 'X') {
        int cnt = 0;
        vector<pair<int, int> > v;
        for (int d = 0; d < 4; d++)
          if (i + dx[d] >= 1 && i + dx[d] <= n && j + dy[d] >= 1 &&
              j + dy[d] <= m && g[i + dx[d]][j + dy[d]] == '.')
            v.push_back(make_pair(i + dx[d], j + dy[d]));
        if (v.size() == 2)
          add(tran(v[0]), tran(v[1])), add(tran(v[1]), tran(v[0]));
        else if (v.size() == 4)
          for (int d = 0; d < 4; d++)
            add(tran(v[d]), tran(v[(d + 1) % 4])),
                add(tran(v[(d + 1) % 4]), tran(v[d]));
        else if (v.size() > 0)
          flag = false;
      }
  if (!flag)
    return puts("NO"), 0;
  else {
    puts("YES");
    for (int i = 1; i <= n * m; i++)
      if (!col[i]) dfs(i, 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (g[i][j] == '.') s[i][j] = col[tran(make_pair(i, j))];
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (g[i][j] == 'X')
          for (int d = 0; d < 4; d++)
            if (i + dx[d] >= 1 && i + dx[d] <= n && j + dy[d] >= 1 &&
                j + dy[d] <= m && g[i + dx[d]][j + dy[d]] == '.')
              s[i][j] += s[i + dx[d]][j + dy[d]];
    for (int i = 1; i <= n; i++, puts(""))
      for (int j = 1; j <= m; j++) printf("%d ", s[i][j]);
  }
}
