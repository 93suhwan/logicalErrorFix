#include <bits/stdc++.h>
using namespace std;
namespace IO {
inline long long read() {
  long long w = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    w = (w << 1) + (w << 3) + (ch ^ 48);
    ch = getchar();
  }
  return w * f;
}
}  // namespace IO
using namespace IO;
namespace CL {
const long long maxn = 1e5 + 5, mod = 998244353;
long long T, n, ans;
long long a[maxn], f[2][maxn];
bool vis[2][maxn];
vector<long long> vec[2];
inline void insert(long long cur, long long val) {
  if (vis[cur][val]) return;
  vis[cur][val] = 1, vec[cur].push_back(val);
}
inline void init() {
  for (long long i : vec[0]) f[0][i] = vis[0][i] = 0;
  for (long long i : vec[1]) f[1][i] = vis[1][i] = 0;
  vec[0].clear(), vec[1].clear();
  ans = 0;
}
inline long long main() {
  T = read();
  while (T--) {
    n = read();
    for (long long i = 1; i <= n; i++) a[i] = read();
    for (long long i = n, cur = n & 1; i >= 1; i--, cur ^= 1) {
      f[cur][a[i]] = 1;
      insert(cur, a[i]);
      for (long long j : vec[cur ^ 1]) {
        long long k = (long long)ceil((double)a[i] / (double)j);
        f[cur][a[i] / k] = (f[cur][a[i] / k] + f[cur ^ 1][j]) % mod;
        insert(cur, a[i] / k);
        ans = (ans + i * f[cur ^ 1][j] % mod * (k - 1) % mod) % mod;
        f[cur ^ 1][j] = vis[cur ^ 1][j] = 0;
      }
      vec[cur ^ 1].clear();
    }
    printf("%lld\n", ans);
    init();
  }
  return 0;
}
}  // namespace CL
signed main() { return CL::main(); }
