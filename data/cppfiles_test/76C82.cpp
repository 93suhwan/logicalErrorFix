#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vvii = vector<vector<ii>>;
using ll = long long;
using ld = long double;
int RAM = 120;
int main() {
  int n, m;
  cin >> n >> m;
  n = min(n, RAM);
  vvi g(n, vi(n, 0));
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a < n and b < n) {
      g[a][b] = 1;
      g[b][a] = 1;
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      for (int k = j + 1; k < n; ++k)
        for (int l = k + 1; l < n; ++l)
          for (int t = l + 1; t < n; ++t) {
            if (g[i][j] == g[i][k] && g[i][j] == g[i][l] &&
                g[i][j] == g[i][t] && g[i][j] == g[j][k] &&
                g[i][j] == g[j][l] && g[i][j] == g[j][t] &&
                g[i][j] == g[k][l] && g[i][j] == g[k][t] &&
                g[i][j] == g[l][t]) {
              cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << l + 1
                   << " " << t + 1 << '\n';
              return 0;
            }
          }
  cout << -1 << '\n';
}
