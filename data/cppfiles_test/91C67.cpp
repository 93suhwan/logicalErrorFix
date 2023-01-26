#include <bits/stdc++.h>
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
vector<pair<long long, long long> > g[2];
int main() {
  cin >> t;
  while (t--) {
    n = read();
    long long ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read();
    g[n % 2].clear();
    g[n % 2].push_back({a[n], 1});
    for (int i = n; i > 1; i--) {
      int las = (i % 2), now = (las ^ 1);
      g[now].clear();
      int las1 = 0;
      for (auto tmp : g[las]) {
        ans += ((a[i - 1] - 1) / tmp.first) * (i - 1) % mod * tmp.second % mod;
        int tmp1 = a[i - 1] / ((a[i - 1] - 1) / tmp.first + 1);
        if (tmp1 == las1)
          g[now][g[now].size() - 1].second += tmp.second % mod;
        else
          g[now].push_back({tmp1, tmp.second}), las1 = tmp1;
      }
      if (a[i - 1] == las1)
        g[now][g[now].size() - 1].second++;
      else
        g[now].push_back({a[i - 1], 1ll});
      g[las] = g[now];
    }
    cout << ans % mod << endl;
  }
}
