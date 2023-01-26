#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmax(const _Tp &a,
                                                     const _Tp &b) {
  (a < b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void chmin(const _Tp &a,
                                                     const _Tp &b) {
  (a > b) && (a = b);
}
template <typename _Tp>
__inline__ __attribute__((always_inline)) void read(_Tp &x) {
  register char ch(getchar());
  bool f(false);
  while (ch < 48 || ch > 57) f |= ch == 45, ch = getchar();
  x = ch & 15, ch = getchar();
  while (ch >= 48 && ch <= 57)
    x = (((x << 2) + x) << 1) + (ch & 15), ch = getchar();
  if (f) x = -x;
}
template <typename _Tp, typename... Args>
__inline__ __attribute__((always_inline)) void read(_Tp &t, Args &...args) {
  read(t);
  read(args...);
}
void solve() {
  string s;
  cin >> s;
  long long ct = 0;
  for (auto i : s) {
    ct += (i == 'N');
  }
  if (ct == 1)
    puts("NO");
  else
    puts("YES");
}
int32_t main() {
  long long t;
  read(t);
  while (t--) solve();
}
