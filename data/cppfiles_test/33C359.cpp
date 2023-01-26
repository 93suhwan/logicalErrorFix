#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, m = 0, c = 0, ans = 0;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n - 1; i++) {
      c = a[i] * a[i + 1];
      if (c > m) {
        m = c;
      }
    }
    cout << m << endl;
  }
  return 0;
}
