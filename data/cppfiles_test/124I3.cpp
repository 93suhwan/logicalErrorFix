#include <bits/stdc++.h>
const int M = 2005;
const int MOD = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int T, n, ans, pre[M][M << 1], suf[M][M << 1];
char s[M], t[M];
void add(int &x, int y) { x = (x + y) % MOD; }
int Abs(int x) { return x > 0 ? x : -x; }
int match(char c, int x) { return c == '?' || c == x + '0'; }
void work() {
  n = read();
  scanf("%s%s", s + 1, t + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] != '?' && i % 2) s[i] = ((s[i] - '0') ^ 1) + '0';
    if (t[i] != '?' && i % 2) t[i] = ((t[i] - '0') ^ 1) + '0';
  }
  for (int i = 0; i <= n + 1; i++)
    for (int j = -n; j <= n; j++) pre[i][j + M] = suf[i][j + M] = 0;
  pre[0][0 + M] = suf[n + 1][0 + M] = 1;
  ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = -n; j <= n; j++)
      for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
          if (match(s[i], x) && match(t[i], y))
            add(pre[i][j + x - y + M], pre[i - 1][j + M]);
  for (int i = n; i >= 1; i--)
    for (int j = -n; j <= n; j++)
      for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
          if (match(s[i], x) && match(t[i], y))
            add(suf[i][j + x - y + M], suf[i + 1][j + M]);
  for (int i = 1; i <= n; i++)
    for (int j = -n; j <= n; j++)
      add(ans, pre[i][j + M] * suf[i + 1][-j + M] % MOD * Abs(j));
  printf("%lld\n", ans);
}
signed main() {
  T = read();
  while (T--) work();
}
