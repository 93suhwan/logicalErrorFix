#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n;
  cin >> n;
  long long sum = 0;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(), a.end());
  long long m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    long long i = lower_bound(a.begin(), a.end(), x) - a.begin();
    long long ans = 2e18;
    if (i > 0) ans = min(ans, (x - a[i - 1]) + max(0LL, y - sum + a[i - 1]));
    if (i < n) ans = min(ans, max(0LL, y - sum + a[i]));
    cout << ans << "\n";
  }
  return 0;
}
