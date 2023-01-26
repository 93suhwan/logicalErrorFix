#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 8192;
vector<int> g[maxn];
int n, vis[maxn], r[maxn];
int main() {
  scanf("%d", &n);
  int tmp = 0;
  vis[0] = 1;
  for (int i = 0; i < (1 << 13); i++) g[i].push_back(0);
  for (int i = 0; i < (1 << 13); i++) r[i] = (1 << 13);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &tmp);
    for (auto x : g[tmp]) {
      int to = (x ^ tmp);
      vis[to] = 1;
      while (r[to] > tmp) {
        r[to]--;
        if (r[to] != tmp) g[r[to]].push_back(to);
      }
    }
    g[tmp] = {};
  }
  int ans[maxn];
  int cnt = 0;
  for (int i = 0; i < (1 << 13); i++)
    if (vis[i]) ans[++cnt] = i;
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
  return 0;
}
