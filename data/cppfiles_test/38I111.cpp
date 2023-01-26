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
long long Solve(long long need) {
  long long ans = 1ll * 1e18;
  for (int i = 0; i <= 20; i++) {
    for (int j = 0; j <= 20; j++) {
      for (int k = 0; k <= 20; k++) {
        long long total = i * 6 + j * 8 + k * 10;
        long long money = i * 15 + j * 20 + k * 25;
        if (total >= need) ans = min(ans, money);
      }
    }
  }
  return ans;
}
int main() {
  int test = 1, no = 0;
  fastScan(test);
  while (test--) {
    fastScan(n);
    printf("%lld\n", (n / 120) * 300 + Solve(n % 120));
  }
  return 0;
}
