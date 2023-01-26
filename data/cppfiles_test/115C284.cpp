#include <bits/stdc++.h>
using namespace std;
long long arr[105];
bool ok(long long k, long long n, long long h) {
  long long i, sum = 0;
  for (i = 1; i < n; i++) {
    sum += (min(arr[i] - arr[i - 1], k));
  }
  sum += k;
  if (sum >= h) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, h, i, lo, hi, mid, ans;
  cin >> t;
  while (t--) {
    cin >> n >> h;
    for (i = 0; i < n; i++) cin >> arr[i];
    lo = 1;
    hi = 1e18;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (ok(mid, n, h)) {
        ans = mid;
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
