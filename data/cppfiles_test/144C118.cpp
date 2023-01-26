#include <bits/stdc++.h>
using namespace std;
const int maxdouble = 0x7f;
const int mindouble = 0xfe;
const long long mod = 998244353;
double jz(int n) {
  double ans = 1;
  for (int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
    if (ch == -1) return 0;
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
inline long long check(long long x) {
  long long s = sqrt(x * 2) + (1e-12);
  if ((s * (s + 1) / 2) == x) return s;
  return -1;
}
long long int ksm(long long int a, long long int b) {
  long long int ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
inline long long mul(long long a, long long b, long long mod) {
  return (a * b - (long long)((long double)a / mod * b) * mod + mod) % mod;
}
int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int l = 0, a = n / m, b = (n + m - 1) / m, t2 = n % m, t1 = m - t2;
    while (k--) {
      int t = l;
      for (int i = 1; i <= t2; i++) {
        printf("%d", b);
        for (int j = 0; j < b; j++) {
          printf(" %d", (t + j) % n + 1);
        }
        cout << '\n';
        ;
        t = (t + b) % n;
      }
      for (int i = 1; i <= t1; i++) {
        printf("%d", a);
        for (int j = 0; j < a; j++) {
          printf(" %d", (t + j) % n + 1);
        }
        cout << '\n';
        ;
        t = (t + a) % n;
      }
      l = (l + b * t2) % n;
    }
    cout << '\n';
    ;
  }
  return 0;
}
