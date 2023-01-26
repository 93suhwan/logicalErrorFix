#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long Inf = 1ll << 60ll;
namespace io {
char buf[(1 << 23)], *p1 = buf, *p2 = buf, c;
int f;
template <typename T>
T read() {
  T x = 0;
  f = 0;
  c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (!isdigit(c))
    (c == '-') && (f = 1),
        c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin),
                          p1 == p2)
                 ? EOF
                 : *p1++);
  while (isdigit(c))
    x = x * 10 + (c & 15),
    c = (p1 == p2 &&
                 (p2 = (p1 = buf) + fread(buf, 1, (1 << 23), stdin), p1 == p2)
             ? EOF
             : *p1++);
  return f ? -x : x;
}
}  // namespace io
const int N = 200005;
const long long mod = 1000000007;
const long long inv2 = 500000004;
const int pw[4] = {0, 2, 11, 41};
const int lim = 42;
const int T = 3;
long long qpow(long long b, long long p) {
  long long res = 1;
  for (; p; p >>= 1ll, b = b * b % mod)
    if (p & 1) res = res * b % mod;
  return res;
}
void reduce(int& x) { (x >= mod) && (x -= mod); }
int n, q, a[N], sum[N], H[4][N], pre[lim + 1][N], C[lim + 1][lim + 1];
int main() {
  n = io::read<int>();
  q = io::read<int>();
  for (int i = 1; i <= n; ++i) {
    a[i] = io::read<int>();
    reduce(sum[i] = sum[i - 1] + a[i]);
    for (int j = 1; j <= T; ++j)
      reduce(H[j][i] = H[j][i - 1] + qpow(a[i], pw[j]));
  }
  for (int i = 0; i <= lim; ++i) {
    pre[i][0] = qpow(0, i);
    for (int j = 1; j <= n; ++j) reduce(pre[i][j] = pre[i][j - 1] + qpow(j, i));
  }
  for (int i = 0; i <= lim; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      reduce(C[i][j] = C[i - 1][j] + C[i - 1][j - 1]);
  }
  while (q--) {
    int l = io::read<int>(), r = io::read<int>(), d = io::read<int>();
    int x = r - l + 1;
    int A = ((sum[r] + mod - sum[l - 1]) % mod + mod -
             1ll * x * (x - 1) % mod * inv2 % mod * d % mod) %
            mod * qpow(x, mod - 2) % mod;
    int ok = 1;
    for (int i = 1; i <= T; ++i) {
      int power = pw[i];
      int pow_a = 1, pow_d = qpow(d, power);
      int res = 0;
      int inv_d = qpow(d, mod - 2);
      for (int j = 0; j <= power; ++j) {
        int tmp = 1ll * C[power][j] * pow_a % mod * pow_d % mod;
        reduce(res += 1ll * tmp * pre[power - j][x - 1] % mod);
        pow_a = 1ll * pow_a * A % mod;
        pow_d = 1ll * pow_d * inv_d % mod;
      }
      if ((H[i][r] - H[i][l - 1] + mod) % mod != res) {
        ok = 0;
        break;
      }
    }
    puts(ok ? "Yes" : "No");
  }
  return 0;
}
