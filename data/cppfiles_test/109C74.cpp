#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7, inf = 2e9 + 9, mod = 998244353;
long long pw(long long x, int k) {
  long long res = 1LL;
  while (k) {
    if (k & 1) {
      res *= x;
      res %= mod;
    }
    k >>= 1;
    x *= x;
    x %= mod;
  }
  return res;
}
long long c(int n, int k) {
  if (k < 0) return 0;
  long long res = 1;
  for (int i = n - k + 1; i < n + 1; ++i) {
    res *= i;
    res %= mod;
  }
  for (int i = 2; i < k + 1; ++i) {
    res *= pw(i, mod - 2);
    res %= mod;
  }
  return res;
}
char a[2];
bool is(char c[2]) { return a[0] == c[0] and a[1] == c[1]; }
void solve() {
  int n;
  scanf("%d", &n);
  int _b = 0, b_ = 0, _w = 0, w_ = 0, __ = 0, e = 0, tw = 0, tb = 0;
  bool same = false;
  for (int i = 0; i < n; ++i) {
    scanf("%s", &a);
    for (int i = 0; i < 2; ++i) {
      if (a[i] == 'B')
        tb++;
      else if (a[i] == 'W')
        tw++;
    }
    if (is("??")) __++;
    if (is("BB") or is("WW")) same = true;
    switch (a[0]) {
      case 'B':
        b_ = true;
        break;
      case 'W':
        w_ = true;
        break;
      case '?':
        e++;
        break;
    }
    switch (a[1]) {
      case 'B':
        _b = true;
        break;
      case 'W':
        _w = true;
        break;
      case '?':
        e++;
        break;
    }
  }
  int d = abs(tb - tw);
  long long res = c(e, (e - d) / 2);
  if (!same) {
    res -= pw(2, __);
    if (!_w and !b_) res++;
    if (!w_ and !_b) res++;
    res = (res + mod) % mod;
  }
  printf("%I64d", res);
}
int main() {
  solve();
  return 0;
}
