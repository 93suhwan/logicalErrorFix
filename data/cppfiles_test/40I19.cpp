#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5, maxm = 3e5 + 5;
struct Edge {
  int to, nxt;
} e[2 * maxm];
int cnt;
int head[maxn];
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
void add(int u, int v) {
  e[cnt] = (Edge){v, head[u]};
  head[u] = cnt++;
  return;
}
bool ban[maxm];
int st[maxm], tp;
void dfs(int x) {
  for (int &i = head[x]; i != -1; i = e[i].nxt) {
    int id = i, tmp = e[id].to;
    if (ban[i >> 1]) continue;
    ban[i >> 1] = 1;
    dfs(tmp);
    st[++tp] = id;
    if (i == -1) break;
  }
  return;
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
  memset(head, -1, sizeof(head));
  for (int i = 1; i <= m; i++) {
    int u, v;
    u = read();
    v = read();
    to[u].push_back(v), to[v].push_back(u);
  }
  int q, rt = 0;
  q = read();
  for (int i = 1; i <= q; i++) {
    int a, b;
    a = read();
    b = read();
    rt = a;
    add(a, b), add(b, a);
    d[a] ^= 1, d[b] ^= 1;
  }
  int num = 0;
  for (int i = 1; i <= n; i++) num += d[i];
  if (num) {
    puts("NO");
    printf("%d\n", num / 2);
    return 0;
  }
  dfs(rt);
  dfs1(rt, 0);
  int x = rt;
  for (int i = tp; i > 1; i--) {
    int id = st[i];
    get(x, e[id].to);
    res[id >> 1] = path;
    x = e[id].to;
  }
  get(x, e[st[1]].to);
  res[st[1] >> 1] = path;
  puts("YES");
  for (int i = 0; i < q; i++) {
    printf("%d\n", res[i].size());
    for (int j = 0; j < res[i].size(); j++) printf("%d ", res[i][j]);
    puts("");
  }
  return 0;
}
