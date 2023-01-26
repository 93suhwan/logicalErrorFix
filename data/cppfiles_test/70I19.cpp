#include <bits/stdc++.h>
template <typename _Tp>
void read(_Tp &x) {
  char ch(getchar());
  bool f(false);
  while (!isdigit(ch)) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (isdigit(ch)) x = x * 10 + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
template <typename _Tp>
inline _Tp abs(const _Tp &a) {
  return a >= 0 ? a : -a;
}
template <typename _Tp>
_Tp gcd(const _Tp &a, const _Tp &b) {
  return !b ? a : gcd(b, a % b);
}
const int N = 200005, P = 1000000007;
int a[N], b[N], L[N], last[N];
std::map<int, int> mp;
int Log2[N], f[N][20], g[N][20];
inline int ask(int l, int r) {
  int k = Log2[r - l + 1];
  return std::max(f[l][k], f[r - (1 << k) + 1][k]);
}
inline int ASK(int l, int r) {
  int k = Log2[r - l + 1];
  return gcd(g[l][k], g[r - (1 << k) + 1][k]);
}
int main() {
  for (int i = 2; i < N; ++i) Log2[i] = Log2[i >> 1] + 1;
  int n, q;
  read(n, q);
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) {
    int j = i;
    while (j < n && a[j + 1] == a[i]) ++j;
    for (int k = i; k <= j; ++k) L[k] = i;
    i = j;
  }
  for (int i = 1; i <= n; ++i) last[i] = mp[a[i]], mp[a[i]] = i;
  for (int i = n; i >= 1; --i) {
    f[i][0] = last[i];
    for (int j = 1; j < 20 && i + (1 << (j - 1)) <= n; ++j)
      f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
  }
  for (int i = 1; i < n; ++i) {
    int tmp = abs(a[i] - a[i + 1]);
    if (tmp > P - tmp) tmp = P - tmp;
    b[i] = tmp;
  }
  for (int i = n - 1; i >= 1; --i) {
    g[i][0] = b[i];
    for (int j = 1; j < 20 && i + (1 << (j - 1)) < n; ++j)
      g[i][j] = gcd(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
  }
  int l, r, d;
  while (q--) {
    read(l, r, d);
    if (d > P - d) d = P - d;
    if (d == 0) {
      puts(L[r] <= l ? "Yes" : "No");
      continue;
    } else {
      if (l == r)
        puts("Yes");
      else if (ask(l, r) >= l)
        puts("No");
      else {
        if (ASK(l, r - 1) == d)
          puts("Yes");
        else
          puts("No");
      }
    }
  }
  return 0;
}
