#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = ' ';
  while (!isdigit(ch)) {
    ch = getchar();
    if (ch == '-') f = -1;
  }
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch - 48), ch = getchar();
  return x * f;
}
const int mod = 998244353;
int t, n, a[100005];
map<int, int> g[2];
int main() {
  cin >> t;
  while (t--) {
    n = read();
    long long ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    g[n % 2].clear();
    g[n % 2][a[n]] = 1;
    for (int i = n; i > 1; i--) {
      int las = (i % 2), now = (las ^ 1);
      g[now].clear();
      for (auto tmp : g[las]) {
        ans += ((a[i - 1] - 1) / tmp.first) * (i - 1) % mod * tmp.second % mod;
        g[now][a[i - 1] / ((a[i - 1] - 1) / tmp.first + 1)] += tmp.second;
        g[now][a[i - 1] / ((a[i - 1] - 1) / tmp.first + 1)] %= mod;
      }
      g[now][a[i - 1]]++;
      g[las] = g[now];
    }
    printf("%d\n", ans % mod);
  }
}
