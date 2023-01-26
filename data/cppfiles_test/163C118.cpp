#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long inf = 1e17;
long long get_pow(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % mod;
    b /= 2;
    a = (a * a) % mod;
  }
  return ans;
}
void add(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, rb, cb, rd, cd, pp;
    cin >> n >> m >> rb >> cb >> rd >> cd >> pp;
    long long p = ((100 - pp) * get_pow(100, mod - 2)) % mod;
    long long ppow = 1;
    long long mpow = 0;
    long long ans = 0;
    long long dr = 1, dc = 1;
    if (rb + dr > n || rb + dr < 1) dr = -dr;
    if (cb + dc > m || cb + dc < 1) dc = -dc;
    while (rb != rd && cb != cd) {
      if (rb + dr > n || rb + dr < 1) dr = -dr;
      if (cb + dc > m || cb + dc < 1) dc = -dc;
      rb += dr;
      cb += dc;
      if (rb + dr > n || rb + dr < 1) dr = -dr;
      if (cb + dc > m || cb + dc < 1) dc = -dc;
      ans++;
    }
    long long moves = 0;
    long long mm = 40000000;
    if (rb + dr > n || rb + dr < 1) dr = -dr;
    if (cb + dc > m || cb + dc < 1) dc = -dc;
    long long odr = dr, odc = dc, rrb = rb, ccb = cb;
    vector<long long> s;
    long long last = 0;
    do {
      if (rb + dr > n || rb + dr < 1) dr = -dr;
      if (cb + dc > m || cb + dc < 1) dc = -dc;
      rb += dr;
      cb += dc;
      if (rb + dr > n || rb + dr < 1) dr = -dr;
      if (cb + dc > m || cb + dc < 1) dc = -dc;
      last++;
      if (rb == rd || cb == cd) {
        s.push_back(last);
        last = 0;
      }
      moves++;
      if (moves > mm) {
        return 69;
      }
    } while (((rb != rrb || cb != ccb) || (dc != odc || odr != dr)));
    long long tans = 0;
    for (long long i = 0; i < s.size(); i++) {
      ppow *= p;
      ppow %= mod;
      add(tans, (ppow * s[i]) % mod);
    }
    tans = (tans * get_pow((mod + 1 - ppow), mod - 2)) % mod;
    add(ans, tans);
    cout << ans << endl;
  }
}
