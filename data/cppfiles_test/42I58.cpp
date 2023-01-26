#include <bits/stdc++.h>
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + (c - '0'), c = getchar();
  return f * x;
}
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
template <typename T>
bool umin(T& a, T t) {
  if (a > t) return a = t, 1;
  return 0;
}
template <typename T>
bool umax(T& a, T t) {
  if (a < t) return a = t, 1;
  return 0;
}
const int MAXN = 3011;
int rb[MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN], p[MAXN];
bool used[MAXN];
int main() {
  int n = read();
  for (int i = 1; i <= n; ++i) {
    int l = read(), r = read();
    p[r] = l, rb[i] = r;
  }
  int t = read();
  for (int i = 1; i <= t; ++i) used[rb[read()]] = 1;
  for (int r = 1; r <= 2 * n; ++r) {
    for (int l = r; l; --l) {
      f[l][r] = f[l][r - 1];
      if (p[r] >= l) f[l][r] += 1 + f[p[r] + 1][r];
      if (used[r] && p[r] >= l)
        g[l][r] = f[l][r - 1] + 1 + g[p[r] + 1][r];
      else
        g[l][r] = g[l][r - 1];
    }
  }
  printf("%d\n", g[1][2 * n]);
  return 0;
}
