#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 1e4, M = 1e3 + 1e2;
const long long Maxn = 0x3ffffff, Minm = -0x3ffffff;
const long long Mod = 1e9 + 7;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * w;
}
long long t;
long long n;
signed main() {
  t = read();
  while (t--) {
    n = read();
    long long ans = 1;
    for (long long i = 3; i <= 2 * n; i++) ans *= i, ans %= Mod;
    cout << ans << "\n";
  }
}
