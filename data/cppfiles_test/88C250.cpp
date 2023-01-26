#include <bits/stdc++.h>
using namespace std;
const int sz = 305;
int a[sz * sz];
pair<int, int> w[sz * sz];
bool vis[sz][sz];
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  map<int, vector<int>> mp;
  int tot = n * m;
  for (int i = 1; i <= tot; i++) scanf("%d", &a[i]), mp[a[i]].push_back(i);
  int r = 1, c = 0;
  for (auto &[v, ara] : mp) {
    sort(ara.begin(), ara.end());
    int z = ara.size(), it = 0;
    while (m - c <= z - it) {
      for (int i = m; i > c; i--) {
        w[ara[it++]] = {r, i};
      }
      r++, c = 0;
    }
    int i = c + z - it, ti = i;
    while (i > c) {
      w[ara[it++]] = {r, i};
      i--;
    }
    c = ti;
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) vis[i][j] = 0;
  for (int i = 1; i <= tot; i++) {
    auto [r, c] = w[i];
    for (int j = 0; j < c; j++) ans += vis[r][j];
    vis[r][c] = 1;
  }
  printf("%lld\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
