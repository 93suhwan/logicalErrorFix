#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int N = min(50, n);
  int adj[N + 1][N + 1];
  memset(adj, 0, sizeof(adj));
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > N or v > N) continue;
    if (u < v)
      adj[u][v] = 1;
    else
      adj[v][u] = 1;
  }
  for (int a = 1; a <= N; a++) {
    for (int b = a + 1; b <= N; b++) {
      for (int c = b + 1; c <= N; c++) {
        if (adj[a][b] != adj[b][c] or adj[b][c] != adj[a][c]) continue;
        for (int d = c + 1; d <= N; d++) {
          if (adj[a][d] != adj[a][b]) continue;
          if (adj[a][d] != adj[b][d] or adj[b][d] != adj[c][d]) continue;
          for (int e = d + 1; e <= N; e++) {
            if (adj[a][e] != adj[a][b]) continue;
            if (adj[a][e] != adj[b][e] or adj[a][e] != adj[c][e] or
                adj[a][e] != adj[d][e])
              continue;
            cout << a << " " << b << " " << c << " " << d << " " << e << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << -1 << endl;
}
