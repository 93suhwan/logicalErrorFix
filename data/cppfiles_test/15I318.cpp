#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const double PI = acos(-1), EPS = 1e-8;
namespace fast_IO {
long long read() {
  long long num = 0;
  char c;
  bool tag = false;
  while ((c = getchar()) != '-' && c != '+' && (c < '0' || c > '9') && ~c)
    ;
  if (!~c) return EOF;
  if (c == '-')
    tag = true;
  else if (c == '+')
    tag = false;
  else
    num = c ^ 48;
  while ((c = getchar()) >= '0' && c <= '9')
    num = (num << 1) + (num << 3) + (c ^ 48);
  if (tag) return -num;
  return num;
}
}  // namespace fast_IO
vector<int> to[N];
long long C[N][N], a[N], dp[N][N];
int q[N];
bool vis[N];
void dfs(int x, int step) {
  int head = 0, tail = 0, sum = 1;
  vis[x] = true;
  q[head++] = x;
  while (head != tail) {
    if (--step == 0) {
      if (sum) a[++*a] = sum;
      return;
    }
    int tot = 0;
    while (sum--) {
      int x = q[tail++];
      for (auto k : to[x]) {
        if (vis[k]) continue;
        vis[k] = true;
        ++tot;
        q[head++] = k;
      }
    }
    sum = tot;
  }
}
int main() {
  C[0][0] = 1;
  for (int i = 1; i <= 100; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
  }
  int T = fast_IO::read();
  while (T--) {
    int n = fast_IO::read(), k = fast_IO::read();
    long long ans = 0;
    for (int i = 1; i <= n; ++i) to[i].clear();
    for (int i = 1; i < n; ++i) {
      int x = fast_IO::read(), y = fast_IO::read();
      to[x].push_back(y);
      to[y].push_back(x);
    }
    if (k > 2) {
      for (int i = 1; i <= n; ++i) {
        if (to[i].size() < k) continue;
        for (int j = 1; j <= n; ++j) {
          *a = 0;
          memset(vis, 0, sizeof(vis));
          vis[i] = true;
          for (auto k : to[i]) dfs(k, j);
          if (*a < k) continue;
          dp[0][0] = 1;
          for (int t = 1; t <= *a; ++t)
            for (int p = 1; p <= t && p <= k; ++p)
              dp[t][p] = (dp[t - 1][p] + dp[t - 1][p - 1] * a[t] % mod) % mod;
          (ans += dp[*a][k]) %= mod;
        }
      }
      printf("%lld\n", ans);
    } else
      printf("%lld\n", C[n][2]);
  }
  return 0;
}
