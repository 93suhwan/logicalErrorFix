#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 10;
const long long inf = 1e18;
template <typename _tp>
inline void read(_tp& x) {
  char ch = getchar(), sgn = 0;
  while (ch ^ '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') ch = getchar(), sgn = 1;
  for (x = 0; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (sgn) x = -x;
}
long long n, m;
long long s[maxn];
signed main() {
  read(n), read(m);
  long long ans = 0;
  while (m--) {
    long long u, v;
    read(u), read(v);
    if (u > v) swap(u, v);
    if (++s[u] == 1) ans++;
  }
  long long q;
  read(q);
  while (q--) {
    long long x, u, v;
    read(x);
    if (x == 1) {
      read(u), read(v);
      if (u > v) swap(u, v);
      if (++s[u] == 1) ans++;
    } else if (x == 2) {
      read(u), read(v);
      if (u > v) swap(u, v);
      if (--s[u] == 0) ans--;
    } else
      printf("%lld\n", n - ans);
  }
  return 0;
}
