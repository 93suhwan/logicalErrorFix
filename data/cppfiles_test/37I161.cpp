#include <bits/stdc++.h>
using namespace std;
int sh[200005];
int find(int x) { return sh[x] == x ? x : sh[x] = find(sh[x]); }
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int> > e;
  vector<int> vis(n + 1, 0);
  map<pair<int, int>, int> ma;
  int f = 0;
  for (int i = 1; i <= n; i++) sh[i] = i;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (ma[{a, c}] == 1) continue;
    ma[{a, c}] = 1, ma[{c, a}] = 1;
    e.push_back({a, c});
    vis[a] = vis[c] = 1;
    f = a;
    sh[find(a)] = find(c);
  }
  for (int i = 0; i < e.size(); i++)
    cout << e[i].first << " " << e[i].second << endl;
  for (int i = 1; i <= n; i++) {
    if (find(1) != find(sh[i])) {
      cout << 1 << " " << i << endl;
      sh[find(1)] = find(i);
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
