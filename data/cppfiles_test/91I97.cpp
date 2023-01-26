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
int t, n, a[100005];
map<int, int> g[100005];
int main() {
  cin >> t;
  while (t--) {
    n = read();
    long long ans = 0;
    for (int i = 1; i <= n; i++) a[i] = read(), g[i].clear();
    g[n][a[n]] = 1;
    for (int i = n; i > 1; i--) {
      for (auto tmp : g[i]) {
        ans += ((a[i - 1] - 1) / tmp.first) * (i - 1) * tmp.second;
        g[i - 1][a[i - 1] / ((a[i - 1] - 1) / tmp.first + 1)] += tmp.second;
      }
      g[i - 1][a[i - 1]]++;
    }
    cout << ans << endl;
  }
}
