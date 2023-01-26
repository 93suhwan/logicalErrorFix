#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    long long i = n - (2 * k), j = n - 1;
    long long mid = (j - i + 1) / 2 + i;
    long long score = 0;
    while (i < mid && mid < n) {
      score += (min(a[i], a[mid]) / max(a[i], a[mid]));
      i++;
      mid++;
    }
    long long idx = n - (2 * k);
    for (long long i = 0; i < idx; i++) score += a[i];
    cout << score << "\n";
  }
  return 0;
}
