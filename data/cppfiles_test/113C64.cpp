#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  long long a[n], sum = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  long long m;
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    long long i = lower_bound(a, a + n, x) - a;
    long long ans = 0, S = sum;
    if (i == n)
      S -= x, ans += x - a[n - 1];
    else
      S -= a[i];
    ans += max(0ll, y - S);
    if (i) {
      i--;
      long long now = 0;
      S = sum - a[i];
      now += x - a[i];
      now += max(0ll, y - S);
      ans = min(ans, now);
    }
    cout << ans << "\n";
  }
  return 0;
}
