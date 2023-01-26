#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      long long ans = x - i - 1;
      mx = max(mx, ans);
    }
    cout << mx << "\n";
  }
  return 0;
}
