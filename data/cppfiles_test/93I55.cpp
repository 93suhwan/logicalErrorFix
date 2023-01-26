#include <bits/stdc++.h>
using namespace std;
long long minimum(long long a, long long b) { return (a < b ? a : b); }
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, ans = 0, helper = 1, h = 1;
    cin >> n >> k;
    while (helper < k && (n - helper) > 0) {
      helper *= 2;
      ans++;
      h = 0;
    }
    long long remaining = ceil(((n - h) - (helper / 2)) / k);
    ans += remaining;
    cout << ans << "\n";
  }
}
