#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    long long ans = a[0];
    for (long long i = 1; i < n; i++) {
      ans = max(ans, a[i] - a[i - 1]);
    }
    cout << ans << '\n';
  }
  return 0;
}
