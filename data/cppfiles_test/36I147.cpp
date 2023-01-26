#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  int f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
const double Pi = acos(-1.0);
const double eps = 1e-10;
const long long MOD = 998244353;
const int N = 2e5 + 5, M = 1e5 + 5;
int main() {
  int t = read();
  while (t--) {
    int n = read();
    if (n & 1) {
      for (int i = 1; i <= n / 2; i++) putchar('a');
      if (n == 1) goto NEXT;
      putchar('b'), putchar('c');
      for (int i = n / 2 + 3; i <= n; i++) putchar('a');
    } else {
      for (int i = 1; i <= n / 2; i++) putchar('a');
      putchar('b');
      for (int i = n / 2 + 2; i <= n; i++) putchar('a');
    }
  NEXT:
    putchar('\n');
  }
  return 0;
}
