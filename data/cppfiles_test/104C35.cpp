#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(51);
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, bal = 0;
    cin >> n >> m;
    vector<long long> a(n), b(n), cola(n), colb(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      cola[i] = min(a[i], m);
      colb[i] = m - cola[i];
      bal -= (a[i] - cola[i]);
      bal += (b[i] - colb[i]);
    }
    if (bal > 0) {
      for (long long i = 0; i < n; i++) {
        long long can = min(b[i] - colb[i], cola[i]);
        if (bal > 2 * can) {
          cola[i] -= can, colb[i] += can;
          bal -= 2 * can;
        } else {
          cola[i] -= bal / 2, colb[i] += bal / 2;
          break;
        }
      }
    }
    long long sum = 0;
    for (long long i = 0; i < n; i++)
      sum += (a[i] - cola[i]) - (b[i] - colb[i]);
    cout << abs(sum) << endl;
    for (long long i = 0; i < n; i++) {
      cout << cola[i] << ' ' << colb[i] << endl;
    }
  }
  return 0;
}
