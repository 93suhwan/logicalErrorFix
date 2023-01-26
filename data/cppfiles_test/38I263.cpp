#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int MX = 123456;
const int mod = (int)1e9 + 7;
const int base = 97;
const unsigned long long BS1 = 10000019ULL;
const int INF = (1 << 29);
template <class T>
inline void fastScan(T &x) {
  register char c = getchar();
  int neg = 0;
  x = 0;
  for (; (c < 48 || c > 57) && (c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
template <typename T>
inline T gcd(T a, T b) {
  T c;
  while (b) {
    c = b;
    b = a % b;
    a = c;
  }
  return a;
}
long long n;
long long Solve() {
  long long a = (n / 6) * 15;
  if (n % 6 != 0) a += 15;
  long long b = (n / 8) * 20;
  if ((n % 8) <= 6)
    b += 15;
  else
    b += 20;
  long long c = (n / 10) * 25;
  if ((n / 10) <= 6)
    c += 15;
  else if ((n / 10) <= 8)
    c += 20;
  else
    c += 25;
  return min(a, min(b, c));
}
int main() {
  int test = 1, no = 0;
  fastScan(test);
  while (test--) {
    fastScan(n);
    printf("%lld\n", Solve());
  }
  return 0;
}
