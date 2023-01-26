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
int nn, m, t[maxn], a[maxn], b[maxn];
int lowbit(int x) { return x & (-x); };
void add(int x) {
  while (x <= m + 3) t[x]++, x += lowbit(x);
}
int query(int x) {
  int as = 0;
  while (x) {
    as += t[x];
    x -= lowbit(x);
  }
  return as;
}
int main() {
  int _ = read();
  while (_--) {
    nn = read(), m = read();
    for (int i = (1); i <= (m); ++i) t[i] = 0, a[i] = read(), b[i] = a[i];
    for (int i = (1); i <= (m + 3); ++i) t[i] = 0;
    sort(b + 1, b + 1 + m);
    int pos = unique(b + 1, b + 1 + m) - (b + 1);
    for (int i = (1); i <= (m); ++i)
      a[i] = lower_bound(b + 1, b + 1 + pos, a[i]) - b;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      int x = a[i];
      x += 2;
      ans += query(x - 1);
      add(x);
    }
    printf("%d\n", ans);
    ;
  }
  return 0;
}
