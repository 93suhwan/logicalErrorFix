#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
const long long inf = 1e9 + 228;
const long long infll = 4e18;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long double eps = 1e-14;
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
long long kek[1000000][2];
long long cnt_ok = 0, cnt_blocked = 0;
long long cnt_ok2 = 0, cnt_blocked2 = 0;
long long counter1[2][2];
long long counter2[1000000][2];
long long binpow(long long n, long long k) {
  if (!k) return 1;
  if (k & 1) return binpow(n, k - 1) * n % mod2;
  long long b = binpow(n, k / 2);
  return b * b % mod2;
}
void solve() {
  long long n, m, q;
  cin >> n >> m >> q;
  cnt_ok = m;
  map<pair<long long, long long>, long long> lol;
  cnt_ok = m;
  cnt_ok2 = n;
  for (long long i = 0; i < q; i++) {
    long long x, y, t;
    cin >> x >> y >> t;
    x--, y--;
    if (t == -1) {
      if (lol.count(make_pair(x, y))) {
        long long was = lol[make_pair(x, y)];
        if (x & 1) was ^= 1;
        if (kek[y][was] == 1) {
          if (kek[y][was ^ 1]) cnt_blocked--;
          if (!kek[y][was ^ 1]) cnt_ok++;
        }
        kek[y][was]--;
        counter1[y & 1][was]--;
        if (counter2[x][was ^ (y & 1)] == 1) {
          if (counter2[x][was ^ (y & 1) ^ 1] == 0) {
            cnt_ok2++;
          } else {
            cnt_blocked2--;
          }
        }
        counter2[x][was ^ (y & 1)]--;
        lol.erase(make_pair(x, y));
      }
    } else {
      if (lol.count(make_pair(x, y))) {
        long long was = lol[make_pair(x, y)];
        if (x & 1) was ^= 1;
        if (kek[y][was] == 1) {
          if (kek[y][was ^ 1]) cnt_blocked--;
          if (!kek[y][was ^ 1]) cnt_ok++;
        }
        kek[y][was]--;
        counter1[y & 1][was]--;
        if (counter2[x][was ^ (y & 1)] == 1) {
          if (counter2[x][was ^ (y & 1) ^ 1] == 0) {
            cnt_ok2++;
          } else {
            cnt_blocked2--;
          }
        }
        counter2[x][was ^ (y & 1)]--;
        lol.erase(make_pair(x, y));
      }
      lol[make_pair(x, y)] = t;
      if (x & 1) t ^= 1;
      if (kek[y][t] == 0) {
        if (kek[y][t ^ 1] == 0) {
          cnt_ok--;
        } else {
          cnt_blocked++;
        }
      }
      counter1[y & 1][t]++;
      if (counter2[x][t ^ (y & 1)] == 0) {
        if (counter2[x][t ^ (y & 1) ^ 1] == 0) {
          cnt_ok2--;
        } else {
          cnt_blocked2++;
        }
      }
      counter2[x][t ^ (y & 1)]++;
      kek[y][t]++;
    }
    long long ans = (cnt_blocked ? 0 : binpow(2, cnt_ok));
    ans -= (!counter1[0][0]) & (!counter1[1][1]);
    ans -= (!counter1[0][1]) & (!counter1[1][0]);
    if (!cnt_blocked2) {
      ans += binpow(2, cnt_ok2);
    }
    ans %= mod2;
    if (ans < 0) ans += mod2;
    cout << ans << '\n';
  }
}
signed main() {
  fast_io();
  cout << fixed << setprecision(10);
  long long q = 1;
  while (q--) solve();
}
