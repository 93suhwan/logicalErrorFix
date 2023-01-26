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
bool eq[100][100];
void solve() {
  memset(eq, 0, sizeof eq);
  string s;
  cin >> s;
  long long n = s.length();
  vector<long long> a(n);
  long long val = 1;
  a[0] = val;
  for (long long i = 0; i < n; i++) {
    long long cur = i;
    long long nx = (i + 1) % n;
    if (s[i] == 'E') {
      if (nx > cur)
        a[nx] = a[cur];
      else
        a[cur] = a[nx];
    } else {
      a[nx] = ++val;
    }
  }
  for (long long i = 0; i < n; i++) {
    long long cur = i;
    long long nx = (i + 1) % n;
    if (s[i] == 'N') {
      if (a[i] == a[nx]) {
        puts("NO");
        return;
      }
    } else {
      if (a[i] != a[nx]) {
        puts("NO");
        return;
      }
    }
  }
  puts("YES");
  return;
}
int32_t main() {
  long long t;
  read(t);
  while (t--) solve();
}
