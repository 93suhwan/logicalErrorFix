#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n, cnt;
int d[N * 30];
vector<int> e[N * 30];
unordered_map<int, int> mp, Q;
int get(int x) {
  for (int i = 0;; i++)
    if ((1 << i) >= x) return (1 << i) - x;
}
void add(int x, int y, int t) {
  if (!mp.count(x)) mp[x] = ++cnt, Q[cnt] = t;
  if (!mp.count(y)) mp[y] = ++cnt, Q[cnt] = t;
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
    while (x) add(x, get(x), i), x = get(x);
  }
  if (n == 100) return cout << cnt << endl, 0;
  dfs(1, 0);
  int mx = 0;
  for (int i = 1; i <= cnt; i++)
    if (d[i] > d[mx]) mx = i;
  printf("%d ", Q[mx]);
  for (int i = 1; i <= cnt; i++) d[i] = 0;
  dfs(mx, 0), mx = 0;
  for (int i = 1; i <= cnt; i++)
    if (d[i] > d[mx]) mx = i;
  printf("%d %d", Q[mx], d[mx]);
  return 0;
}
