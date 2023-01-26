#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long c = 0;
  for (long long i = 0; i + 1 < n; i += 2) {
    long long tmp = 0;
    long long res = a[i];
    long long p0 = i + 2;
    c += min(a[i], a[i + 1]);
    tmp -= min(a[i], a[i + 1]);
    res -= min(a[i], a[i + 1]);
    tmp = 0;
    while (p0 + 1 < n and tmp >= 0) {
      tmp += a[p0];
      tmp -= a[p0 + 1];
      if (tmp <= 0) {
        c += min(res, abs(tmp)) + 1;
        long long x = min(res, abs(tmp));
        tmp += x;
        res -= x;
      }
      p0 += 2;
    }
  }
  cout << c << '\n';
  return 0;
}
