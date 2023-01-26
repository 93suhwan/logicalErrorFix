#include <bits/stdc++.h>
using namespace std;
int fac[3000005], inv[3000005], f[3000005];
int read() {
  int A;
  bool K;
  char C;
  C = A = K = 0;
  while (C < '0' || C > '9') K |= C == '-', C = getchar();
  while (C > '/' && C < ':') A = (A << 3) + (A << 1) + (C ^ 48), C = getchar();
  return (K ? -A : A);
}
void write(int X) {
  if (X < 0) putchar('-'), X = -X;
  if (X > 9) write(X / 10);
  putchar(X % 10 | 48);
}
int ksm(int x, int y) {
  return (!y ? 1
             : 1LL * ksm(1LL * x * x % 1000000007, y >> 1) * (y & 1 ? x : 1) %
                   1000000007);
}
inline int C(int x, int y) {
  return (y >= x
              ? 0
              : 1LL * fac[x] * inv[x - y] % 1000000007 * inv[y] % 1000000007);
}
int main() {
  int n, q, i, x, invv;
  n = read(), q = read();
  fac[0] = 1;
  for (i = 1; i <= (3 * n + 3); i++) fac[i] = 1LL * fac[i - 1] * i % 1000000007;
  inv[3 * n + 3] = ksm(fac[3 * n + 3], 1000000007 - 2);
  for (i = 3 * n + 2; i >= (0); i--)
    inv[i] = 1LL * inv[i + 1] * (i + 1) % 1000000007;
  for (i = 1; i <= (n); i++)
    for (x = 1; x <= (2); x++) f[x] = (f[x] + C(3 * i, x)) % 1000000007;
  invv = ksm(3, 1000000007 - 2);
  for (x = 3; x <= (3 * n); x++)
    f[x] = ((1LL * C(3 * n + 3, x + 1) - C(2, x) - C(1, x) - C(0, x) -
             3ll * f[x - 1] - f[x - 2]) %
                1000000007 * invv % 1000000007 +
            1000000007) %
           1000000007;
  while (q--) write(f[read()]), putchar('\n');
  return 0;
}
