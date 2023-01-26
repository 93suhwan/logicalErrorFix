#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int MAX = 2e5 + 10;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
const long double PI = acos(-1);
inline long long fexp(long long b, long long e) {
  long long res = 1;
  b %= MOD;
  while (e) {
    if (e & 1LL) res = (res * b) % MOD;
    e = e >> 1LL;
    b = (b * b) % MOD;
  }
  return res;
}
inline long long div_mod(long long a, long long b) {
  return (a * fexp(b, MOD - 2)) % MOD;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n, m, xi, yi, xf, yf, p;
    cin >> n >> m >> xi >> yi >> xf >> yf >> p;
    map<pair<pair<int, int>, pair<int, int> >, bool> save;
    vector<long long> d;
    int k;
    int dx = 1, dy = 1;
    for (int i = 0; true; i++) {
      if (xi + dx == 0 or xi + dx == n + 1) dx = -dx;
      if (yi + dy == 0 or yi + dy == m + 1) dy = -dy;
      if (save[{{xi, yi}, {dx, dy}}]) {
        k = i;
        break;
      }
      if (xi == xf or yi == yf) d.push_back(i);
      save[{{xi, yi}, {dx, dy}}] = true;
      xi += dx;
      yi += dy;
    }
    int kc = d.size();
    long long pn = div_mod(100 - p, 100);
    p = div_mod(p, 100);
    long long ppn = 1;
    long long ans = 0;
    for (int i = 0; i < kc; i++) {
      long long add = (p * d[i]) % MOD;
      add = (add * ppn) % MOD;
      ans = (ans + add) % MOD;
      ppn = (ppn * pn) % MOD;
    }
    ans = (ans + k * ppn) % MOD;
    ans = div_mod(ans, (1 - ppn + MOD));
    cout << ans << '\n';
  }
  return 0;
}
