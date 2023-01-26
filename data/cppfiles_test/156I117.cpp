#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < (n); i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort((a).begin(), (a).end());
    long long ans = 0;
    if (sum > k) {
      ans = sum - k;
      long long tot = 0;
      for (int i = 1; i < n - 1; i++) {
        long long x = tot - k;
        long long y = -ceil(x / (1.0 * (n - i)));
        ans = min(ans, abs(a[0] - y) + (n - i));
        tot += a[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
