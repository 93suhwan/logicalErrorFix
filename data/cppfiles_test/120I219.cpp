#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long ar[35]{};
    long long l, r;
    cin >> l >> r;
    if (l % 2 == 1 && r % 2 == 1) {
      ar[0] = (r - l) / 2 + 1;
    } else if (l % 2 == 1 && r % 2 == 0) {
      ar[0] = (r - l + 1) / 2;
    } else if (l % 2 == 0 && r % 2 == 0) {
      ar[0] = (r - l + 1) / 2;
    } else if (l % 2 == 0 && r % 2 == 1) {
      ar[0] = (r - l + 1) / 2 + 1;
    }
    for (long long i = 1; i < 30; i++) {
      long long p = (1 << i);
      long long q = (1 << (i + 1));
      if (r < p || l > q) {
        continue;
      } else if (l <= p && r >= q) {
        ar[i] = q - p;
      } else if (l <= p && r < q) {
        ar[i] = q - p - (q - r - 1);
      } else if (l > p && r < q) {
        ar[i] = q - p - (l - p - 1 + q - r - 1);
      } else if (l > p && r <= q) {
        ar[i] = q - p - (l - p - 1);
      }
    }
    long long mx = *max_element(ar, ar + 35);
    cout << r - l + 1 - mx << '\n';
  }
}
