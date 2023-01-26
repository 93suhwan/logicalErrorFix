#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long a = 0;
  long long d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
  return a;
}
vector<vector<long long> > edge(1050000);
long long siz[1050000];
long long fa[1050000];
long long n;
long long cnt;
long long ans;
void dfs1(long long u, long long from) {
  siz[u] = 1;
  fa[u] = from;
  for (long long i = 0; i < edge[u].size(); i++) {
    long long v = edge[u][i];
    if (v != from) {
      dfs1(v, u);
      siz[u] += siz[v];
    }
  }
  if (from == 1 && siz[u] == 1) cnt++;
}
void update(long long now, long long dx) {
  if (!now) return;
  siz[now] -= dx;
  update(fa[now], dx);
}
void dfs2(long long u, long long from) {
  for (long long i = 0; i < edge[u].size(); i++) {
    long long v = edge[u][i];
    if (v != from) dfs2(v, u);
  }
  if (u == 1) return;
  if (siz[u] == 2) {
    update(u, 2);
    return;
  }
  if (siz[u] == 3 && edge[u].size() == 3) {
    update(u, 3);
    ans++;
    return;
  }
}
signed main() {
  long long t = read();
  while (t--) {
    n = read();
    cnt = 0;
    for (long long i = 1; i <= n; i++) edge[i].clear();
    for (long long i = 1; i < n; i++) {
      long long u = read();
      long long v = read();
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs1(1, 0);
    ans = max(cnt, 1ll);
    dfs2(1, 0);
    printf("%lld\n", ans);
  }
  return 0;
}
