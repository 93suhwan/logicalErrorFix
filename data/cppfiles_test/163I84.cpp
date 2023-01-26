#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "trapv"
long long powerr(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  long long z = powerr(x, y / 2);
  z = z * z;
  z %= 1000000007;
  if (y % 2) {
    z = z * x;
    z %= 1000000007;
  }
  return z;
}
long long inv(long long x) { return powerr(x, 1000000007 - 2); }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, rb, cb, rd, cd, p;
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    rb--;
    cb--;
    rd--;
    cd--;
    p = p * inv(100);
    p %= 1000000007;
    long long currx = rb;
    long long curry = cb;
    long long dr = 1;
    long long dc = 1;
    long long startx = rb;
    long long starty = cb;
    long long e = 0;
    long long hits = 0;
    long long moves = 0;
    while (1) {
      if (rd == rb || cd == cb) {
        long long gg = (moves * p);
        gg %= 1000000007;
        long long zz = 1;
        for (long long i = 0; i < hits; i++) {
          zz = zz * (1000000007 + 1 - p);
          zz %= 1000000007;
        }
        zz = zz * gg;
        zz %= 1000000007;
        e += zz;
        e %= 1000000007;
        hits++;
      }
      if (rb + dr >= n || rb + dr < 0) {
        dr = -dr;
      }
      if (cb + dc >= m || cb + dc < 0) {
        dc = -dc;
      }
      rb = rb + dr;
      cb = cb + dc;
      if (rb == startx && cb == starty) {
        moves++;
        break;
      }
      moves++;
    }
    long long lol = 1;
    for (long long i = 0; i < hits; i++) {
      lol = lol * (1000000007 + 1 - p);
      lol %= 1000000007;
    }
    long long den = (1000000007 + 1 - lol);
    den %= 1000000007;
    long long t1 = (e * inv(den)) % 1000000007;
    long long t2 = (lol * moves) % 1000000007;
    t2 = t2 * den;
    t2 %= 1000000007;
    long long gg = den;
    t2 = t2 * inv(gg);
    t2 %= 1000000007;
    t2 = t2 * inv(gg);
    t2 %= 1000000007;
    t2 %= 1000000007;
    cout << (t1 + t2) % 1000000007 << "\n";
  }
}
