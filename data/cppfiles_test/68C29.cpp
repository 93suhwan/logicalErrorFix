#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long k, c, r, n;
    cin >> k;
    n = sqrt(k);
    if (k == (n * n)) {
      r = n;
      c = 1;
    } else {
      if (k <= ((n * n) + n + 1)) {
        r = k - n * n;
        c = n + 1;
      } else {
        r = n + 1;
        c = (n + 1) * (n + 1) - k + 1;
      }
    }
    cout << r << "\t" << c << "\n";
  }
  return 0;
}
