#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
const int mod = 998244353;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10ll + ch - '0', ch = getchar();
  return x * f;
}
int n, k, pw[N], a[N];
char s[N];
void up(int& x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int Pow(int x, int y) {
  if (!y) return 1;
  int t = Pow(x, y >> 1);
  t = (long long)t * t % mod;
  if (y & 1) t = (long long)t * x % mod;
  return t;
}
int fac[N], inv[N], fin[N];
void init() {
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = (long long)fac[i - 1] * i % mod;
  inv[0] = inv[1] = 1;
  for (int i = 2; i < N; i++)
    inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
  fin[0] = 1;
  for (int i = 1; i < N; i++) fin[i] = (long long)fin[i - 1] * inv[i] % mod;
}
int C(int n, int m) {
  if (n < m) return 0;
  return (long long)fac[n] * fin[m] % mod * fin[n - m] % mod;
}
int main() {
  n = read(), k = read();
  init();
  int l = 0;
  scanf("%s", s + 1);
  a[l++] = 0;
  for (int i = 1; i <= n; i++)
    if (s[i] == '1') a[l++] = i;
  a[l++] = n + 1;
  if (!k || k > l - 2) return puts("1"), 0;
  int ans = 0;
  for (int i = 0; i + 1 + k < l; i++) {
    up(ans, C(a[i + 1 + k] - a[i] - 1, k));
    if (i + 1 + k != l - 1)
      up(ans, mod - C(a[i + 1 + k] - a[i + 1] - 1, k - 1));
  }
  cout << ans;
}
