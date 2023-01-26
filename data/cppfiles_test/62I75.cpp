#include <bits/stdc++.h>
using namespace std;
const int DIR4[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int DIR8[8][2] = {{1, 0},   {-1, 0}, {0, 1},  {0, -1},
                        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
const int MOD197 = 1e9 + 7;
const int MOD19 = 1e9;
const int MOD353 = 998244353;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const long long LNINF = 0xc0c0c0c0c0c0c0c0;
inline int LT(int x) { return x << 1; }
inline int RT(int x) { return (x << 1) | 1; }
inline int LB(int x) { return x & -x; }
inline int MSK(int x) { return 1 << x; }
inline int HF(int x) { return x >> 1; }
inline int DB(int x) { return x << 1; }
inline int GT(int x, int i) { return (x >> i) & 1; }
inline int ST(int x, int i) { return x | (1 << i); }
inline int ODD(int x) { return x & 1; }
inline int SGN(int x) { return x >= 0 ? (x == 0 ? 0 : 1) : -1; }
template <int mod>
long long fpow(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = (a * a) % mod)
    if (b & 1) ans = (ans * a) % mod;
  return ans;
}
template <int mod>
struct MODINT {
  long long val;
  MODINT() : val(0) {}
  MODINT(long long v) : val(v % mod) {}
  MODINT operator+(const MODINT &o) const { return MODINT(val + o.val); }
  MODINT &operator+=(const MODINT &o) {
    val = (val + o.val) % mod;
    return *this;
  }
  MODINT operator*(const MODINT &o) const { return MODINT(val * o.val); }
  MODINT &operator*=(const MODINT &o) {
    val = (val * o.val) % mod;
    return *this;
  }
  MODINT operator-(const MODINT &o) const {
    return MODINT((val - o.val) % mod + mod);
  }
  MODINT &operator-=(const MODINT &o) {
    val = ((val - o.val) % mod + mod) % mod;
    return *this;
  }
  MODINT operator/(const MODINT &o) const {
    return MODINT(val * fpow<mod>(o.val, mod - 2));
  }
  MODINT &operator/=(const MODINT &o) {
    val = (val * fpow<mod>(o.val, mod - 2)) % mod;
    return *this;
  }
};
long long dp[1005][1005][2];
int flip[1005][1005];
int n, m;
long long solve1(int r, int c) {
  int ur = r, uc = c;
  int ut = 0;
  while (1) {
    if (uc - 1 > 0 && !flip[ur][uc - 1]) {
      ut++;
      uc--;
    } else
      break;
    if (ur - 1 > 0 && !flip[ur - 1][uc]) {
      ut++;
      ur--;
    } else
      break;
  }
  int br = r, bc = c;
  int bt = 0;
  while (1) {
    if (br + 1 <= n && !flip[br + 1][bc]) {
      bt++;
      br++;
    } else
      break;
    if (bc + 1 <= m && !flip[br][bc + 1]) {
      bt++;
      bc++;
    } else
      break;
  }
  return ut * bt + ut + bt;
}
long long solve2(int r, int c) {
  int ur = r, uc = c;
  int ut = 0;
  while (1) {
    if (ur - 1 > 0 && !flip[ur - 1][uc]) {
      ut++;
      ur--;
    } else
      break;
    if (uc - 1 > 0 && !flip[ur][uc - 1]) {
      ut++;
      uc--;
    } else
      break;
  }
  int br = r, bc = c;
  int bt = 0;
  while (1) {
    bool ok = false;
    if (bc + 1 <= m && !flip[br][bc + 1]) {
      bt++;
      bc++;
      ok = true;
    }
    if (!ok) break;
    if (br + 1 <= n && !flip[br + 1][bc]) {
      bt++;
      br++;
      ok = true;
    }
    if (!ok) break;
  }
  return ut * bt + ut + bt;
}
void solve() {
  int t;
  cin >> n >> m >> t;
  long long all = 0;
  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= m; c++) {
      dp[r][c][0] += dp[r][c - 1][1] + 1;
      dp[r][c][1] += dp[r - 1][c][0] + 1;
      all += dp[r][c][0] + dp[r][c][1] - 1;
    }
  }
  while (t--) {
    int x, y;
    cin >> x >> y;
    int tmp = flip[x][y];
    flip[x][y] = 0;
    long long a = solve1(x, y);
    long long b = solve2(x, y);
    flip[x][y] = 1 - tmp;
    if (flip[x][y]) {
      all -= a + b + 1;
    } else {
      all += a + b + 1;
    }
    cout << all << endl;
  }
}
int main() {
  ;
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
