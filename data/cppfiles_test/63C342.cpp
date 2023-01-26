#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int maxm = 1e7 + 100;
const int mod = 998244353;
long long t, n, m1, m2, f[2][maxn], cnt = 0;
pair<int, int> ans[maxn];
long long find(int x, int y) {
  return f[y][x] == x ? x : f[y][x] = find(f[y][x], y);
}
void merge(int x, int y, int z) { f[z][find(x, z)] = find(y, z); }
void solve() {
  cin >> n >> m1 >> m2;
  int u, v;
  for (int i = 0; i <= n; i++) f[0][i] = f[1][i] = i;
  for (int i = 1; i <= m1; i++) {
    cin >> u >> v;
    merge(u, v, 1);
  }
  for (int i = 1; i <= m2; i++) {
    cin >> u >> v;
    merge(u, v, 0);
  }
  int uu, vv;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      u = find(i, 1), uu = find(i, 0);
      v = find(j, 1), vv = find(j, 0);
      if ((u == v) || (uu == vv)) continue;
      ans[cnt].first = i, ans[cnt++].second = j;
      merge(u, v, 1);
      merge(uu, vv, 0);
    }
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
