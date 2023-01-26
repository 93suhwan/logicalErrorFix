#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long mod = 9901;
const long long N = 1e5 + 100, M = 110;
long long a[N];
signed main() {
  std::ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 0) {
      long long p = (max(a, b) - min(a, b)) / 2;
      long long cnt = min(a, b) + 1;
      cout << cnt << endl;
      while (cnt--) {
        cout << p;
        p += 2;
        if (cnt != 0) cout << ' ';
      }
      cout << endl;
    } else {
      long long k = max(a, b) - min(a, b);
      k = k / 2;
      cout << a + b - k * 2 + 1 << endl;
      for (long long i = k; i <= a + b - k; i++) {
        if (i != k) cout << ' ';
        cout << i;
      }
      cout << endl;
    }
  }
}
