#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
const int MAXN = 1e3;
const int MOD = (int)1e9 + 7;
void clear() {}
void precalc() {}
int fields[MAXN][MAXN];
int vals[MAXN][MAXN];
int p[MAXN][MAXN];
int get_parent(int i, int j) {
  return p[i][j] == i ? i : p[i][j] = get_parent(p[i][j], j);
}
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      p[i][j] = i;
      cin >> fields[i][j];
      if (fields[i][j] == 2) p[i][j] = i + 1;
    }
  }
  for (int j = 0; j < m; ++j) p[n][j] = n;
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    c--;
    int x = 0;
    int y = c;
    while (x < n) {
      x = get_parent(x, y);
      if (x < n) {
        int d_y = y + 2 - fields[x][y];
        p[x][y] = x + 1;
        y = d_y;
      }
    }
    cout << y + 1 << ' ';
  }
}
void multisolve() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  precalc();
  solve();
  return 0;
}
