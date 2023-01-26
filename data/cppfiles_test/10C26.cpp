#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long Fact_Length = 1e5 + 1;
long long Power(long long base, long long expo) {
  long long $result = 1;
  base %= mod;
  while (expo) {
    if (expo % 2 == 1) $result = ($result * base) % mod;
    base = (base * base) % mod;
    expo /= 2;
  }
  return $result;
}
void solve() {
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long a1x, a1y, b1x, b1y;
  cin >> a1x >> a1y >> b1x >> b1y;
  long long tot = n * m;
  long long cmn = r * c;
  if (a1x == b1x && a1y == b1y) cmn = 0;
  tot -= cmn;
  long long ans = Power(k, tot);
  cout << ans << "\n";
  return;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
