#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(50, vector<int>(50, 0));
  for (int i = 1; i <= M; i++) {
    int u, v;
    cin >> u >> v;
    if (u <= 49 && v <= 49) {
      g[u][v] = 1;
      g[v][u] = 1;
    }
  }
  for (int a = 1; a <= min(N, 48); a++) {
    for (int b = a + 1; b <= min(N, 48); b++) {
      for (int c = b + 1; c <= min(N, 48); c++) {
        for (int d = c + 1; d <= min(N, 48); d++) {
          for (int e = d + 1; e <= min(N, 48); e++) {
            if ((g[a][b] && g[a][c] && g[a][d] && g[a][e] && g[b][c] &&
                 g[b][d] && g[b][e] && g[c][d] && g[c][e] && g[d][e]) ||
                !(g[a][b] || g[a][c] || g[a][d] || g[a][e] || g[b][c] ||
                  g[b][d] || g[b][e] || g[c][d] || g[c][e] || g[d][e])) {
              cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
