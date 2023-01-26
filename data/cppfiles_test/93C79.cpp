#include <bits/stdc++.h>
using namespace std;
long long ceiling(long double n) {
  if (n == (long long)n)
    return n;
  else
    return n + 1;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k, helper = 1, ans = 0;
    cin >> n >> k;
    while (helper < k && (n - helper) > 0) {
      helper *= 2;
      ans++;
    }
    if (n > helper) ans += ceiling((n - helper) * 1.0 / k);
    cout << ans << "\n";
  }
}
