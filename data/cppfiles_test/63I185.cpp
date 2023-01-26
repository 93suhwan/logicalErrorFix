#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int maxm = 1e7 + 100;
const int mod = 998244353;
long long t, n, m1, m2, f1[maxn], f2[maxn], cnt = 0;
pair<int, int> ans[maxn];
long long find(int x, int y) {
  if (y == 1) return f1[x] == x ? x : f1[x] = find(f1[x], 1);
  return f2[x] == x ? x : f2[x] = find(f2[x], 2);
}
void merge(int x, int y, int z) {
  if (z == 1)
    f1[find(x, 1)] = find(y, 1);
  else
    f2[find(x, 2)] = find(y, 2);
}
void solve() {
  cin >> n >> m1 >> m2;
  int u, v;
  for (int i = 0; i <= n; i++) f1[i] = f2[i] = i;
  for (int i = 1; i <= m1; i++) {
    cin >> u >> v;
    if (u < v) swap(u, v);
    merge(u, v, 1);
  }
  for (int i = 1; i <= m2; i++) {
    cin >> u >> v;
    if (u < v) swap(u, v);
    merge(u, v, 2);
  }
  int uu, vv, ma = min(n - 1 - m1, n - 1 - m2);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      u = find(i, 1), uu = find(i, 2);
      v = find(j, 1), vv = find(j, 2);
      if (u == v || uu == vv) continue;
      ans[cnt].first = i, ans[cnt++].second = j;
      merge(v, u, 1);
      merge(v, u, 2);
    }
    if (cnt == ma) break;
  }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
