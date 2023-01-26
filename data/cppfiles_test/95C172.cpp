#include <bits/stdc++.h>
using namespace std;
long long pow2(long long i) { return 1LL << i; }
long long topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
long long topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
long long lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
long long lowbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a); }
long long allbit(long long n) { return (1LL << n) - 1; }
long long popcount(signed t) { return __builtin_popcount(t); }
long long popcount(long long t) { return __builtin_popcountll(t); }
bool ispow2(long long i) { return i && (i & -i) == i; }
template <class T>
T POW(T x, long long n) {
  T res = 1;
  for (; n; n >>= 1, x *= x)
    if (n & 1) res *= x;
  return res;
}
inline long long max(long long x, long long y) { return (x < y) ? y : x; }
inline long long min(long long x, long long y) { return (x < y) ? x : y; }
inline long long read() {
  register long long a = 0, po = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') po = -1, ch = getchar();
  while (isdigit(ch)) a = (a << 1) + (a << 3) + ch - 48, ch = getchar();
  return a * po;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  return;
}
long long gcd(long long x, long long y) {
  while (x % y) {
    long long temp = x % y;
    x = y, y = temp;
  }
  return y;
}
long long mgml(long long a, long long b, long long mod) {
  long long temp = 1;
  while (b) {
    if (b % 2) {
      temp = temp * a % mod;
    }
    a = a * a % mod;
    b /= 2;
  }
  return temp;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {
  long long ret, tmp;
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ret = exgcd(b, a % b, x, y);
  tmp = x;
  x = y;
  y = tmp - a / b * y;
  return ret;
}
long long lcm(long long x, long long y) { return (x * y) / gcd(x, y); }
long long fac[100009], inv[100009], MXNC = 100005;
long long mod = 1000000007;
void init() {
  inv[0] = inv[1] = fac[0] = 1;
  for (long long i = 2; i <= MXNC; i++)
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
  for (long long i = 2; i <= MXNC; i++)
    inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
  for (long long i = 1; i < MXNC; i++) fac[i] = fac[i - 1] * i % mod;
}
long long C(long long n, long long m) {
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
long long fenkuai(long long n) {
  long long ans = 0;
  for (long long l = 1, r; l <= n; l = r + 1) {
    r = n / (n / l);
    ans += (r - l + 1) * (n / l);
  }
  return ans;
}
long long fl[1200010];
vector<long long> prime;
void gep() {
  memset(fl, false, sizeof(fl));
  fl[1] = true;
  for (long long i = 2; i <= 1200000; i++) {
    long long t = 1200000 / i;
    for (long long j = 2; j <= t; j++) fl[i * j] = true;
  }
  for (long long i = 2; i <= 1200000; i++)
    if (!fl[i]) prime.push_back(i);
}
signed main() {
  long long t = read();
  while (t--) {
    long long n = read(), m = read();
    for (long long i = 1; i <= m; i++) {
      if (i == m)
        cout << n << "\n";
      else if (n > 1000000000 && n - 1000000000 >= m - i) {
        cout << 1000000000 << " ";
        n -= 1000000000;
      } else if (n > 100000000 && n - 100000000 >= m - i) {
        cout << 100000000 << " ";
        n -= 100000000;
      } else if (n > 10000000 && n - 10000000 >= m - i) {
        cout << 10000000 << " ";
        n -= 10000000;
      } else if (n > 1000000 && n - 1000000 >= m - i) {
        cout << 1000000 << " ";
        n -= 1000000;
      } else if (n > 100000 && n - 100000 >= m - i) {
        cout << 100000 << " ";
        n -= 100000;
      } else if (n > 10000 && n - 10000 >= m - i) {
        cout << 10000 << " ";
        n -= 10000;
      } else if (n > 1000 && n - 1000 >= m - i) {
        cout << 1000 << " ";
        n -= 1000;
      } else if (n > 100 && n - 100 >= m - i) {
        cout << 100 << " ";
        n -= 100;
      } else if (n > 10 && n - 10 >= m - i) {
        cout << 10 << " ";
        n -= 10;
      } else {
        cout << 1 << " ";
        n--;
      }
    }
  }
  return 0;
}
