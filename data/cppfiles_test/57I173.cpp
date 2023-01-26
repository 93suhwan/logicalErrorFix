#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
long long g(long long x) { return (x + 1) / 2; }
signed main() {
  long long T = read();
  while (T--) {
    long long s;
    s = read(), n = read(), k = read();
    swap(n, s);
    if (k == 1) {
      puts("YES");
      continue;
    }
    long long p = n / k, q = n % k;
    long long w = q * g(p + 1) + (k - q) * g(p);
    if (w >= s)
      puts("NO");
    else
      puts("YES");
  }
}
