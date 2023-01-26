#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, N = 2e6;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int n;
int num[N], num_cnt, id[N];
vector<int> e[N];
unordered_map<int, int> mp;
inline int k2(int x) {
  int t = 1;
  while (t < x) t <<= 1;
  return t;
}
int ans, ans1, ans2;
pair<int, int> dfs(int u) {
  pair<int, int> mx1 = make_pair(0, id[u]), mx2 = make_pair(0, id[u]);
  for (auto v : e[u]) {
    pair<int, int> tmp = dfs(v);
    tmp.first++;
    if (tmp >= mx1)
      mx2 = mx1, mx1 = tmp;
    else if (tmp >= mx2)
      mx2 = tmp;
  }
  if (mx1.first + mx2.first > ans && mx2.second) {
    ans = mx1.first + mx2.first;
    ans1 = mx1.second;
    ans2 = mx2.second;
  }
  return mx1;
}
int main() {
  n = read();
  for (int i = 1, a; i <= n; i++) {
    a = read();
    if (mp[a]) continue;
    num[mp[a] = ++num_cnt] = a, id[mp[a]] = i;
    while (a > 0) {
      int fa = k2(a) - a, f = mp[fa];
      if (!mp[fa]) num[mp[fa] = ++num_cnt] = fa;
      e[mp[fa]].push_back(mp[a]);
      if (f) break;
      a = fa;
    }
  }
  dfs(mp[0]);
  printf("%d %d %d\n", ans1, ans2, ans);
  return 0;
}
