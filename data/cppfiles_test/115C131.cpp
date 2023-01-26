#include <bits/stdc++.h>
using namespace std;
long long t, n, h;
long long a[1000];
bool p(long long k) {
  if (n == 1) {
    if (k >= h)
      return true;
    else
      return false;
  }
  long long last = a[0];
  long long health = h;
  for (long long i = 1; i < n; i++) {
    health -= min(a[i] - a[i - 1], k);
    if (health <= 0) return true;
  }
  health -= k;
  if (health <= 0) return true;
  return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n >> h;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long lo = 1;
    long long hi = 1000000000000000000;
    long long mid = lo + (hi - lo) / 2;
    while (lo < hi) {
      mid = lo + (hi - lo) / 2;
      if (p(mid))
        hi = mid;
      else
        lo = mid + 1;
    }
    cout << lo << endl;
  }
  return 0;
}
