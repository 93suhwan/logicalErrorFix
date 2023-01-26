#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, f = 1;
  char _ch = getchar();
  while (!('0' <= _ch && _ch <= '9')) (_ch == '-') && (f = -1), _ch = getchar();
  while (('0' <= _ch && _ch <= '9')) s = s * 10 + _ch - 48, _ch = getchar();
  return s * f;
}
const long long N = 5e5 + 10, inf = 1e17;
long long n, d, ans;
struct node {
  long long s, a;
  bool operator<(const node& t) const {
    if (max(s, a) == max(t.s, t.a)) return s < t.s;
    return max(s, a) < max(t.s, t.a);
  }
} a[N];
signed main() {
  n = read();
  d = read();
  for (register long long i = 1; i <= n; i++) {
    a[i].s = read();
    a[i].a = read();
  }
  sort(a + 1, a + 1 + n);
  for (register long long i = 1; i <= n; i++)
    if (a[i].s >= d) {
      d = max(d, a[i].a);
      ans++;
    }
  cout << ans << '\n';
  return 0;
}
