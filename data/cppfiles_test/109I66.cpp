#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long Fact_Length = 5e5 + 1;
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
long long Mod_Inv(long long $a) { return Power($a, mod - 2); }
long long Factorial[Fact_Length];
long long Make_Factorial() {
  Factorial[0] = 1;
  for (long long i = 1; i < Fact_Length; i++) {
    Factorial[i] = (i * Factorial[i - 1]) % mod;
  }
  return 0;
}
long long Implement_Make_Factorial = Make_Factorial();
long long nCr(long long $n, long long $r) {
  if ($n < $r || $n < 0 || $r < 0) return 0;
  long long $ans = (Factorial[$n] * Mod_Inv(Factorial[$r])) % mod;
  $ans = ($ans * Mod_Inv(Factorial[$n - $r])) % mod;
  return $ans;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n + 1];
  long long pos_bw = 1;
  long long pos_wb = 1;
  long long alr_bb = 0;
  long long alr_ww = 0;
  long long tp[6] = {0};
  for (long long i = 1; i <= n; i++) {
    char x, y;
    cin >> x >> y;
    if (x == 'B') pos_wb = 0;
    if (x == 'W') pos_bw = 0;
    if (y == 'W') pos_wb = 0;
    if (y == 'B') pos_bw = 0;
    if (x == 'B' && y == 'W') continue;
    if (x == 'W' && y == 'B') continue;
    if (x == 'B' && y == 'B') alr_bb++;
    if (x == 'W' && y == 'W') alr_ww++;
    if (x == '?' && y == 'W') tp[1]++;
    if (x == 'W' && y == '?') tp[2]++;
    if (x == '?' && y == 'B') tp[3]++;
    if (x == 'B' && y == '?') tp[4]++;
    if (x == '?' && y == '?') tp[5]++;
  }
  long long ans = (pos_bw + pos_wb);
  long long n1 = tp[1] + tp[2];
  long long n2 = tp[3] + tp[4];
  long long n3 = tp[5];
  long long dp[n3 + 1];
  dp[0] = 1;
  for (long long i = 1; i <= n3; i++) dp[i] = nCr(2 * i, i);
  for (long long i = -n3; i <= n3; i++) {
    long long j = abs(i);
    long long x = dp[n3 - j];
    long long y = nCr(n3, j);
    long long xy = (x * y) % mod;
    long long dif = alr_bb + i - alr_ww;
    long long cur = 0;
    if (dif < 0) {
      dif *= -1;
      if (n2 < dif) continue;
      long long z = nCr(n2, dif);
      long long nw = n2 - dif;
      long long nb = n1;
      long long zz = nCr(nw + nb, nw);
      long long tmp = (z * zz) % mod;
      cur += (tmp * xy) % mod;
      cur %= mod;
    } else {
      if (n1 < dif) continue;
      long long z = nCr(n1, dif);
      long long nw = n1 - dif;
      long long nb = n2;
      long long zz = nCr(nw + nb, nw);
      long long tmp = (z * zz) % mod;
      cur += (tmp * xy) % mod;
      cur %= mod;
    }
    ans += cur;
    ans %= mod;
  }
  if (alr_bb == 0 && alr_ww == 0) ans -= dp[n3];
  ans %= mod;
  if (ans < 0) ans += mod;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
