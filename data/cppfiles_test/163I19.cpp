#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, M = 2e3 + 5, mod = 1e9 + 7;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
void wt(long long x) {
  write(x);
  puts("");
}
long long qmi(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) (res *= a) %= mod;
    (a *= a) %= mod;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long n = read(), m = read(), rb = read(), cb = read(), rd = read(),
            cd = read(), p = read();
  vector<long long> v;
  long long cnt = 0;
  long long x = rb, y = cb, sec = 0, dx = 1, dy = 1,
            proc = (100 - p) * qmi(100, mod - 2) % mod, sum = 0, add = 0;
  while (1) {
    if (x == rd || y == cd) {
      if (x + dx > n || x + dx < 1) dx = -dx;
      if (y + dy > m || y + dy < 1) dy = -dy;
      break;
    }
    if (x + dx > n || x + dx < 1) dx = -dx;
    if (y + dy > m || y + dy < 1) dy = -dy;
    add++;
    x += dx, y += dy;
  }
  p = proc;
  map<array<long long, 4>, bool> mp;
  while (1) {
    if (mp.count({x, y, dx, dy})) break;
    if (x == rd || y == cd) {
      v.push_back(sec);
      if (sec) {
        (sum += sec * proc % mod) %= mod;
        (proc *= p) %= mod;
        sec = 0;
      }
    }
    mp[{x, y, dx, dy}] = 1;
    if (x + dx > n || x + dx < 1) dx = -dx;
    if (y + dy > m || y + dy < 1) dy = -dy;
    sec++;
    x += dx, y += dy;
  }
  if (v.size() > 2) {
    (sum += sec * proc % mod) %= mod;
    (proc *= p) %= mod;
    sec = 0;
  }
  proc = proc * qmi(p, mod - 2) % mod;
  wt((sum * (qmi(((1 - proc) % mod + mod) % mod, mod - 2)) % mod + add) % mod);
}
signed main() {
  long long _ = 1;
  cin >> _;
  while (_--) solve();
  return 0;
}
