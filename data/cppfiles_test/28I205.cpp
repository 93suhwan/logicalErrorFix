#include <bits/stdc++.h>
using namespace std;
const long long mod = 993315154;
long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 3) + (s << 1) + (ch ^ 48);
    ch = getchar();
  }
  return s * w;
}
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
signed main() {
  long long T = 0;
  cin >> T;
  while (T--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long t = min(a, b);
    c = c % 2;
    b = b % 2;
    if (b == 0 && c == 0) {
      if (a % 2 == 1) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if (b == 1 && c == 0) {
      if (abs((a - b * 2) % 2 == 0)) {
        printf("0\n");
      } else {
        printf("1\n");
      }
    } else if (b == 0 && c == 1) {
      if (abs((a - c * 3) % 3 == 0)) {
        printf("0\n");
      } else {
        printf("%lld\n", abs(a - c * 3) % 3);
      }
    } else if (b == 1 && c == 1) {
      if (a >= 1) {
        if (a % 2 == 1) {
          printf("0\n");
        } else {
          printf("1\n");
        }
      } else {
        printf("1\n");
      }
    }
  }
  return 0;
}
