#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, a[N], head[N * 40], ver[N * 80], nex[N * 80], dis[N * 40], tot, cnt, s,
    e, sval, eval, ans;
map<int, int> id;
inline void add(int x, int y) {
  ver[++tot] = y;
  nex[tot] = head[x];
  head[x] = tot;
}
void dfs1(int x, int fa) {
  if (dis[x] > ans) {
    ans = dis[x];
    s = x;
  }
  for (int i = head[x]; i; i = nex[i]) {
    int y = ver[i];
    if (y == fa) continue;
    dis[y] = dis[x] + 1;
    dfs1(y, x);
  }
}
void dfs2(int x, int fa) {
  if (dis[x] > ans) {
    ans = dis[x];
    e = x;
  }
  for (int i = head[x]; i; i = nex[i]) {
    int y = ver[i];
    if (y == fa) continue;
    dis[y] = dis[x] + 1;
    dfs2(y, x);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    int x = a[i];
    id[x] = ++cnt;
    while (x) {
      int bit = 1;
      while (bit < x) bit <<= 1;
      int y = bit - x;
      if (!id[y]) {
        id[y] = ++cnt;
        add(id[x], id[y]);
        add(id[y], id[x]);
        x = y;
      } else {
        add(id[x], id[y]);
        add(id[y], id[x]);
        break;
      }
    }
  }
  dfs1(1, 0);
  ans = dis[s] = 0;
  dfs2(s, 0);
  map<int, int>::iterator it = id.begin();
  for (; it != id.end(); it++) {
    if (it->second == s) sval = it->first;
    if (it->second == e) eval = it->first;
  }
  for (int i = 1; i <= n; i++)
    if (a[i] == sval || a[i] == eval) printf("%d ", i);
  printf("%d\n", ans);
  return 0;
}
