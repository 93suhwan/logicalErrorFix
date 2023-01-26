#include <bits/stdc++.h>
using namespace std;
const int N = 400005, mod = 1000000007;
int n, m, a[N], lst[N];
long long f[N], t[N], ans;
struct data {
  int a, b;
} dat[N];
int getint() {
  char ch;
  while (!isdigit(ch = getchar()))
    ;
  int x = ch - 48;
  while (isdigit(ch = getchar())) x = x * 10 + ch - 48;
  return x;
}
long long add(long long x, long long y) {
  if ((x += y) >= mod) x -= mod;
  return x;
}
void ins(int x, long long y) {
  for (int i = x; i; i -= i & -i) t[i] = add(t[i], y);
}
long long query(int x) {
  long long ret = 0;
  for (int i = x; i <= 2 * n; i += i & -i) ret = add(ret, t[i]);
  return ret;
}
void init() {
  for (int i = 1; i <= 2 * n; ++i)
    if (lst[i]) f[i] = add(query(lst[i]), 1), ins(lst[i], f[i]);
}
bool cmp(int x, int y) { return dat[x].b > dat[y].b; }
void solve() {
  int p = 0, x = 2 * n;
  for (int i = 1; i <= m; ++i) {
    for (int j = dat[a[i]].b; j <= x; ++j)
      if (lst[j]) ins(lst[j], mod - f[j]);
    x = dat[a[i]].b - 1;
    if (dat[a[i]].a < p) continue;
    ans = add(ans, query(p + 1) + 1);
    p = dat[a[i]].a;
  }
}
int main() {
  n = getint();
  for (int i = 1; i <= n; ++i)
    dat[i].a = getint(), dat[i].b = getint(), lst[dat[i].b] = dat[i].a;
  init();
  m = getint();
  for (int i = 1; i <= m; ++i) a[i] = getint();
  sort(a + 1, a + 1 + m, cmp);
  solve();
  printf("%lld\n", ans);
  return 0;
}
