#include <bits/stdc++.h>
using namespace std;
long long cnt(long long n, long long x) {
  n++;
  long long l = n / x;
  long long m = (n - (l * x));
  long long ans = (l / 2) * x;
  if (l % 2 == 1) ans += m;
  return ans;
}
void solve() {
  long long l, r;
  cin >> l >> r;
  long long tot = r - l + 1;
  long long ans = tot - 1;
  long long p2 = 1;
  while (p2 <= r) {
    long long tmp = cnt(r, p2) - cnt(l - 1, p2);
    tmp = tot - tmp;
    ans = min(ans, tmp);
    p2 *= 2;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
