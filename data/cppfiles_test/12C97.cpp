#include <bits/stdc++.h>
template <class T>
void read(T &x) {
  x = 0;
  char f = 0, c = getc(stdin);
  while (c < '0' || c > '9') f ^= (c == '-'), c = getc(stdin);
  while (c >= '0' && c <= '9') x = x * 10 + (c & 15), c = getc(stdin);
  f && (x = -x);
}
int Max(int a, int b) { return a > b ? a : b; }
int Min(int a, int b) { return a < b ? a : b; }
int Abs(int a) { return a < 0 ? -a : a; }
long long sqr(int a) { return (long long)a * a; }
int qpow(int a, int b) {
  if (b < 0) return 0;
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * a * ans % 1000000007;
    a = 1ll * a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int T = 1;
int n, m, k;
int main() {
  read(T);
  while (T--) {
    read(n), read(m), read(k);
    int flg = 1;
    if (n % 2) {
      if (k < m / 2) puts("NO"), flg = 0;
      k -= m / 2;
      if (k & 1 && flg) puts("NO"), flg = 0;
      if (flg) puts("YES"), flg = 0;
    }
    if (flg && m & 1) {
      int tmp = n * m >> 1;
      tmp -= k;
      if (tmp < n / 2 && flg) puts("NO"), flg = 0;
      tmp -= n / 2;
      if (tmp & 1 && flg) puts("NO"), flg = 0;
      if (flg) puts("YES"), flg = 0;
    }
    if (k & 1 && flg) puts("NO"), flg = 0;
    if (!(k & 1) && flg) puts("YES"), flg = 0;
  }
}
