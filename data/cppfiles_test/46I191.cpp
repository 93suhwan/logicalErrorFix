#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k = 1, count = 1, p;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      k = max(k, a[i]);
    }
    for (long long int i = n - 1; i >= 0; i--) {
      if (a[i] == k) {
        p = i;
        break;
      }
    }
    if (p == n - 1) {
      cout << 0 << endl;
      continue;
    }
    long long int x = a[p + 1], ans = n - p;
    for (long long int i = p + 1; i < n; i++) {
      if (a[i] >= x) {
        x = a[i];
        ans--;
      } else {
        x = a[i];
      }
    }
    cout << ans << endl;
  }
}
