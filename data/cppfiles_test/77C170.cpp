#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::cout;
bool MEMST;
const long long N = 5e6 + 5;
long long n, P, f[N], g[N], sum[N];
bool MEMED;
signed main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  cin >> n >> P;
  f[1] = 1;
  for (long long i = 1; i <= n; ++i) {
    g[i] = (g[i] + g[i - 1]) % P;
    f[i] = (f[i] + g[i] + sum[i - 1]) % P;
    for (long long j = 2; i * j <= n; ++j) {
      g[i * j] = (g[i * j] + f[i]) % P;
      if (1ll * i * j + j <= n) g[i * j + j] = (g[i * j + j] - f[i] + P) % P;
    }
    sum[i] = (sum[i - 1] + f[i]) % P;
  }
  cout << f[n] << '\n';
  cout.flush();
  return 0;
}
