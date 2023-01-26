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
    map<long long int, long long int> m;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      k = max(k, a[i]);
      m[a[i]] = i;
    }
    sort(a, a + n);
    p = m[a[n - 1]];
    long long int x = p, ans = n - p - 1;
    for (long long int i = n - 2; i >= 0; i--) {
      if (m[a[i]] > x) {
        ans -= m[a[i]] - x - 1;
        x = m[a[i]];
      }
    }
    cout << ans << endl;
  }
}
