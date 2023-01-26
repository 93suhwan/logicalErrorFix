#include <bits/stdc++.h>
using namespace std;
struct Mint;
const int MOD = 1e9 + 7;
int pwr(int a, int b) {
  int res = 1;
  for (; b; b >>= 1) {
    if (b & 1) res = 1LL * res * a % MOD;
    a = 1LL * a * a % MOD;
  }
  return res;
}
struct Mint {
  int a;
  Mint(int x) { a = x; }
  Mint() { a = 0; }
  Mint operator=(const Mint &x) {
    a = x.a;
    return *this;
  }
  Mint operator+(const Mint &x) {
    Mint res = *this;
    res += x;
    return res;
  }
  Mint operator-(const Mint &x) {
    Mint res = *this;
    res -= x;
    return res;
  }
  Mint operator*(const Mint &x) {
    Mint res = *this;
    res *= x;
    return res;
  }
  Mint operator/(const Mint &x) {
    Mint res = *this;
    res /= x;
    return res;
  }
  void operator+=(const Mint &x) {
    a = a + x.a;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
  }
  void operator-=(const Mint &x) {
    a = a - x.a;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
  }
  void operator*=(const Mint &x) { a = 1LL * a * x.a % MOD; }
  void operator/=(const Mint &x) { a = 1LL * a * pwr(x.a, MOD - 2) % MOD; }
};
const int MAXN = 1e5 + 10;
int T = 1, n, m, x, y, X, Y, p;
Mint P, NP;
bool mark[MAXN][2][2];
inline int getid(int x, int y) { return x * m + y; }
pair<int, pair<Mint, Mint> > solve(int x, int y, int r, int c) {
  if ((x == n - 1 && r == 0) || (x == 0 && r == 1)) r = 1 - r;
  if ((y == m - 1 && c == 0) || (y == 0 && c == 1)) c = 1 - c;
  if (mark[getid(x, y)][r][c]) return {0, {Mint(0), Mint(1)}};
  mark[getid(x, y)][r][c] = true;
  pair<int, pair<Mint, Mint> > tmp = solve(x + 1 - 2 * r, y + 1 - 2 * c, r, c);
  if (x == X || y == Y) {
    return {1 + tmp.first,
            {P + NP * (tmp.second.first + Mint(1)), NP * tmp.second.second}};
  }
  return {tmp.first + 1, {tmp.second.first + 1, tmp.second.second}};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    memset(mark, 0, sizeof mark);
    cin >> n >> m >> x >> y >> X >> Y >> p;
    x--, y--, X--, Y--;
    P = Mint(p);
    P /= Mint(100);
    NP = (Mint(1) - P);
    pair<int, pair<Mint, Mint> > res = solve(x, y, 0, 0);
    res.second.first -= (res.second.second * Mint(res.first));
    Mint ans = (Mint(res.first) * (res.second.second) + res.second.first) /
               (Mint(1) - res.second.second);
    cout << ans.a - 1 << '\n';
  }
}
