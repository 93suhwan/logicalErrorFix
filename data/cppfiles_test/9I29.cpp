#include <bits/stdc++.h>
using namespace std;
int dx[]{-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
long long const mod = 1e9 + 7;
int const N = 1e5 + 10;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  int g[n][m];
  vector<set<int>> s(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
      if (g[i][j] != 2) {
        s[j].insert(i);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    --x;
    int y = 0;
    while (1) {
      auto k = s[x].upper_bound(y);
      if (k == s[x].begin()) {
        cout << x + 1 << " ";
        break;
      }
      s[x].erase(y);
      if (g[x][*k] == 1) {
        ++x;
      } else
        --x;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
