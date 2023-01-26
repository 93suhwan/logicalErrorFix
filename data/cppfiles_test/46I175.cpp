#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
const int maxn = 2e5 + 7;
const long long mod = 1e9 + 7;
inline long long read() {
  long long x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || '9' < ch) f |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
void out(long long x) {
  int stackk[20];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int top = 0;
  while (x) stackk[++top] = x % 10, x /= 10;
  while (top) putchar(stackk[top--] + '0');
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long n, a[maxn];
int main() {
  n = read();
  for (int i = (1); i <= (n); ++i) a[i] = read();
  long long ans = 0;
  for (int i = 2; i <= n; i += 2) {
    long long r = 0;
    for (int j = i - 1; j >= 1; j -= 2) {
      if (j + 1 == i) {
        if (a[j] > a[j + 1]) {
          ans += a[j + 1];
          break;
        } else {
          ans += a[j];
          r += a[j + 1] - a[j];
        }
        continue;
      }
      if (r + a[j + 1] < a[j]) {
        ans += a[j + 1] + r;
        break;
      }
      ans += a[j];
      r += a[j + 1] - a[j];
    }
  }
  out(ans);
  return 0;
}
