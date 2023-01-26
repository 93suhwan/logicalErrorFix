#include <bits/stdc++.h>
using namespace std;
inline char gc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline long long read() {
  char c = getchar();
  long long su = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) su = su * 10 + c - '0';
  return su * f;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writesp(long long x) { write(x), putchar(' '); }
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
long long P[15][15], f[1 << 15], ans, n, a[15];
long long quickPower(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = res * x % 1000000007;
    x = x * x % 1000000007;
    y >>= 1;
  }
  return res;
}
long long work(long long x, long long y) {
  vector<long long> g;
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    if ((y >> (i - 1)) % 2) g.push_back(i);
  }
  for (long long i = 1; i <= n; i++)
    if ((x >> (i - 1)) % 2) {
      long long now = 1;
      for (auto u : g) {
        now = now * P[u][i] % 1000000007;
      }
      res = res * now % 1000000007;
    }
  return res;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++)
      P[i][j] = a[i] * quickPower(a[i] + a[j], 1000000007 - 2) % 1000000007;
  for (long long stat = 1; stat < (1 << n); stat++) {
    f[stat] = 1;
    for (long long S = (stat - 1) & stat; S; S = (S - 1) & stat) {
      f[stat] = (f[stat] - f[S] * work(stat ^ S, S) % 1000000007 + 1000000007) %
                1000000007;
      if (S == 0) break;
    }
    ans = (ans + __builtin_popcount(stat) * f[stat] % 1000000007 *
                     work(((1 << n) - 1) ^ stat, stat)) %
          1000000007;
  }
  writeln(ans);
}
