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
    int c, r = 0;
    cin >> c;
    --c;
    while (1) {
      if (g[r][c] == 1) {
        g[r][c] = 2;
        ++c;
      } else if (g[r][c] == 3) {
        g[r][c] = 2;
        --c;
      } else
        r++;
      if (r == n) {
        cout << c + 1 << " ";
        break;
      }
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
