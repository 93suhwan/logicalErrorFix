#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k;
int32_t main() {
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    long long c = 0;
    long long b = n - (n / m) * m;
    for (long long i = 0; i < k; ++i) {
      for (long long j = 0; j < b; ++j) {
        cout << n / m + 1;
        for (long long a = 0; a < n / m + 1; ++a) {
          cout << " " << c + 1;
          c = (c + 1) % n;
        }
        cout << "\n";
      }
      long long d = c;
      for (long long j = b; j < m; ++j) {
        cout << n / m;
        for (long long a = 0; a < n / m; ++a) {
          cout << " " << d + 1;
          d = (d + 1) % n;
        }
        cout << "\n";
      }
    }
    cout << "\n";
  }
}
