#include <bits/stdc++.h>
using namespace std;
const double PI = 3.1415926535897932384626;
const long long mod = 1000000007;
long long n, m;
void dfs(string a[], long long ux, long long uy, char col) {
  a[ux][uy] = col;
  if (ux + 1 < n and a[ux + 1][uy] == '.') dfs(a, ux + 1, uy, col);
  if (uy + 1 < m and a[ux][uy + 1] == '.') dfs(a, ux, uy + 1, col);
}
void solve() {
  cin >> n >> m;
  string a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++)
    if (a[i][0] == '.') dfs(a, i, 0, 'E');
  for (long long j = 0; j < m; j++)
    if (a[0][j] == '.') dfs(a, 0, j, 'E');
  for (long long j = 0; j < m; j++)
    for (long long i = 0; i < n; i++)
      if (a[i][j] == '.') dfs(a, i, j, '0' + j);
  set<long long> walls;
  for (long long j = 0; j < m; j++) {
    bool first = 0;
    for (long long i = 0; i < n; i++)
      if (a[i][j] == ('0' + j)) first = 1;
    if (first) walls.insert(j);
  }
  long long q;
  cin >> q;
  while (q--) {
    long long qx, qy;
    cin >> qx >> qy;
    qx--, qy--;
    auto it = walls.lower_bound(qx + 1);
    if (it == walls.end() or *it > qy)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
