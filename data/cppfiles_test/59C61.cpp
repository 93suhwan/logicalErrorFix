#include <bits/stdc++.h>
const int N = 1005;
int n, m, a[N], b[N];
std::vector<int> adj[N];
bool used[N];
std::vector<int> store;
int pre[N];
std::pair<int, long long> que[N];
int l, r;
bool check(int init) {
  std::fill(used + 1, used + 1 + n, false);
  used[1] = 1;
  store.clear();
  store.push_back(1);
  long long power = init;
  while ((int)store.size() != n) {
    l = 1, r = 0;
    for (int i = 0; i < (int)store.size(); i++)
      que[++r] = std::make_pair(-store[i], power);
    std::fill(pre + 1, pre + 1 + n, false);
    int s = 0, t = 0;
    while (l <= r) {
      int x = que[l].first;
      bool f = x > 0;
      x = std::abs(x);
      long long p = que[l++].second;
      for (int e = 0; e < (int)adj[x].size(); e++) {
        int y = adj[x][e];
        if (pre[x] == y || a[y] >= p) continue;
        if (pre[y] || (used[y] && f)) {
          s = x, t = y;
          break;
        }
        if (used[y]) continue;
        pre[y] = x;
        que[++r] = std::make_pair(y, p + b[y]);
      }
      if (s && t) break;
    }
    if (!s && !t) break;
    do {
      if (!used[s]) {
        store.push_back(s);
        used[s] = 1, power += b[s];
      }
    } while (s = pre[s]);
    do {
      if (!used[t]) {
        store.push_back(t);
        used[t] = 1, power += b[t];
      }
    } while (t = pre[t]);
  }
  if ((int)store.size() != n) return false;
  return true;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) scanf("%d", a + i);
  for (int i = 2; i <= n; i++) scanf("%d", b + i);
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v), adj[v].push_back(u);
  }
  int lb = 0, ub = 1e9 + 1, best = -1;
  while (lb <= ub) {
    int mid = (lb + ub) >> 1;
    if (check(mid))
      ub = mid - 1, best = mid;
    else
      lb = mid + 1;
  }
  printf("%d\n", best);
  for (int i = 1; i <= n; i++) adj[i].clear();
}
signed main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
