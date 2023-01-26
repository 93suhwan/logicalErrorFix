#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
inline int qpow(int x, int n) {
  int ret = 1;
  for (; n; n >>= 1) {
    if (n & 1) ret = 1ll * ret * x % mod;
    x = 1ll * x * x % mod;
  }
  return ret;
}
inline int inv(int x) { return qpow(x, mod - 2); }
void solve(const int cas) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int least = ((n & 1) ? m / 2 : 0);
  int most = ((m & 1) ? (m - 1) * n / 2 : n * m / 2);
  if (k < least || k > most || (k - least) & 1) {
    puts("NO");
    return;
  }
  puts("YES");
}
int main() {
  int T = 1, cas = 1;
  scanf("%d", &T);
  for (; T--; ++cas) solve(cas);
  return 0;
}
