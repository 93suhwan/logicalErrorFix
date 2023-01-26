#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, m;
vector<int> t[N];
vector<pair<int, int>> g[N];
map<pair<int, int>, int> ans;
void add(int x, int y, int z) {
  if (x > y) swap(x, y);
  if (ans.find(make_pair(x, y)) != ans.end()) return;
  ans[make_pair(x, y)] = z;
}
int c[N];
bool flag;
void dfs(int x) {
  for (auto p : g[x])
    if (c[p.first] == 0)
      c[p.first] = (p.second == 1 ? -c[x] : c[x]), dfs(p.first);
    else if (c[p.first] != (p.second == 1 ? -c[x] : c[x])) {
      flag = 1;
      return;
    }
}
int main() {
  for (scanf("%d", &T); T--;) {
    scanf("%d%d", &n, &m);
    ans.clear();
    for (int i = 1; i <= n; ++i) t[i].clear(), g[i].clear();
    for (int i = 1; i <= n; ++i) c[i] = 0;
    for (int i = 1; i <= n - 1; ++i) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      t[x].push_back(y), t[y].push_back(x);
      if (z != -1) {
        add(x, y, z);
        g[x].push_back(make_pair(y, __builtin_parity(z)));
        g[y].push_back(make_pair(x, __builtin_parity(z)));
      }
    }
    for (int i = 1; i <= m; ++i) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      g[x].push_back(make_pair(y, z));
      g[y].push_back(make_pair(x, z));
    }
    flag = 0;
    for (int i = 1; i <= n; ++i)
      if (c[i] == 0) {
        c[i] = 1;
        dfs(i);
        if (flag) break;
      }
    if (flag) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i)
      for (int v : t[i]) add(i, v, c[i] != c[v]);
    for (auto p : ans)
      printf("%d %d %d\n", p.first.first, p.first.second, p.second);
  }
  return 0;
}
