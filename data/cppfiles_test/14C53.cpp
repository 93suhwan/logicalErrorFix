#include <bits/stdc++.h>
void Solve() {
  int n = 0, k = 0, x = 0;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x;
    a[i] = i + 1 - x;
  }
  std::vector<int> maxdepth(n);
  int ans = n;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= 0) {
      maxdepth[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (a[j] >= 0 && a[i] >= a[j] && a[i] < a[j] + i - j) {
          maxdepth[i] = std::max(maxdepth[i], maxdepth[j] + 1);
        }
      }
      if (maxdepth[i] >= k) {
        ans = std::min(ans, a[i]);
      }
    }
  }
  if (ans == n) {
    std::cout << "-1\n";
  } else {
    std::cout << ans << '\n';
  }
}
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    Solve();
  }
}
