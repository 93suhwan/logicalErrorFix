#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const ll mod = 1e9 + 7;
ll power(ll base, ll pow) {
  if (pow == 0) return 1;
  if (pow % 2 == 0) {
    ll powh = power(base, pow / 2);
    return (powh * powh) % mod;
  } else
    return (power(base, pow - 1) * base) % mod;
}
int n, m, rp, cp, rk, ck, r, c, dr, dc;
ll p, x, w, res;
stack<pii> s;
void solve(int subtask) {
  cin >> n >> m >> rp >> cp >> rk >> ck >> p;
  p = ((100LL - p) * power(100LL, mod - 2)) % mod;
  x = 1;
  w = 0;
  r = rp;
  c = cp;
  dr = dc = -1;
  for (int i = 0; i < 4 * (n - 1) * (m - 1); ++i) {
    if (!(1 <= r + dr and r + dr <= n)) dr = -dr;
    if (!(1 <= c + dc and c + dc <= m)) dc = -dc;
    r += dr;
    c += dc;
    w = (w + 1) % mod;
    if (r == rk || c == ck) {
      x = (x * p) % mod;
      w = (w * p) % mod;
    }
  }
  x = (1 + mod - x) % mod;
  res = (w * power(x, mod - 2)) % mod;
  cout << res << "\n";
}
int main() {
  boost();
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
