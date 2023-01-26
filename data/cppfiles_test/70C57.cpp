#include <bits/stdc++.h>
using namespace std;
const int n7 = 201234, k7 = 12;
const long long mo = 1000000007;
int n, T;
long long a[n7], b[n7], s[n7][k7], inv[n7], BlankAo[n7][k7], spow[n7][k7],
    C[k7][k7];
int rd() {
  int shu = 0;
  bool fu = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fu = 1;
    ch = getchar();
  }
  while (isdigit(ch)) shu = (shu << 1) + (shu << 3) + ch - '0', ch = getchar();
  return fu ? -shu : shu;
}
long long Dpow(long long p, long long q) {
  long long tot = 1;
  while (q) {
    if (q & 1) tot = tot * p % mo;
    p = p * p % mo, q = q >> 1;
  }
  return tot;
}
void ready() {
  for (int i = 1; i <= n; ++i) b[i] = 1;
  for (int j = 1; j <= 10; ++j)
    for (int i = 1; i <= n; ++i) {
      b[i] = b[i] * a[i] % mo;
      s[i][j] = (s[i - 1][j] + b[i]) % mo;
    }
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) inv[i] = mo - (mo / i) * inv[mo % i] % mo;
  for (int i = 0; i <= n; ++i) BlankAo[i][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 10; ++j) BlankAo[i][j] = BlankAo[i][j - 1] * i % mo;
  for (int j = 0; j <= 10; ++j) spow[0][j] = BlankAo[0][j];
  for (int j = 0; j <= 10; ++j)
    for (int i = 1; i <= n; ++i)
      spow[i][j] = (spow[i - 1][j] + BlankAo[i][j]) % mo;
  for (int i = 0; i <= 10; ++i) C[i][0] = 1;
  for (int i = 1; i <= 10; ++i)
    for (int j = 1; j <= i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mo;
    }
}
long long Dcalc(long long me, long long A, long long d, int r) {
  long long tot = 0;
  for (int i = 0; i <= me; ++i) {
    tot = (tot + C[me][i] * Dpow(A, me - i) % mo * Dpow(d, i) % mo *
                     spow[r][i] % mo) %
          mo;
  }
  return tot;
}
bool calc(long long A, long long d, int l, int r) {
  int me;
  me = 2;
  if (Dcalc(me, A, d, r - l) ^ ((s[r][me] - s[l - 1][me] + mo) % mo)) return 0;
  me = 3;
  if (Dcalc(me, A, d, r - l) ^ ((s[r][me] - s[l - 1][me] + mo) % mo)) return 0;
  me = 6;
  if (Dcalc(me, A, d, r - l) ^ ((s[r][me] - s[l - 1][me] + mo) % mo)) return 0;
  me = 7;
  if (Dcalc(me, A, d, r - l) ^ ((s[r][me] - s[l - 1][me] + mo) % mo)) return 0;
  me = 8;
  if (Dcalc(me, A, d, r - l) ^ ((s[r][me] - s[l - 1][me] + mo) % mo)) return 0;
  me = 9;
  if (Dcalc(me, A, d, r - l) ^ ((s[r][me] - s[l - 1][me] + mo) % mo)) return 0;
  return 1;
}
int main() {
  n = rd(), T = rd();
  for (int i = 1; i <= n; ++i) a[i] = rd();
  ready();
  while (T--) {
    long long l = rd(), r = rd(), d = rd();
    long long A = ((s[r][1] - s[l - 1][1] + mo) % mo -
                   (r - l + 1) * (r - l) % mo * d % mo * inv[2] % mo + mo) %
                  mo * inv[r - l + 1] % mo;
    puts(calc(A, d, l, r) ? "Yes" : "No");
  }
  return 0;
}
