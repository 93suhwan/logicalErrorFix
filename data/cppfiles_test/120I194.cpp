#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long ar[35]{};
    long long l, r;
    cin >> l >> r;
    long long pa;
    if (l % 2 == 0 && r % 2 == 0) {
      pa = (r - l) / 2 + 1;
    } else if (l % 2 == 0 && r % 2 == 1) {
      pa = (r - l) / 2 + 1;
    } else if (l % 2 == 1 && r % 2 == 0) {
      pa = (r - l) / 2 + 1;
    } else if (l % 2 == 1 && r % 2 == 1) {
      pa = (r - l) / 2;
    }
    for (long long i = 1; i < 30; i++) {
      long long p = (1 << i);
      long long q = (1 << (i + 1)) - 1;
      if (l <= p) {
        if (r >= q) {
          ar[i] = q - p + 1;
        } else {
          ar[i] = r - p + 1;
        }
      } else {
        if (r >= q) {
          ar[i] = q - l + 1;
        } else {
          ar[i] = r - l + 1;
        }
      }
    }
    long long mx = *max_element(ar, ar + 35);
    cout << min(r - l + 1 - mx, pa) << '\n';
  }
}
