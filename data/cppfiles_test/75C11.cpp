#include <bits/stdc++.h>
using namespace std;
namespace io {
inline long long read() {
  register char c = getchar();
  register long long x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x * f;
}
inline void write(long long x) {
  if (!x) {
    putchar('0');
    return;
  }
  register char s[50];
  register int t = 0;
  while (x) {
    s[++t] = x % 10 + '0';
    x /= 10;
  }
  while (t) putchar(s[t--]);
}
}  // namespace io
using namespace io;
const int maxn = 200005;
int n;
long long a[maxn];
int l[maxn], r[maxn];
bool sol(int x, int y, long long mx) {
  if (x == y) return 0;
  if (a[x] <= mx && a[y] <= mx) return 1;
  if (a[x] <= mx) return !(l[y] & 1);
  if (a[y] <= mx) return !(r[x] & 1);
  if (a[x] > a[y]) {
    if (r[x] & 1)
      return 0;
    else
      return !sol(x, y - 1, a[y]);
  } else {
    if (l[y] & 1)
      return 0;
    else
      return !sol(x + 1, y, a[x]);
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (i > 1 && a[i] < a[i - 1])
      l[i] = l[i - 1] + 1;
    else
      l[i] = 1;
  }
  r[n] = 1;
  for (int i = n - 1; i; i--) {
    if (a[i] < a[i + 1])
      r[i] = r[i + 1] + 1;
    else
      r[i] = 1;
  }
  if (sol(1, n, -1))
    printf("Bob");
  else
    printf("Alice");
  return 0;
}
