#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;
char buffer[maxn], *S, *T;
inline char Get_Char() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, maxn, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
inline int read() {
  char c;
  int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f) return -re;
  return re;
}
inline void read(int& x) {
  char c;
  int re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
inline void read(long long& x) {
  char c;
  long long re = 0, f = 0;
  for (c = Get_Char(); c < '0' or c > '9'; c = Get_Char())
    if (c == '-') f = 1;
  for (; c >= '0' and c <= '9';)
    re = (re << 1) + (re << 3) + (c - '0'), c = Get_Char();
  if (f)
    x = -re;
  else
    x = re;
}
string s, t;
const int mxn = 5e5 + 5;
long long a[mxn], n, m;
inline long long qp(long long x, long long y, long long md) {
  long long rt = 1;
  for (; y; y >>= 1, (x *= x) %= md)
    if (y & 1) (rt *= x) %= md;
  return rt;
}
inline long long Inv(long long x, long long md) { return qp(x, md - 2, md); }
struct ahash {
  long long val[mxn], inv[mxn];
  long long mod, mul;
  long long tt;
  inline void init() {
    memset(val, 0, sizeof(val));
    memset(inv, 0, sizeof(inv));
    val[0] = a[0];
    for (int i = 1; i < n; ++i) val[i] = (val[i - 1] * mul + a[i]) % mod;
    inv[0] = 1;
    inv[1] = mul;
    for (int i = 2; i <= n; ++i) inv[i] = inv[i - 1] * inv[1] % mod;
    tt = 0;
    for (int i = 0; i < m; ++i) tt = (tt * mul + t[i] - '0') % mod;
  }
  inline long long get(int l, int r) {
    if (l == 0) return val[r];
    return (val[r] - val[l - 1] * inv[r - l + 1] % mod + mod) % mod;
  }
  inline void debug() {}
  inline long long cmp(int l1, int r1, int l2, int r2) {
    if ((get(l1, r1) + get(l2, r2)) % mod == tt) return 1;
    return 0;
  }
};
long long modo[41] = {
    999999937, 999999929, 999999893, 999999883, 999999797, 999999761, 999999757,
    999999751, 999999739, 999999733, 999999677, 999999667, 999999613, 999999607,
    999999599, 999999587, 999999541, 999999527, 999999503, 999999491, 999999487,
    999999433, 999999391, 999999353, 999999337, 999999323, 999999229, 999999223,
    999999197, 999999193, 999999191, 999999181, 999999163, 999999151, 999999137,
    999999131, 999999113, 999999107, 998244853};
struct hashes {
  ahash x[20];
  inline void init() {
    for (int i = 0; i < 20; ++i) {
      x[i].mul = 10;
      x[i].mod = modo[i];
      x[i].init();
    }
  }
  inline int cmp(int l1, int r1, int l2, int r2) {
    for (int i = 0; i < 20; ++i)
      if (!x[i].cmp(l1, r1, l2, r2)) return 0;
    return 1;
  }
} E;
int z[mxn], lcp[mxn];
inline void Z(string ss) {
  int nn = ss.size();
  z[0] = nn;
  for (int i = 1, l = 0, r = 0; i < nn; ++i) {
    z[i] = i < r ? min(z[i - l], r - i) : 0;
    for (; i + z[i] < n and ss[i + z[i]] == ss[z[i]];) ++z[i];
    if (i + z[i] > r) l = i, r = i + z[i];
  }
}
inline void solve() {
  cin >> s >> t;
  n = s.size();
  m = t.size();
  for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
  E.init();
  string ss = t + '$' + s;
  Z(ss);
  for (int i = 0; i < n; ++i) lcp[i] = z[t.size() + i + 1];
  if (t.size() > 1) {
    for (int i = 0; i + 2 * m - 3 < n; ++i) {
      if (E.cmp(i, i + m - 2, i + m - 1, i + 2 * m - 3)) {
        cout << i + 1 << ' ' << i + m - 1 << '\n';
        cout << i + m << ' ' << i + 2 * m - 2 << '\n';
        exit(0);
      }
      if (i + 2 * m - 2 < n and E.cmp(i, i + m - 2, i + m - 1, i + 2 * m - 2)) {
        cout << i + 1 << ' ' << i + m - 1 << '\n';
        cout << i + m << ' ' << i + 2 * m - 1 << '\n';
        exit(0);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int ln = m - lcp[i];
    if (n >= 944 and i == 390 and s[0] != '1') {
      cout << "?? " << ln << ' ' << E.cmp(289, 389, 390, 944) << '\n';
    }
    if (i + m + ln - 2 < n and E.cmp(i, i + m - 1, i + m, i + m + ln - 2)) {
      cout << i + 1 << ' ' << i + m << '\n';
      cout << i + m + 1 << ' ' << i + m + ln - 1 << '\n';
      exit(0);
    }
    if (i + m + ln - 1 < n and E.cmp(i, i + m - 1, i + m, i + m + ln - 1)) {
      cout << i + 1 << ' ' << i + m << '\n';
      cout << i + m + 1 << ' ' << i + m + ln << '\n';
      exit(0);
    }
    if (i - ln + 1 >= 0 and E.cmp(i, i + m - 1, i - ln + 1, i - 1)) {
      cout << i - ln + 2 << ' ' << i << '\n';
      cout << i + 1 << ' ' << i + m << '\n';
    }
    if (i - ln >= 0 and E.cmp(i, i + m - 1, i - ln, i - 1)) {
      cout << i - ln + 1 << ' ' << i << '\n';
      cout << i + 1 << ' ' << i + m << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T;
  T = 1;
  for (; T--;) solve();
}
