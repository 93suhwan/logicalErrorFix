#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5, maxm = 3e5 + 5;
int a[maxn], b[maxn];
int d[maxn];
vector<int> to[maxn];
int read() {
  int x = 0, y = 1;
  char ch = getchar();
  while (ch < 48 || ch > 57) {
    if (ch == 45) y = -1;
    ch = getchar();
  }
  while (ch >= 48 && ch <= 57)
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * y;
}
vector<int> res[maxm];
int f[maxn], dep[maxn];
bool vis[maxn];
void dfs1(int x, int fa) {
  vis[x] = 1;
  f[x] = fa;
  dep[x] = dep[fa] + 1;
  for (int i = 0; i < to[x].size(); i++) {
    int tmp = to[x][i];
    if (vis[tmp]) continue;
    dfs1(tmp, x);
  }
  return;
}
vector<int> path, tmp1, tmp2;
void get(int x, int y) {
  int X = x, Y = y;
  tmp1.clear(), tmp2.clear();
  tmp1.push_back(x), tmp2.push_back(y);
  bool tag = 0;
  while (x ^ y) {
    if (dep[x] < dep[y]) swap(x, y), tag ^= 1;
    x = f[x];
    if (tag && x != X && x != Y)
      tmp2.push_back(x);
    else if (!tag && x != X && x != Y)
      tmp1.push_back(x);
  }
  reverse(tmp2.begin(), tmp2.end());
  for (int i = 0; i < tmp2.size(); i++) tmp1.push_back(tmp2[i]);
  path = tmp1;
  return;
}
int main() {
  int n, m;
  n = read();
  m = read();
  for (int i = 1; i <= m; i++) {
    int u, v;
    u = read();
    v = read();
    to[u].push_back(v), to[v].push_back(u);
  }
  int q, rt = 0;
  q = read();
  for (int i = 1; i <= q; i++) {
    a[i] = read();
    b[i] = read();
    rt = a[i];
    d[a[i]] ^= 1, d[b[i]] ^= 1;
  }
  int num = 0;
  for (int i = 1; i <= n; i++) num += d[i];
  if (num) {
    puts("NO");
    printf("%d\n", num / 2);
    return 0;
  }
  dfs1(rt, 0);
  puts("YES");
  for (int i = 1; i <= q; i++) {
    get(a[i], b[i]);
    printf("%d\n", path.size());
    for (int j = 0; j < path.size(); j++) printf("%d ", path[j]);
    puts("");
  }
  return 0;
}
