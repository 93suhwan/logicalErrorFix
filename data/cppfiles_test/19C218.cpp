#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch = getchar();
  long long f = 0;
  x = 0;
  while (!isdigit(ch)) {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
  if (f) x = -x;
}
const long long N = 2e5 + 5, M = 1e5;
long long n, a[N], tag;
void dfs(long long x, long long s, long long now) {
  if (s == a[now] || tag) {
    tag = 1;
    return;
  }
  if (x > n) return;
  dfs(x + 1, s, now);
  if (x == now) return;
  dfs(x + 1, s - a[x], now);
  dfs(x + 1, s + a[x], now);
}
signed main() {
  long long T;
  read(T);
  while (T--) {
    read(n);
    for (long long i = 1; i <= n; ++i) read(a[i]);
    tag = 0;
    for (long long i = 1; i <= n && tag == 0; ++i) {
      dfs(1, 0, i);
      if (a[i] == 0) tag = 1;
    }
    puts(tag ? "YES" : "NO");
  }
}
