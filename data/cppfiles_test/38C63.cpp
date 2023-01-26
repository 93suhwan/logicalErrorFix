#include <bits/stdc++.h>
const long long mod = 998244353;
long long Add(long long x, long long y) {
  return (x + y >= mod) ? (x + y - mod) : (x + y);
}
long long Mul(long long x, long long y) { return x * y % mod; }
long long Mod(long long x) {
  return x < 0 ? (x + mod) : (x >= mod ? (x - mod) : x);
}
long long cadd(long long &x, long long y) {
  return x = (x + y >= mod) ? (x + y - mod) : (x + y);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T &read(T &r) {
  r = 0;
  bool w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') w = ch == '-' ? 1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') r = r * 10 + (ch ^ 48), ch = getchar();
  return r = w ? -r : r;
}
const int N = 1000100;
int n, m, v[N], all[N];
std::vector<char> ch[N];
std::vector<int> left[N], up[N];
void solve() {
  read(n);
  read(m);
  for (int i = 1; i <= m; ++i) v[i] = 0;
  for (int i = 0; i <= n + 1; ++i)
    ch[i].resize(m + 1), left[i].resize(m + 1), up[i].resize(m + 1);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      char qwq;
      std::cin >> qwq;
      ch[i][j] = qwq;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 2; j <= m; ++j)
      if (ch[i][j - 1] == 'X') left[i][j] = 1;
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (ch[i - 1][j] == 'X') up[i][j] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (left[i][j] && up[i][j]) v[j] = 1;
  for (int i = 1; i <= m; ++i) v[i] += v[i - 1];
  int q;
  read(q);
  for (int o = 1; o <= q; ++o) {
    int l, r;
    read(l);
    read(r);
    if (v[r] - v[l])
      puts("NO");
    else
      puts("YES");
  }
}
signed main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
