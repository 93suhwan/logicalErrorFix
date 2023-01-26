#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 200005;
int son[N] = {0}, dd[N] = {0}, d[N] = {0}, top[N] = {0}, ye = 0;
vector<int> my[N];
void dfs1(int x) {
  int i = 0, y = 0, now = 0;
  son[x] = -1;
  dd[x] = 1;
  for (i = 0; i < my[x].size(); i++) {
    y = my[x][i];
    if (d[y]) continue;
    d[y] = d[x] + 1;
    dfs1(y);
    now = dd[y] + 1;
    if (now > dd[x]) {
      dd[x] = now;
      son[x] = y;
    }
  }
  if (dd[x] == 1) {
    ye++;
  }
}
void dfs2(int x, int r, int t) {
  top[x] = t;
  int i = 0, y = 0;
  for (i = 0; i < my[x].size(); i++) {
    y = my[x][i];
    if (y == r) continue;
    if (son[x] == y) {
      dfs2(y, x, t);
    } else {
      dfs2(y, x, y);
    }
  }
}
void solve() {
  int i = 0, n = 0, m = 0, p = 0, q = 0, you = 0;
  long long ans = 0, now = 0;
  vector<int> a;
  scanf("%d%d", &n, &m);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &p, &q);
    my[p].push_back(q);
    my[q].push_back(p);
  }
  d[1] = 1;
  dfs1(1);
  if (m >= ye) {
    for (i = ye; i <= m; i++) {
      now = (n - i) * 1LL * i;
      if (now > ans) ans = now;
    }
    printf("%lld\n", ans);
    return;
  }
  dfs2(1, 0, 1);
  for (i = 1; i <= n; i++) {
    if (dd[i] == 1) {
      a.push_back(-d[i] + d[top[i]] - 1);
    }
  }
  sort(a.begin(), a.end());
  for (i = 0; i < m; i++) {
    you -= a[i];
  }
  printf("%lld\n", (you - m) * 1LL * (m - (n - you)));
}
int main() {
  int o = 1;
  while (o--) {
    solve();
  }
  return 0;
}
