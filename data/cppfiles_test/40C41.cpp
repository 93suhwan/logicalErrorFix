#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, m, q, fa[N];
int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
vector<int> g[N];
int b[N];
vector<int> ans[N];
int cur;
bool dfs(int x, int f, int goal) {
  ans[cur].push_back(x);
  if (x == goal) return true;
  for (int y : g[x])
    if (y != f)
      if (dfs(y, x, goal)) return true;
  ans[cur].pop_back();
  return false;
}
set<pair<int, int> > s;
int deg[N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (get(u) == get(v)) continue;
    fa[get(u)] = get(v);
    g[u].push_back(v), g[v].push_back(u);
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    cur++, dfs(u, 0, v);
  }
  for (int i = 1; i <= q; i++) {
    for (int j = 1; j < (int)ans[i].size(); j++) {
      int x = ans[i][j - 1], y = ans[i][j];
      if (x > y) swap(x, y);
      if (s.find(make_pair(x, y)) != s.end())
        s.erase(make_pair(x, y));
      else
        s.insert(make_pair(x, y));
    }
  }
  if (s.empty()) {
    puts("YES");
    for (int i = 1; i <= q; i++) {
      printf("%d\n", (int)ans[i].size());
      for (int x : ans[i]) printf("%d ", x);
      puts("");
    }
  } else {
    puts("NO");
    for (pair<int, int> temp : s) {
      int x = temp.first, y = temp.second;
      deg[x]++, deg[y]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
      if (deg[i] & 1) res++;
    printf("%d\n", res / 2);
  }
  return 0;
}
