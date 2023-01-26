#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, a[N], val[N * 30], head[N * 30], ver[N * 60], nex[N * 60], dis[N * 30],
    tot, cnt, s, e, ans;
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
    id[a[i]] = ++cnt;
    val[cnt] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x) {
      long long bit = 1;
      while (bit < x) bit <<= 1;
      long long y = bit - x;
      if (!id.count(y)) {
        id[y] = ++cnt;
        val[cnt] = y;
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
  for (int i = 1; i <= n; i++)
    if (a[i] == val[s] || a[i] == val[e]) printf("%d ", i);
  printf("%d\n", ans);
  return 0;
}
