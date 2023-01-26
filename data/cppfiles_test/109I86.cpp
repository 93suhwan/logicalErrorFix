#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 100000;
long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
long long jc[N + 5], inv[N + 5];
inline long long C(long long x, long long y) {
  if (y > x) return 0;
  return jc[x] * inv[y] % mod * inv[x - y] % mod;
}
inline char readchar() {
  char C = getchar();
  while (C < 33 || C > 126) C = getchar();
  return C;
}
void init() {
  jc[0] = 1;
  for (int i = 1; i <= N; i++) jc[i] = jc[i - 1] * i % mod;
  inv[N] = ksm(jc[N], mod - 2);
  for (int i = N - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
int a, b, c, d;
int main() {
  init();
  int n;
  cin >> n;
  if (n == 1) {
    char x = readchar(), y = readchar();
    if (x == '?' && y == '?')
      a = 2;
    else if (x == y)
      a = 0;
    else
      a = 1;
    cout << a << endl;
    return 0;
  }
  long long tmp = 0, flag = 0;
  for (int i = 1; i <= n; i++) {
    char x = readchar();
    if (x == 'W')
      a++;
    else if (x == 'B')
      b++;
    char y = readchar();
    if (y == 'W')
      c++;
    else if (y == 'B')
      d++;
    if (x == '?' && y == '?')
      tmp++;
    else if (x == y)
      flag = 1;
  }
  long long res = 0;
  if (flag == 1)
    res = 0;
  else {
    tmp = max(tmp - 1, 0ll);
    res = ksm(2, tmp);
  }
  int w1 = n - a - b, w2 = n - c - d;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    if (a > i || b > n - i || c > n - i || d > i) continue;
    ans = (ans + C(w1, i - a) * C(w2, i - d) % mod) % mod;
  }
  cout << (ans - res + mod) % mod;
  return 0;
}
