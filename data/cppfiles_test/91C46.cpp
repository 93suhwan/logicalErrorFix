#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  int c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long t, n, ans, lst, a[100009], b1[100009], b2[100009], c[100009],
    d[100009];
void calc(long long x, long long y) {
  for (int i = y + 1; i <= x; i++)
    d[i] = (d[i - 1] + c[i] * i % 998244353) % 998244353,
    ans += c[i] * i % 998244353, ans %= 998244353;
}
void solve() {
  n = read();
  for (int i = 1; i <= n; i++) b1[i] = b2[i] = c[i] = d[i] = 0;
  for (int i = 1; i <= n; i++) a[i] = read();
  ans = 0;
  for (int i = 1; i <= n; i++) {
    lst = a[i];
    int j;
    b1[i] = b2[i] = a[i];
    for (j = i - 1; j >= 1; j--) {
      if (b2[j] > lst) {
        c[j] = (a[j] + lst - 1) / lst;
        b1[j] = a[j] / c[j];
        if (a[j] % c[j] == 0)
          b2[j] = b1[j];
        else
          b2[j] = b1[j] + 1;
        lst = b1[j], c[j]--;
      } else {
        ans += d[j], ans %= 998244353;
        break;
      }
    }
    calc(i, j);
  }
}
int main() {
  t = read();
  while (t--) solve(), printf("%lld\n", ans);
  return 0;
}
