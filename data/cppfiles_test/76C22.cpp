#include <bits/stdc++.h>
using namespace std;
bool ok[51][51];
signed main() {
  long long n, m;
  cin >> n >> m;
  n = min(n, 50ll);
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    if (u <= n && v <= n) {
      ok[u][v] = 1;
      ok[v][u] = 1;
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      for (long long k = j + 1; k <= n; k++) {
        for (long long l = k + 1; l <= n; l++) {
          for (long long o = l + 1; o <= n; o++) {
            vector<long long> v = {i, j, k, l, o};
            bool can = 1;
            for (long long p = 0; p < 5; p++) {
              for (long long q = p + 1; q < 5; q++) {
                if (ok[v[p]][v[q]] != ok[v[0]][v[1]]) can = 0;
              }
            }
            if (can) {
              cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << o << '\n';
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "-1\n";
}
