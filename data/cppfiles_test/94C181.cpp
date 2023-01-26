#include <bits/stdc++.h>
using namespace std;
long long T, n, k;
long long a[15], bb[15], po[15];
long long lp(int t) {
  long long d = 1;
  for (int i = 1; i <= t; ++i) d = d * 10;
  return d;
}
int main() {
  cin >> T;
  for (int ii = 1; ii <= T; ++ii) {
    cin >> n >> k;
    k = k + 1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (i > 1) {
        bb[i - 1] = lp(a[i] - a[i - 1]) - 1;
        po[i - 1] = bb[i - 1] + po[i - 2];
      }
    }
    long long ans = 0;
    for (int d = n - 1; d >= 1; --d)
      if (k > po[d]) {
        ans += lp(a[d + 1]) * (k - po[d]);
        k -= (k - po[d]);
      }
    cout << ans + k << endl;
  }
  return 0;
}
