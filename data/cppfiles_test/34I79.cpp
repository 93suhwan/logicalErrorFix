#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 8192;
vector<int> g[maxn];
int n, a[maxn], vis[maxn], r[maxn];
int main() {
  scanf("%d", &n);
  int tmp = 0;
  vis[0] = 1;
  for (int i = 0; i < (1 << 13); i++) g[i].push_back(0);
  for (int i = 0; i < (1 << 13); i++) r[i] = (1 << 13);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    for (auto x : g[a[i]]) {
      int to = (x ^ a[i]);
      vis[to] = 1;
      while (r[to] > a[i]) {
        r[to]--;
        if (r[to] != a[i]) g[r[to]].push_back(to);
      }
    }
    g[a[i]] = {};
  }
  int ans[maxn];
  int cnt = 0;
  for (int i = 0; i < (1 << 13); i++)
    if (vis[i]) ans[++cnt] = i;
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  return 0;
}
