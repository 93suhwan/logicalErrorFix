#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
mt19937 mrand(10086);
int rnd(int x) { return mrand() % x; }
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
long long Inv(long long b) { return powmod(b, (long long)1000000007 - 2); }
namespace fast {
inline char nc() {
  static char buf[100000], *L = buf, *R = buf;
  return L == R && (R = (L = buf) + fread(buf, 1, 100000, stdin), L == R)
             ? EOF
             : *L++;
}
template <class orz>
inline void qread(orz &x) {
  x = 0;
  char ch = nc();
  bool f = 0;
  while (ch < '0' || ch > '9') (ch == '-') && (f = 1), ch = nc();
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = nc();
  f && (x = -x);
}
}  // namespace fast
using namespace fast;
template <class orz>
inline void read(orz &x) {
  x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') (ch == '-') && (f = 1), ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  f && (x = -x);
}
template <class orz>
inline void out(orz x) {
  (x < 0) && (putchar('-'), x = -x);
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1000005;
const int M = 205;
const double eps = 1e-9;
const double inf = 1e18;
long long dp[N * 3][3], A[N * 3], InvA[N * 3];
long long C(int n, int m) {
  return A[n] * InvA[m] % 1000000007 * InvA[n - m] % 1000000007;
}
int main() {
  int n, q, x;
  read(n);
  read(q);
  A[0] = 1;
  for (int i = 1; i <= n * 3; ++i) A[i] = A[i - 1] * i % 1000000007;
  InvA[3 * n] = Inv(A[3 * n]);
  for (int i = 3 * n - 1; i >= 0; --i)
    InvA[i] = InvA[i + 1] * (i + 1) % 1000000007;
  for (int i = 0; i <= 2; ++i) dp[0][i] = n;
  long long inv3 = Inv(3);
  for (int i = 1; i <= n * 3; ++i) {
    dp[i][0] =
        (C(n * 3, i + 1) - 2 * dp[i - 1][0] - dp[i - 1][1]) * inv3 % 1000000007;
    dp[i][1] = (dp[i][0] + dp[i - 1][0]) % 1000000007;
    dp[i][2] = (dp[i][1] + dp[i - 1][1]) % 1000000007;
  }
  while (q--) {
    read(x);
    long long ans = dp[x][0] + C(3 * n, x);
    ans = (ans + 1000000007) % 1000000007;
    out(ans);
    putchar('\n');
  }
  return 0;
}
