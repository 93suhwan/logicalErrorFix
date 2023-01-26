#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 998244353;
bool func(int y, int x, int k, vector<vector<char>>& v) {
  int n = v.size();
  int m = v[0].size();
  int l, r;
  l = r = x;
  int sz = -1;
  char cur = v[y][x];
  while (y > -1 && l > -1 && r < m) {
    if (v[y][l] == '.' || v[y][r] == '.') break;
    if (v[y][l] == '*') v[y][l] = '#';
    if (v[y][r] == '*') v[y][r] = '#';
    y--;
    l--;
    r++;
    sz++;
  }
  if (sz >= k || cur == '#')
    return true;
  else
    return false;
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<char>> v(n, vector<char>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> v[i][j];
  bool ok = true;
  for (int i = n - 1; i > -1; i--) {
    for (int j = 0; j < m; j++)
      if (v[i][j] != '.')
        if (!func(i, j, k, v)) {
          ok = false;
        }
  }
  cout << (ok ? "YES\n" : "NO\n");
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
}
