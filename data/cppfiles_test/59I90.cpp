#include <bits/stdc++.h>
using namespace std;
int n, m, a[2005], b[2005], inset[2005], from[2005], vis[2005];
int dt;
vector<int> e[2005], vec;
void fuck(int x) {
  while (!inset[x]) {
    dt += b[x];
    vec.push_back(x);
    inset[x] = 1;
    x = from[x];
  }
}
bool dfs(int u, int pw) {
  vis[u] = 1;
  for (auto v : e[u]) {
    if (pw <= a[v]) continue;
    if (inset[u] && inset[v]) continue;
    if (v == from[u]) continue;
    if (vis[v]) {
      fuck(v);
      fuck(u);
      return 1;
    } else {
      from[v] = u;
      if (dfs(v, pw + b[v])) return 1;
    }
  }
  return 0;
}
bool check(int p) {
  vec.clear();
  for (int i = (1); i <= (n); i++) inset[i] = 0;
  vec.push_back(1);
  inset[1] = 1;
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (n); j++) from[j] = 0, vis[j] = inset[j];
    dt = 0;
    for (auto x : vec) {
      if (dfs(x, p)) {
        break;
      }
    }
    p += dt;
  }
  return ((int)vec.size()) == n;
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = (2); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (2); i <= (n); i++) scanf("%d", &b[i]);
  for (int i = (1); i <= (n); i++) e[i].clear();
  for (int i = (1); i <= (m); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int l = 1, r = 1e9, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T-- > 0) solve();
  return 0;
}
