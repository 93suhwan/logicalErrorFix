#include <bits/stdc++.h>
using namespace std;
const int N = 1002021, mod = 998244353;
int n, ans, x[N], y[N], f[N];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read();
  for (int op, i = 1; i <= n; i++) {
    x[i] = read(), y[i] = read();
    op = read();
    int lst = lower_bound(x + 1, x + i + 1, y[i]) - x;
    int w = (f[i - 1] - f[lst - 1] + x[i] - y[i]) % mod;
    f[i] = (f[i - 1] + w) % mod;
    if (op) (ans += w) %= mod;
  }
  cout << ((ans + x[n] + 1) % mod + mod) % mod << endl;
  return 0;
}
