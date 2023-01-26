#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  unordered_map<int, unordered_map<int, bool>> g;
  unordered_map<int, int> pos;
  for (int i = 1; i <= n; i++) {
    int val;
    scanf("%d", &val);
    pos[val] = i;
    int up = 1 << 30;
    while (val) {
      while (up - val >= val) up >>= 1;
      g[up - val][val] = true;
      val = up - val;
    }
  }
  pair<int, pair<int, int>> ans;
  function<pair<int, int>(int)> dfs = [&](int u) {
    pair<int, int> ret = {-1e9, 0};
    if (pos[u]) ret = {0, pos[u]};
    for (auto p : g[u]) {
      int v = p.first;
      auto t = dfs(v);
      ans = max(ans, {t.first + 1 + ret.first, {t.second, ret.second}});
      ret = max(ret, {t.first + 1, t.second});
    }
    return ret;
  };
  dfs(0);
  printf("%d %d %d\n", ans.second.first, ans.second.second, ans.first);
  return 0;
}
