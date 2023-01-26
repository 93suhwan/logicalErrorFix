#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
inline void Prin(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) Prin(x / 10);
  putchar(x % 10 + '0');
}
const int inf = 0x3f3f3f3f;
const long long mod = 1000000007;
const int qs = 5e5 + 7;
long long n, T, m;
long long qpow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
int main() {
  n = read();
  n = pow(2, n) - 1;
  long long ans = 6;
  ans = ans * qpow(4, n - 1) % mod;
  cout << ans << "\n";
  return 0;
}
