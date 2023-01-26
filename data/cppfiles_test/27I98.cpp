#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    if (m < n - 1 || m > (n * (n - 1) / 2)) {
      cout << "NO" << '\n';
    } else if (k - 2 >= 1 && m == n * (n - 1) / 2) {
      cout << "YES" << '\n';
    } else if (k - 2 >= 2) {
      cout << "YES" << '\n';
    } else
      cout << "NO" << '\n';
  }
}
