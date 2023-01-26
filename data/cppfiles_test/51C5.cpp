#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  int ret = 0;
  char c = getchar(), last = ' ';
  while (!isdigit(c)) last = c, c = getchar();
  while (isdigit(c)) ret = (ret << 1) + (ret << 3) + c - '0', c = getchar();
  x = last == '-' ? -ret : ret;
}
void readll(long long &x) {
  long long ret = 0;
  char c = getchar(), last = ' ';
  while (!isdigit(c)) last = c, c = getchar();
  while (isdigit(c)) ret = (ret << 1) + (ret << 3) + c - '0', c = getchar();
  x = last == '-' ? -ret : ret;
}
int qpow(int x, int p, int mod) {
  int ret = 1;
  for (; p; x = 1ll * x * x % mod, p >>= 1)
    if (p & 1) ret = 1ll * ret * x % mod;
  return ret;
}
long long qpowl(long long x, long long p, long long mod) {
  long long ret = 1;
  for (; p; x = x * x % mod, p >>= 1)
    if (p & 1) ret = ret * x % mod;
  return ret;
}
long long qmul(long long a, long long b, int mod) {
  if (a < b) swap(a, b);
  long long ret = 0;
  for (; b; a = a * 2 % mod, b >>= 1)
    if (b & 1) ret = (ret + a) % mod;
  return ret;
}
long long qpowl_qmul(long long x, long long p, long long mod) {
  long long ret = 1;
  for (; p; x = qmul(x, x, mod), p >>= 1)
    if (p & 1) ret = qmul(ret, x, mod);
  return ret;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long gcdll(long long a, long long b) { return b ? gcdll(b, a % b) : a; }
int split_int(int x, int *s) {
  int cnt = 0;
  while (x) {
    s[++cnt] = x % 10;
    x /= 10;
  }
  return cnt;
}
int T;
long long n;
int main() {
  read(T);
  while (T--) {
    readll(n);
    long long res = 1;
    while (n % 2 == 0) res <<= 1, n >>= 1;
    cout << (n == 1 ? -1 : 1) * (res - (n + (n == 1)) / 2) << ' ' << res + n / 2
         << '\n';
  }
  return 0;
}
