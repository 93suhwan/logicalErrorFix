#include <bits/stdc++.h>
using namespace std;
const int N = 2003;
int fst[N * N], nxt[N * N], v[N * N], cnt;
int dx[27], dy[27], n, m, tx, ty;
int dfn[N][N], low[N][N], c[N][N], tot, top;
int siz[N * N], vis[N * N], num;
char a[N][N];
bool ins[N][N];
pair<int, int> st[N * N], id[N * N], pos;
inline int read() {
  int ss = 0, ww = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ww = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    ss = (ss << 1) + (ss << 3) + (ch ^ 48), ch = getchar();
  return ss * ww;
}
bool ok(int x, int y) { return (x >= 1 && x <= n && y >= 1 && y <= m); }
bool add(int x, int y) {
  v[++cnt] = y;
  nxt[cnt] = fst[x], fst[x] = cnt;
}
void tj(int x, int y) {
  dfn[x][y] = low[x][y] = ++tot;
  st[++top] = make_pair(x, y);
  ins[x][y] = 1;
  tx = x + dx[a[x][y] - 'A'], ty = y + dy[a[x][y] - 'A'];
  if (ok(tx, ty)) {
    if (!dfn[tx][ty]) {
      tj(tx, ty);
      low[x][y] = min(low[x][y], low[tx][ty]);
    } else if (ins[tx][ty])
      low[x][y] = min(low[x][y], dfn[tx][ty]);
  }
  if (dfn[x][y] == low[x][y]) {
    id[++num] = make_pair(x, y);
    while (st[top].first != x || st[top].second != y) {
      ins[st[top].first][st[top].second] = 0,
      c[st[top].first][st[top].second] = num;
      siz[num]++, top--;
    }
    ins[x][y] = 0, c[x][y] = num;
    top--, siz[num]++;
  }
}
void dfs(int x, int col) {
  vis[x] = col;
  for (int i = fst[x]; i; i = nxt[i]) {
    if (!vis[v[i]]) {
      dfs(v[i], col);
      siz[x] += siz[v[i]];
    } else if (vis[v[i]] != col)
      siz[x] += siz[v[i]];
  }
}
int main() {
  dx['U' - 'A'] = -1, dx['D' - 'A'] = 1;
  dy['L' - 'A'] = -1, dy['R' - 'A'] = 1;
  int t = read(), x, y, ans;
  while (t--) {
    n = read(), m = read(), cnt = tot = ans = num = 0;
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ins[i][j] = dfn[i][j] = low[i][j] = 0;
    for (int i = 1; i <= n * m; i++) fst[i] = vis[i] = siz[i] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!dfn[i][j]) {
          top = 0;
          tj(i, j);
        }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        x = i + dx[a[i][j] - 'A'], y = j + dy[a[i][j] - 'A'];
        if (ok(x, y) && c[i][j] != c[x][y]) add(c[i][j], c[x][y]);
      }
    }
    for (int i = 1; i <= num; i++)
      if (!vis[i]) dfs(i, i);
    for (int i = 1; i <= num; i++)
      if (siz[i] > ans) ans = siz[i], pos = id[i];
    printf("%d %d %d\n", pos.first, pos.second, ans);
  }
  return 0;
}
