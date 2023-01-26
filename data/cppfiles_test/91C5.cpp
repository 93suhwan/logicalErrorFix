#include <bits/stdc++.h>
const int P = 998244353;
using i64 = long long;
int f[100005], g[100005];
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = n - 2; i >= 0; --i) {
    ++f[a[i + 1]];
    int l = 1, r = 0;
    for (; l <= a[i + 1]; l = r + 1) {
      r = a[i + 1] / (a[i + 1] / l);
      int pre = a[i + 1] / l;
      int tmp = (a[i] + pre - 1) / pre;
      ans = (ans + i64(f[pre]) * (tmp - 1) * (i + 1) % P) % P;
      g[a[i] / tmp] = (g[a[i] / tmp] + f[pre]) % P;
      f[pre] = 0;
    }
    l = 1;
    for (; l <= a[i]; l = r + 1) {
      r = a[i] / (a[i] / l);
      f[a[i] / l] = g[a[i] / l];
      g[a[i] / l] = 0;
    }
  }
  std::cout << ans << "\n";
  memset(f, 0, sizeof(f));
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
