#include <bits/stdc++.h>
int main() {
  int n;
  unsigned long long sum = 0;
  std::cin >> n;
  std::vector<unsigned long long> a(n + 1);
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  for (int i = 1; i <= n; i++) sum += a[i];
  int m;
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    unsigned long long u, v;
    std::cin >> u >> v;
    auto it = std::lower_bound(a.begin(), a.end(), u);
    int who;
    unsigned long long ans = 0;
    if (it != a.end()) {
      who = std::lower_bound(a.begin(), a.end(), u) - a.begin();
      if (sum - a[who] >= v)
        ans = 0;
      else
        ans = v - (sum - a[who]);
      if (who > 1) {
        if (sum - a[who - 1] >= v)
          ans = std::max(ans, u - a[who - 1]);
        else
          ans = std::max(ans, u - a[who - 1] + v - (sum - a[who - 1]));
      }
    } else {
      who = n;
      ans = u - a[who];
      if (v > sum - a[who]) ans += v - (sum - a[who]);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
