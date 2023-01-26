#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
namespace fast_IO {
long long read() {
  long long num = 0;
  char c;
  bool tag = false;
  while ((c = getchar()) != '-' && c != '+' && (c < '0' || c > '9') && ~c)
    ;
  if (!~c) return EOF;
  if (c == '-')
    tag = true;
  else if (c == '+')
    tag = false;
  else
    num = c ^ 48;
  while ((c = getchar()) >= '0' && c <= '9')
    num = (num << 1) + (num << 3) + (c ^ 48);
  if (tag) return -num;
  return num;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 ^ 48);
}
}  // namespace fast_IO
int a[N], ans[N];
int GCD(int a, int b) {
  if (!b) return a;
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
int main() {
  int T = fast_IO::read();
  while (T--) {
    int n = fast_IO::read();
    for (int i = 1; i <= n; ++i) a[i] = fast_IO::read();
    int gcd = 0;
    for (int j = 0; j < 30; ++j) {
      int cnt = 0;
      for (int i = 1; i <= n; ++i) cnt += (a[i] >> j) & 1;
      gcd = GCD(gcd, cnt);
    }
    if (gcd) {
      *ans = 0;
      for (int i = 1; i * i <= gcd; ++i)
        if (gcd % i == 0) {
          if (i * i == gcd)
            ans[++*ans] = i;
          else
            ans[++*ans] = i, ans[++*ans] = gcd / i;
        }
      sort(ans + 1, ans + *ans + 1);
      for (int i = 1; i <= *ans; ++i)
        printf("%d%c", ans[i], i == *ans ? '\n' : ' ');
    } else
      for (int i = 1; i <= n; ++i) printf("%d%c", i, i == n ? '\n' : ' ');
  }
  return 0;
}
