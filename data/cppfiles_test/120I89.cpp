#include <bits/stdc++.h>
using namespace std;
long long pref(long long l, long long r) {
  while (r > 1) {
    r >>= 1;
    l >>= 1;
  }
  return l > 0;
}
long long getPrev(long long n) {
  long long k = 1;
  while (n > 1) {
    n >>= 1;
    k <<= 1;
  }
  return (k - 1);
}
long long getNext(long long n) {
  long long k = 1;
  while (n) {
    n >>= 1;
    k <<= 1;
  }
  return k;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = 0;
    while (pref(l, r) == 0) {
      long long ub = getPrev(r), lb = getNext(l);
      if (r - ub < lb - l) {
        ans += (r - ub);
        r = ub;
      } else {
        ans += (lb - l);
        l = lb;
      }
    }
    ans = min(ans, (r - l + 1));
    cout << ans << "\n";
  }
  return 0;
}
