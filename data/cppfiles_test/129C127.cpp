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
const int qs = 1e5 + 7;
int T, n;
int a[qs], u[qs];
int b[qs];
int main() {
  T = read();
  while (T--) {
    n = read();
    int cnt = 0, flag = 1;
    for (int i = 1; i <= n; ++i) u[i] = 0;
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= 1 && a[i] <= n && !u[a[i]]) {
        u[a[i]] = 1;
      } else
        b[++cnt] = a[i];
    }
    sort(b + 1, b + 1 + cnt);
    int j = 1;
    for (int i = 1; i <= n; ++i) {
      if (!u[i]) {
        int p = (b[j] + 1) / 2;
        j++;
        if (i >= p) {
          flag = 0;
        }
      }
    }
    if (!flag)
      cout << "-1\n";
    else
      cout << cnt << "\n";
  }
  return 0;
}
