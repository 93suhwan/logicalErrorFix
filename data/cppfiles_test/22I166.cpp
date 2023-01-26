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
long long st[10], f[10][41];
int cnt[10], n, k;
void dfs(int dep, long long cur) {
  if (dep == k) {
    if (((cur + 1) & (-(cur + 1))) != cur + 1) puts("REJECTED"), exit(0);
    return;
  }
  int qwq = __builtin_popcountll(cur & st[dep]);
  cur &= ~st[dep];
  for (int i = qwq; i <= qwq + cnt[dep]; ++i) dfs(dep + 1, cur | f[dep][i]);
}
int main() {
  read(n, k);
  long long all = 0;
  for (int i = 0; i < k; ++i) {
    long long s = 0;
    int q;
    read(q);
    for (int j = 1, x; j <= q; ++j) read(x), s |= 1LL << (x - 1), f[i][j] = s;
    cnt[i] = __builtin_popcountll(s ^ (all & s)), all |= s, st[i] = s;
  }
  if (all + 1 != (1LL << n)) puts("REJECTED"), exit(0);
  dfs(0, 0);
  puts("ACCEPTED");
  return 0;
}
