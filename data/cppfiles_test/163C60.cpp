#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vec = vector<int>;
using veg = vector<pii>;
template <typename T>
T read() {
  T x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
template <typename T>
void chkmax(T &x, const T &y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, const T &y) {
  x = x < y ? x : y;
}
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
ll qp(ll x, int t) {
  ll res = 1;
  for (; t; t >>= 1, x = x * x % mod)
    if (t & 1) res = res * x % mod;
  return res;
}
int upd(int x) { return x + (x >> 31 & mod); }
int n, m, x, y, cx, cy, gx, gy, p, dx, dy;
void solve() {
  n = read<int>(), m = read<int>(), cx = read<int>(), cy = read<int>(),
  gx = read<int>(), gy = read<int>(),
  p = 1ll * read<int>() * qp(100, mod - 2) % mod;
  dx = dy = 1;
  int lst = 0;
  x = cx, y = cy;
  vec pot;
  auto getdir = [&](int x, int y, int dx, int dy) {
    if (x + dx > n || x + dx <= 0) dx = -dx;
    if (y + dy > m || y + dy <= 0) dy = -dy;
    return pii{dx, dy};
  };
  int cnt = 0;
  do {
    if (x == gx || y == gy) pot.emplace_back(lst), lst = 0;
    if (x + dx > n || x + dx <= 0) dx = -dx;
    if (y + dy > m || y + dy <= 0) dy = -dy;
    x += dx;
    y += dy;
    lst++;
  } while (x != cx || y != cy || (++cnt < 4));
  pot.emplace_back(lst);
  int A = upd(1 - p), B = 1ll * pot.back() * A % mod;
  pot.pop_back();
  while (pot.size() > 1) {
    A = 1ll * A * upd(1 - p) % mod;
    B = upd(B + pot.back() - mod);
    B = 1ll * B * upd(1 - p) % mod;
    pot.pop_back();
  }
  B = upd(B + pot.back() - mod);
  A = 1ll * B * qp(upd(1 - A), mod - 2) % mod;
  printf("%d\n", A);
}
int main() {
  for (int T = read<int>(); T; T--) solve();
  return 0;
}
