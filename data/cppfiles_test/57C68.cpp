#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const double eps = 1e-6;
const double PI = acos(-1);
const double R = 0.57721566490153286060651209;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
namespace FastIO {
char gc(void) {
  const int S = 1 << 17;
  static char buf[S], *s = buf, *t = buf;
  if (s == t) t = buf + fread(s = buf, 1, S, stdin);
  if (s == t) return EOF;
  return *s++;
}
int read(void) {
  int a = 0, b = 1, c = gc();
  for (; !isdigit(c); c = gc()) b ^= (c == '-');
  for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
  return b ? a : -a;
}
}  // namespace FastIO
using namespace FastIO;
long long quick_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans % mod;
}
namespace Comb {
const int N = 1e6 + 10;
long long F[N], invF[N], inv[N];
void init() {
  F[0] = F[1] = invF[0] = invF[1] = inv[0] = inv[1] = 1;
  for (int i = 2; i < N; i++) {
    F[i] = F[i - 1] * i % mod;
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    invF[i] = invF[i - 1] * inv[i] % mod;
  }
}
long long C(long long m, long long n) {
  if (m < 0 || n < 0 || n > m) return 0;
  long long ans = F[m];
  ans = ans * invF[n] % mod;
  ans = ans * invF[m - n] % mod;
  return ans;
}
long long Lucas(long long m, long long n) {
  return n ? Lucas(m / mod, n / mod) * C(m % mod, n % mod) % mod : 1;
}
}  // namespace Comb
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void solve() {
  int _;
  cin >> _;
  while (_--) {
    long long s, n, k;
    cin >> s >> n >> k;
    if (s == k)
      cout << "YES"
           << "\n";
    else {
      long long ans = s / (k * 2) * k;
      long long ys = s % (k * 2) + 1;
      ans += min(k, ys);
      cout << (n + 1 > ans ? "YES" : "NO") << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
