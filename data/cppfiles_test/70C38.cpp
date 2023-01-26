#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, f = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar())
    sum = ((sum << 1) + (sum << 3) + (ch ^ 48));
  return f ? -sum : sum;
}
void write(const long long x) {
  if (x < 0) {
    putchar('-');
    write(-x);
    return;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
char getc() {
  char c = getchar();
  while (!isalpha(c)) c = getchar();
  return c;
}
long long n, m, a[1100000], mod = 1e9 + 7, r, x, y, z, inv6 = 166666668,
                            sum[1100000], ss[1100000];
long long _inc(long long a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
long long inv(long long a, long long k = mod - 2) {
  long long sum = 1;
  for (; k; k >>= 1, a = a * a % mod)
    if (k & 1) sum = sum * a % mod;
  return sum;
}
int main() {
  srand(time(0));
  r = 0;
  n = read(), m = read();
  for (register long long i = (1); i <= (n); i++)
    a[i] = read() + r, a[i] %= mod;
  for (register long long i = (1); i <= (n); i++)
    sum[i] = _inc(sum[i - 1], a[i]);
  for (register long long i = (1); i <= (n); i++)
    ss[i] = _inc(ss[i - 1], a[i] * a[i] % mod);
  for (register long long i = (1); i <= (m); i++) {
    x = read(), y = read(), z = read();
    long long s = y - x + 1, Sum = sum[y] - sum[x - 1],
              a0 = ((2 * Sum - s * (s + 1) % mod * z % mod) % mod + mod) % mod *
                   inv(2 * s) % mod;
    long long tmp =
        a0 * a0 % mod * s % mod + a0 * z % mod * s % mod * (s + 1) % mod +
        z * z % mod * s % mod * (s + 1) % mod * (2 * s + 1) % mod * inv6 % mod;
    tmp %= mod;
    if (tmp == (ss[y] - ss[x - 1] + mod) % mod)
      puts("Yes");
    else
      puts("No");
  }
}
