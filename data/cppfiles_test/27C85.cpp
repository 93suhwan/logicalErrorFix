#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k, f;
    cin >> n >> m >> k;
    long long mx_edge = ((n * (n - 1)) / 2), mn_edge = n - 1, mx_d, min_d;
    if (n == 1) {
      min_d = 0, mx_d = 0;
    } else if (n == 2) {
      min_d = 1, mx_d = 1;
    } else {
      min_d = 2, mx_d = n - 1;
    }
    if (m == mx_edge && n != 1 && n != 2) min_d = 1;
    if (m < mn_edge || m > mx_edge)
      f = 0;
    else {
      if (min_d < (k - 1))
        f = 1;
      else
        f = 0;
    }
    if (f)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
