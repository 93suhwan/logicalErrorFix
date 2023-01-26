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
    vis[b] = 1;
  }
  int rot;
  for (int i = 1; i <= n; i++)
    if (vis[i] == 0) rot = i;
  for (int i = 1; i <= n; i++) {
    if (i != rot) cout << rot << " " << i << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
