#include <bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9 + 7);
const int N = 200010;
const int inf = (int)(1e9);
void solve() {
  long long l, r;
  cin >> l >> r;
  long long fact = 2;
  long long rem = 1;
  long long ans = (long long)(1e9);
  for (long long i = 1; i <= 21; i++) {
    long long cnt = 0;
    cnt += ((r - l + 1) / fact) * (fact - rem);
    if ((r - l + 1) % fact != 0) {
      if (r % fact >= rem) {
        cnt += (-rem + (r % fact) + 1);
      }
      if (l % fact >= rem) {
        cnt += (fact - (l % fact) + 1);
      }
    }
    ans = min(ans, r - l + 1 - cnt);
    fact = fact * 2;
    rem = rem * 2;
  }
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tt = 1;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
