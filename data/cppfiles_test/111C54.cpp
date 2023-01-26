#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize(2)
using namespace std;
const int maxv = 1e6 + 10;
const int maxn = 3e5 + 10;
const int inf32 = 1e9 + 5;
const long long inf64 = 1e18 + 10;
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001;
struct mint {
  long long v;
  explicit operator long long() const { return v; }
  mint() { v = 0; }
  mint(int _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  mint(long long _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mint& a, const mint& b) { return a.v == b.v; }
  friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
  friend bool operator<(const mint& a, const mint& b) { return a.v < b.v; }
  mint& operator+=(const mint& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mint& operator-=(const mint& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mint& operator*=(const mint& m) {
    v = v * m.v % MOD;
    return *this;
  }
  mint& operator/=(const mint& m) { return (*this) *= inv(m); }
  friend mint pow(mint a, long long p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mint inv(const mint& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mint operator-() const { return mint(-v); }
  mint& operator++() { return *this += 1; }
  mint& operator--() { return *this -= 1; }
  mint operator++(int) {
    v++;
    if (v == MOD) v = 0;
    return mint(v);
  }
  mint operator--(int) {
    v--;
    if (v < 0) v = MOD - 1;
    return mint(v);
  }
  friend mint operator+(mint a, const mint& b) { return a += b; }
  friend mint operator-(mint a, const mint& b) { return a -= b; }
  friend mint operator*(mint a, const mint& b) { return a *= b; }
  friend mint operator/(mint a, const mint& b) { return a /= b; }
  friend ostream& operator<<(ostream& os, const mint& m) {
    os << m.v;
    return os;
  }
  friend istream& operator>>(istream& is, mint& m) {
    long long first;
    is >> first;
    m.v = first;
    return is;
  }
};
int b[2005], L[2005], R[2005], N, K;
int dp[2][2005][2005], sum[2][2005][2005], f[2005], invf[2005];
mint C(int n, int r) {
  if (n < 0 || r < 0 || n < r) return 0;
  return f[n] * invf[n - r] * invf[r];
}
int mul(int first, int second) {
  long long v = (long long)first * second % MOD;
  return v;
}
int add(int first, int second) {
  long long v = (long long)first + second;
  return v % MOD;
}
int qpow(long long first, long long n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = mul(ret, first);
    first = mul(first, first);
    n >>= 1;
  }
  return ret;
}
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline int read() {
  int ans = 0, f = 1;
  char c = nc();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = nc();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = nc();
  }
  return ans * f;
}
};  // namespace fastIO
using namespace fastIO;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  f[0] = 1;
  int i, j, k, T, ci, pi, ans = 0;
  for (i = 1; i <= 2000; ++i) f[i] = mul(f[i - 1], i);
  for (i = 0; i <= 2000; ++i) invf[i] = qpow(f[i], MOD - 2);
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) {
    cin >> b[i];
    L[i] = max(0, b[i] - K);
    R[i] = min(N, b[i] + K);
  }
  dp[0][0][0] = 1;
  sum[0][0][0] = 1;
  for (i = 1, ci = 1, pi = 0; i <= N; ++i, ci ^= 1, pi ^= 1) {
    for (T = 0; T <= i; ++T) {
      for (k = L[i]; k <= R[i] && k <= T; ++k) {
        dp[ci][k][T] = add(dp[ci][k][T], mul(dp[pi][k][T], T));
        if (T) dp[ci][k][T] = add(dp[ci][k][T], dp[pi][k][T - 1]);
        if (T && k)
          dp[ci][k][T] =
              add(dp[ci][k][T],
                  mul(sum[pi][min(k - 1, R[i - 1])][T - 1], invf[T - k]));
        sum[ci][k][T] = add(sum[ci][k][T], mul(dp[ci][k][T], f[T - k]));
        if (k) sum[ci][k][T] = add(sum[ci][k][T], sum[ci][k - 1][T]);
      }
    }
    for (T = 0; T <= i - 1; ++T) {
      for (k = L[i - 1]; k <= R[i - 1] && k <= T; ++k) {
        sum[pi][k][T] = dp[pi][k][T] = 0;
      }
    }
  }
  for (j = 0; j <= N; ++j) {
    for (k = L[N]; k <= R[N] && k <= j; ++k) {
      ans = add(ans, mul(dp[N & 1][k][j], mul(f[N - k], invf[N - j])));
    }
  }
  cout << ans << endl;
}
