#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    long long n = a.size(), m = b.size();
    long long j1 = 0, j2 = 0;
    bool e1 = 1, e2 = 0;
    long long i1, i2;
    for (long long i = 0; i < n; i++) {
      if (j1 < m and a[i] == b[j1] and (i & 1) == e1) {
        j1++;
        e1 ^= 1;
        if (j1 == m) i1 = i;
      }
      if (j2 < m and a[i] == b[j2] and (i & 1) == e2) {
        j2++;
        e2 ^= 1;
        if (j2 == m) i2 = i;
      }
    }
    cout << ((j1 == m and ((n - 1) - i1) % 2 == 0) ||
                     (j2 == m and ((n - 1) - i2) % 2 == 0)
                 ? "YES\n"
                 : "NO\n");
  }
}
