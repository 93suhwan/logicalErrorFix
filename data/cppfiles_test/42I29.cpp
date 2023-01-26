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
const int N = 200005, mod = 1000000007;
template <typename _Tp1, typename _Tp2>
inline void add(_Tp1 &a, _Tp2 b) {
  a = a + b >= mod ? a + b - mod : a + b;
}
template <typename _Tp1, typename _Tp2>
inline void sub(_Tp1 &a, _Tp2 b) {
  a = a - b < 0 ? a - b + mod : a - b;
}
int c[N], to[N], f[N], X[N], Y[N], TO[N];
void upd(int x, int C) {
  for (; x; x -= ((x) & (-(x)))) add(c[x], C);
}
int ask(int x) {
  int ans = 0;
  for (; x < N; x += ((x) & (-(x)))) add(ans, c[x]);
  return ans;
}
int main() {
  int n;
  read(n);
  for (int i = 1, x, y; i <= n; ++i)
    read(x, y), to[y] = x, TO[x] = y, X[i] = x, Y[i] = y;
  int k;
  read(k);
  int mx = 0, MX = 0;
  for (int i = 1, x; i <= k; ++i)
    read(x), mx = std::max(mx, X[x]), MX = std::max(MX, Y[x]);
  for (int i = 1; i <= n + n; ++i)
    if (to[i]) f[i] = (ask(to[i]) + 1) % mod, upd(to[i], f[i]);
  int ans = 0;
  for (int i = 1; i <= mx; ++i)
    if (TO[i] && TO[i] <= MX) add(ans, f[TO[i]]);
  printf("%d\n", ans);
  return 0;
}
