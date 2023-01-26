#include <bits/stdc++.h>
using namespace std;
bool ok(long long m, long long n, long long k) {
  long long knt = min(m, k) * (min(m, k) + 1) / 2;
  if (knt >= n) return true;
  if (k * max(1ll * 0, m - k) >= n - knt) return true;
  return false;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long l = -1, r = 2e18;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if (ok(m, n - 1, k))
        r = m;
      else
        l = m;
    }
    cout << r << endl;
  }
  return 0;
}
