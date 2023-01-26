#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long sq = 1;
    long long x, y;
    for (long long i = 0; i * i <= (long long)1e18; i++) {
      if (i * i >= k) {
        sq = i;
        break;
      }
    }
    if (sq * sq - k >= sq) {
      y = sq;
      x = k - (sq - 1) * (sq - 1);
    } else {
      x = sq;
      y = abs(sq * sq - k) + 1;
    }
    cout << x << " " << y << "\n";
  }
  return 0;
}
