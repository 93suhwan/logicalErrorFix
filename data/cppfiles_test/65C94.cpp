#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
long long quickmod(long long x, long long y) {
  long long Ans = 1;
  while (y) {
    if (y & 1) Ans = (Ans * x) % mod;
    x = (x * x) % mod;
    y >>= 1;
  }
  return Ans;
}
long long a[200005];
long long d[200005];
long long p[200005];
char ch[200005];
long long op[200005];
signed main() {
  long long n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  scanf("%s", ch + 1);
  sort(a + 1, a + 1 + n);
  for (long long i = 1; i <= n; i++) {
    if (i == 1 || ch[i] != ch[i - 1]) {
      d[i]++;
    } else {
      d[1]++;
      op[i] = -i + 1;
    }
  }
  for (long long i = 1; i <= n; i++) d[i] += d[i - 1];
  for (long long i = 1; i <= n; i++) p[i] = a[d[i] + op[i]];
  long long num = 0;
  for (long long i = 1; i <= n; i++) {
    char col;
    if (ch[i] == 'L') {
      if (i % 2 == 1 || num > 0)
        col = 'L';
      else
        col = 'R';
    } else {
      if (i % 2 == 1 || num < 0)
        col = 'R';
      else
        col = 'L';
    }
    if (col == 'L')
      num -= p[i];
    else
      num += p[i];
    printf("%lld %c\n", p[i], col);
  }
  return 0;
}
