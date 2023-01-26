#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, cnt;
int d[N * 30];
vector<int> e[N * 30];
map<int, int> mp, Q;
int get(int x) {
  for (int i = 0;; i++)
    if ((1 << i) >= x) return (1 << i) - x;
}
void add(int x, int y) {
  if (!mp.count(x)) mp[x] = ++cnt;
  if (!mp.count(y)) mp[y] = ++cnt;
  e[mp[x]].push_back(mp[y]);
  e[mp[y]].push_back(mp[x]);
}
void dfs(int x, int fa) {
  for (auto i : e[x])
    if (i != fa) d[i] = d[x] + 1, dfs(i, x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (!mp.count(x)) mp[x] = ++cnt, Q[cnt] = i;
    while (x) add(x, get(x)), x = get(x);
  }
  dfs(1, 0);
  int mx = 0, mx2 = 0;
  for (int i = 1; i <= cnt; i++) {
    if (!Q.count(i)) continue;
    if (d[i] >= d[mx])
      mx2 = mx, mx = i;
    else if (d[i] >= d[mx2])
      mx2 = i;
  }
  printf("%d %d %d", Q[mx], Q[mx2], d[mx] + d[mx2]);
  return 0;
}
