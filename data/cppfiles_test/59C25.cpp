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
int day[1005][5];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) cin >> day[i][j];
  }
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      if (i == j) continue;
      int both = 0;
      int ci = 0;
      int cb = 0;
      for (int p = 1; p <= n; p++) {
        if (day[p][i] == 1 && day[p][j] == 1)
          both++;
        else if (day[p][i] == 1)
          ci++;
        else if (day[p][j] == 1)
          cb++;
      }
      if (ci * 2 <= n && cb * 2 <= n && both + ci + cb == n) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
}
int main() {
  ;
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
