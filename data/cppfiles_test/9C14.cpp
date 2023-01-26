#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
set<pair<int, int>> s[N];
int g[N][N], n, m, k;
const int inf = 1e9;
void solve() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> g[i][j];
      if (g[i][j] != 2) {
        s[j].insert({i, g[i][j]});
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    int c;
    cin >> c;
    --c;
    int r = 0;
    while (r < n && (int)(s[c]).size() > 0) {
      auto it = s[c].lower_bound({r, 0});
      if (it == s[c].end()) {
        break;
      }
      auto [rr, d] = *it;
      s[c].erase(it);
      assert(c >= 0 && c < m);
      c += (d == 1 ? 1 : -1);
      r = rr;
    }
    cout << c + 1 << ' ';
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  while (t--) solve();
}
