#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long a[N], b[N];
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, p = 0, q = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) {
      long long mn = min(i + 2, (long long)30);
      for (long long j = 2; j <= mn; j++) {
        if (a[i] % j != 0) {
          p = 1;
          break;
        }
      }
      if (!p) {
        q = 1;
        break;
      }
      p = 0;
    }
    cout << (q ? "NO\n" : "YES\n");
  }
}
