#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using db = double;
using str = string;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
const db eps = 2.2204460492503131e-16;
const long long MOD = 1e9 + 7;
const ll INF = 1e18 + 5;
const db PI = acos((db)-1);
long long num_len(long long x) {
  long long res = 0;
  while (x) {
    res++;
    x /= 10;
  }
  return res;
}
enum dir { NONE, LEFT_UP, RIGHT_UP, RIGHT_DOWN, LEFT_DOWN };
long long n, m, rb, cb, rd, cd, p;
vector<vector<dir>> direction;
vi k;
long long binpow(long long a, long long p, long long mod) {
  if (!p) return 1;
  if (p & 1) return (a * binpow(a, p - 1, mod)) % mod;
  long long temp = binpow(a, p / 2, mod);
  return (temp * temp) % mod;
}
void solve() {
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  direction.assign(n, vector<dir>(m, NONE));
  long long dr = 1;
  long long dc = 1;
  dir d = RIGHT_DOWN;
  long long t = 0;
  while (1) {
    if (rd == rb || cd == cb) k.push_back(t);
    if (dr == 1 && dc == 1) {
      if (rb + 1 > n) {
        dr *= -1;
        d = RIGHT_UP;
      }
      if (cb + 1 > m) {
        dc *= -1;
        d = LEFT_DOWN;
      }
      if (rb == n && cb == m) d = LEFT_UP;
    } else if (dr == -1 && dc == 1) {
      if (rb - 1 < 1) {
        dr *= -1;
        d = RIGHT_UP;
      }
      if (cb + 1 > m) {
        dc *= -1;
        d = LEFT_UP;
      }
      if (rb == 1 && cb == m) d = LEFT_DOWN;
    } else if (dr == 1 && dc == -1) {
      if (rb + 1 > n) {
        dr *= -1;
        d = LEFT_UP;
      }
      if (cb - 1 < 1) {
        dc *= -1;
        d = RIGHT_DOWN;
      }
      if (rb == n && cb == 1) d = RIGHT_UP;
    } else {
      if (rb - 1 < 1) {
        dr *= -1;
        d = LEFT_DOWN;
      }
      if (cb - 1 < 1) {
        dc *= -1;
        d = RIGHT_UP;
      }
      if (rb == 1 && cb == 1) d = RIGHT_DOWN;
    }
    rb += dr;
    cb += dc;
    t++;
    if (d == direction[rb - 1][cb - 1]) break;
    direction[rb - 1][cb - 1] = d;
  }
  k.pop_back();
  long long x = 0, y = p * p * 100;
  for (long long r = 0; r < k.size(); r++) {
    x = (x + (100 - p) * (r + t * 100)) % MOD;
  }
  x = (x * p) % MOD;
  y = binpow(y, MOD - 2, MOD);
  cout << (x * y) % MOD << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
