#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
int n, x, y, tot, up, dep[N], rt, a, b, pos[N];
unordered_map<int, int> mp;
set<int> v[N];
void dfs(int x, int fa) {
  dep[x] = dep[fa] + 1;
  if (pos[x] && dep[x] > dep[rt]) rt = x;
  for (int y : v[x])
    if (y != fa) dfs(y, x);
}
signed main() {
  scanf("%d", &n);
  auto id = [&](int x) {
    if (!mp[x]) mp[x] = ++tot;
    return mp[x];
  };
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x), pos[id(x)] = i, up = 1 << 30;
    while (x) {
      while (up - x >= x) up >>= 1;
      y = up - x, v[id(x)].insert(id(y)), v[id(y)].insert(id(x)), x = y;
    }
  }
  dfs(tot, 0), a = pos[rt], dfs(rt, 0), b = pos[rt];
  printf("%d %d %d\n", a, b, dep[rt] - 1);
  return 0;
}
