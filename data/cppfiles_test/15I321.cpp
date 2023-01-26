#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
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
long long C[N][N];
int q[N];
bool vis[N];
long long getans(int st, int k) {
  int head = 0, tail = 0;
  q[head++] = st;
  int sum = 1;
  long long ans = 0;
  memset(vis, 0, sizeof(vis));
  vis[st] = true;
  while (head != tail) {
    if (sum >= k) (ans += C[sum][k]) %= mod;
    int cnt = 0;
    while (sum--) {
      int x = q[tail++];
      for (auto k : to[x]) {
        if (vis[k]) continue;
        ++cnt;
        vis[k] = true;
        q[head++] = k;
      }
    }
    sum = cnt;
  }
  return ans;
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
    for (int i = 1; i <= n; ++i) {
      (ans += getans(i, k)) %= mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
