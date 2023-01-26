#include <bits/stdc++.h>
using namespace std;
int n, m, g[55][55];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a < 55 && b < 55) g[a][b] = g[b][a] = 1;
  }
  for (int a = 1; a <= min(48, n); a++)
    for (int b = a + 1; b <= min(48, n); b++)
      for (int c = b + 1; c <= min(48, n); c++)
        for (int d = c + 1; d <= min(48, n); d++)
          for (int e = d + 1; e <= min(48, n); e++)
            if ((g[a][b] && g[a][c] && g[a][d] && g[a][e] && g[b][c] &&
                 g[b][d] && g[b][e] && g[c][d] && g[c][e] && g[d][e]) ||
                (!g[a][b] && !g[a][c] && !g[a][d] && !g[a][e] && !g[b][c] &&
                 !g[b][d] && !g[b][e] && !g[c][d] && !g[c][e] && !g[d][e]))
              return cout << a << " " << b << " " << c << " " << d << " " << e,
                     0;
  cout << -1;
}
