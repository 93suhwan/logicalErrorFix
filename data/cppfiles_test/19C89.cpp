#include <bits/stdc++.h>
using namespace std;
long long read() {
  char c = getchar();
  long long s = 0;
  long long x = 1;
  while (c < '0' || c > '9') {
    if (c == '-') x = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * x;
}
const long long N = 2055;
long long n, T, a[10055], l, r, f[N], g[N], maxx;
bool check(long long mid) {
  for (long long i = 0; i <= mid; i++) f[i] = g[i] = 0;
  for (long long i = a[1]; i <= mid; i++) f[i] = 1;
  for (long long i = 2; i <= n; i++) {
    for (long long k = 0; k <= mid; k++) {
      if (f[k]) {
        if (k - a[i] >= 0) g[k - a[i]] = 1;
        if (k + a[i] <= mid) g[k + a[i]] = 1;
      }
    }
    for (long long k = 0; k <= mid; k++) {
      f[k] = g[k];
      g[k] = 0;
    }
  }
  for (long long i = 0; i <= mid; i++)
    if (f[i]) return 1;
  return 0;
}
void solve() {
  n = read();
  maxx = 2000;
  for (long long i = 1; i <= n; i++) a[i] = read();
  l = 0, r = 2022;
  long long jl = 2000;
  while (l <= r) {
    if (check(((l + r) >> 1))) {
      jl = ((l + r) >> 1), r = ((l + r) >> 1) - 1;
    } else {
      l = ((l + r) >> 1) + 1;
    }
  }
  cout << jl << endl;
}
signed main() {
  T = read();
  while (T--) {
    solve();
  }
  return 0;
}
