#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  int N = 1e6;
  std::vector<bool> p(N + 1, true);
  p[0] = p[1] = false;
  for (int i = 2; i * i <= N; ++i) {
    if (p[i]) {
      for (int j = 2 * i; j <= N; j += i) {
        p[j] = false;
      }
    }
  }
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int sum = std::accumulate(a.begin(), a.end(), 0);
    if (p[sum] == false) {
      std::cout << n << "\n";
      for (int i = 0; i < n; ++i) {
        std::cout << i + 1 << " ";
      }
      std::cout << "\n";
    } else {
      std::cout << n - 1 << "\n";
      for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) {
          for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            std::cout << j + 1 << " ";
          }
          std::cout << "\n";
          break;
        }
      }
    }
  }
  return 0;
}
