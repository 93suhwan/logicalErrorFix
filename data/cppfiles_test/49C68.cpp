#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000005];
int ans[1000005];
bool vis[1000005];
struct ques {
  int l, k, id;
};
vector<ques> q[1000005];
vector<int> g[1000005];
vector<int> d[1000005];
int c[1000005];
int s[1000005];
inline void add(int u) {
  s[c[a[u]]]--;
  d[++c[a[u]]].push_back(a[u]);
}
inline void del(int u) {
  d[--c[a[u]]].push_back(a[u]);
  s[c[a[u]]]++;
}
inline int query(int x) {
  int p = lower_bound(s + 1, s + 1 + n, x) - s;
  while (!d[p].empty()) {
    if (c[d[p].back()] == p)
      break;
    else
      d[p].pop_back();
  }
  if (d[p].empty()) return -1;
  return d[p].back();
}
void dfs(int u) {
  add(u);
  for (int i = 0; i < q[u].size(); i++) {
    int l = q[u][i].l, k = q[u][i].k;
    ans[q[u][i].id] = query(k + s[l - 1]);
  }
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    dfs(v);
  }
  del(u);
}
void init() {
  for (int i = 1; i <= n; i++) g[i].clear();
  for (int i = 1; i <= n; i++) q[i].clear();
  for (int i = 1; i <= n; i++) d[i].clear();
  for (int i = 1; i <= n; i++) vis[i] = false;
}
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
inline int rd() {
  int x = 0, f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (isdigit(ch))
    x = x * 10 + (ch ^ 48),
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  return x * f;
}
int main() {
  int t = rd();
  while (t--) {
    n = rd(), m = rd();
    init();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      a[i] = rd();
      if (!vis[a[i]]) {
        vis[a[i]] = true;
        cnt++;
      }
    }
    for (int i = 0; i <= n; i++) s[i] = cnt;
    for (int i = 2; i <= n; i++) {
      int fa = rd();
      g[fa].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
      int v = rd(), l = rd(), k = rd();
      q[v].push_back({l, k, i});
    }
    dfs(1);
    for (int i = 1; i <= m; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
