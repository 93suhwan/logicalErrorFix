#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a, b, x;
    bool cond = false;
    for (long long i = 2; i < n; i++) {
      x = n % i;
      for (long long j = n - 1; j > i; j++) {
        if (n % j == x) {
          a = i;
          b = j;
          cond = true;
          break;
        }
      }
      if (cond) {
        break;
      }
    }
    cout << a << " " << b << '\n';
  }
  return 0;
}
