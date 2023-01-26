#include <bits/stdc++.h>
using namespace std;
long long adj[44][44];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 0; i < 44; i++)
    for (long long j = 0; j < 44; j++) adj[i][j] = 0;
  long long n, m;
  cin >> n >> m;
  long long nn = min(n, (long long)43);
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    if (x <= nn && y <= nn) {
      adj[x][y] = 1;
      adj[y][x] = 1;
    }
  }
  for (long long i = 1; i < nn - 3; i++) {
    for (long long j = i + 1; j < nn - 2; j++) {
      for (long long k = j + 1; k < nn - 1; k++) {
        for (long long l = k + 1; l < nn; l++) {
          for (long long m = l + 1; m < nn + 1; m++) {
            long long c = 0;
            if (adj[i][j]) c++;
            if (adj[i][k]) c++;
            if (adj[i][l]) c++;
            if (adj[i][m]) c++;
            if (adj[j][k]) c++;
            if (adj[j][l]) c++;
            if (adj[j][m]) c++;
            if (adj[k][l]) c++;
            if (adj[k][m]) c++;
            if (adj[l][m]) c++;
            if (c == 10 || c == 0) {
              cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << -1 << endl;
}
