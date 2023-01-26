#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  int64_t test;
  cin >> test;
  while (test--) {
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for (int64_t r = 0; r < n; r++) {
      cin >> a[r];
    }
    sort(a.begin(), a.end());
    int64_t sum = 0;
    for (int64_t r = 0; r < (n - 2 * k); r++) {
      sum += a[r];
    }
    for (int64_t r = 0; r < k; r++) {
      sum += (a[n - 2 * k + r] / a[n - r - 1]);
    }
    cout << sum << '\n';
  }
}
