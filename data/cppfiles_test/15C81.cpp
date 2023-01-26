#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long inf = 4e18;
const long long N = 1e6;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    char a[n][m];
    bool pos[n][m];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
        pos[i][j] = 0;
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (a[i][j] == '.') continue;
        long long d = 0;
        for (long long h = 1; h <= min({i, j, m - 1 - j}); h++) {
          if (a[i - h][j - h] == '*' && a[i - h][j + h] == '*')
            d++;
          else
            break;
        }
        if (d < k) continue;
        pos[i][j] = 1;
        for (long long h = 1; h <= min({i, j, m - 1 - j}); h++) {
          if (a[i - h][j - h] == '*' && a[i - h][j + h] == '*')
            pos[i - h][j - h] = 1, pos[i - h][j + h] = 1;
          else
            break;
        }
      }
    }
    bool boob = 1;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (a[i][j] == '*' && !pos[i][j]) boob = 0;
      }
    }
    if (boob)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
