#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 5;
long long a[maxn][maxn];
int32_t main() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 2) a[i][j] = 0;
      if (a[i][j] == 3) a[i][j] = -1;
    }
  }
  for (long long q = 1; q <= k; q++) {
    long long s;
    cin >> s;
    for (long long i = 1; i <= n; i++) {
      if (a[i][s] == 2) continue;
      long long d = a[i][s];
      while (a[i][s] == d) {
        a[i][s] = 2;
        s += d;
      }
      if (a[i][s] == -d) {
        a[i][s] = 2;
        s -= d;
      }
      a[i][s] = 2;
    }
    cout << s << ' ';
  }
  cout << endl;
  return 0;
}
