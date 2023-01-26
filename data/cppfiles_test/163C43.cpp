#include <bits/stdc++.h>
const int N = 500001;
const int P = 1000000007;
char buf[1 << 25], *p1 = buf, *p2 = buf;
inline int read() {
  int x = 0, f = 1;
  char ch =
      (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
           ? EOF
           : *p1++);
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  }
  while (ch >= '0' && ch <= '9')
    x = x * 10 + ch - 48,
    ch =
        (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
             ? EOF
             : *p1++);
  return x * f;
}
inline int fastpow(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = 1ll * r * a % P;
    a = 1ll * a * a % P;
    b >>= 1;
  }
  return r;
}
int n, m, x, y, a, b, p;
int tm[N], k[N], c[N], tot;
void Solve() {
  n = read(), m = read(), x = read(), y = read(), a = read(), b = read();
  p = 1ll * read() * fastpow(100, P - 2) % P;
  int s = x, t = y, T = 0, dx = 1, dy = 1, inix, iniy;
  tot = 0;
  while (true) {
    int dist = 1e9;
    if (s == n && dx == 1) dx = -1;
    if (s == 1 && dx == -1) dx = 1;
    if (t == m && dy == 1) dy = -1;
    if (t == 1 && dy == -1) dy = 1;
    if (!T) inix = dx, iniy = dy;
    if (T && s == x && y == t && dx == inix && dy == iniy) break;
    if (s == a || t == b) tm[++tot] = T;
    if (dx == 1)
      dist = std::min(dist, n - s);
    else
      dist = std::min(dist, s - 1);
    if (dy == 1)
      dist = std::min(dist, m - t);
    else
      dist = std::min(dist, t - 1);
    if (dx * (a - s) > 0) dist = std::min(dist, abs(a - s));
    if (dy * (b - t) > 0) dist = std::min(dist, abs(b - t));
    if (dx * (x - s) > 0) dist = std::min(dist, abs(x - s));
    if (dy * (y - t) > 0) dist = std::min(dist, abs(y - t));
    s += dx * dist, t += dy * dist;
    T = (T + dist) % P;
  }
  k[tot] = 1, c[tot] = 0;
  for (int i = tot - 1; i >= 1; i--) {
    k[i] = k[i + 1], c[i] = c[i + 1];
    c[i] = (c[i] + (tm[i + 1] - tm[i]) % P) % P;
    k[i] = 1ll * k[i] * (1 - p + P) % P;
    c[i] = 1ll * c[i] * (1 - p + P) % P;
  }
  int x = (((T + tm[1]) % P - tm[tot] + P) % P + c[1]) % P;
  int y = (fastpow(1 - p + P, P - 2) - k[1] + P) % P;
  x = 1ll * x * fastpow(y, P - 2) % P;
  x = (1ll * x * k[1] + c[1]) % P;
  std::printf("%d\n", (x + tm[1]) % P);
  return;
}
int main() {
  int t = read();
  while (t--) Solve();
  return 0;
}
