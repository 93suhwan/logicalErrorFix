#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long m, n;
    cin >> m >> n;
    long long ar[m][n];
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) {
        cin >> ar[i][j];
      }
    }
    long long ans = INT_MAX;
    for (long long i = 0; i < n; i++) {
      long long p = 0;
      for (long long j = 0; j < m; j++) {
        p = max(p, ar[j][i]);
      }
      ans = min(ans, p);
    }
    long long p = 0;
    for (long long i = 0; i < m; i++) {
      sort(ar[i], ar[i] + n);
      p = max(p, ar[i][n - 2]);
    }
    cout << min(ans, p) << endl;
  }
}
