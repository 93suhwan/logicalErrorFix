#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c;
  for (c = getchar(); c < '0' || c > '9';
       f = ((c == '-') ? -1 : f), c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = getchar())
    ;
  return x * f;
}
template <typename T>
inline void write(T a) {
  if (a == 0) {
    putchar('0');
    return;
  }
  if (a < 0) putchar('-'), a = -a;
  char c1[120];
  int h = 0;
  while (a) c1[++h] = a % 10 + '0', a /= 10;
  for (int i = h; i >= 1; --i) putchar(c1[i]);
}
inline void write_() { return; }
template <typename T, typename... Args>
inline void write_(T a, Args... b) {
  write(a);
  putchar(' ');
  write_(b...);
}
inline void writeln() {
  putchar('\n');
  return;
}
template <typename T, typename... Args>
inline void writeln(T a, Args... b) {
  write(a);
  putchar(' ');
  writeln(b...);
}
long long gcd(long long a, long long b) { return a == 0 ? b : gcd(b % a, a); }
inline long long lcm(long long a, long long b) {
  return 1ll * a / gcd(a, b) * b;
}
inline long long Pow(long long n, long long a) {
  long long b = 1;
  while (a) {
    if (a & 1) b = 1ll * b * n % (int)(1e9 + 7);
    n = 1ll * n * n % (int)(1e9 + 7);
    a >>= 1;
  }
  return b;
}
signed main() {
  int t = read(), x, n;
  long long sum = 0;
  while (t--) {
    n = read();
    sum = 0;
    for (int i = 1; i <= n; ++i) x = read(), sum += x;
    if (sum % n == 0)
      writeln(0);
    else
      writeln(1);
  }
  return 0;
}
