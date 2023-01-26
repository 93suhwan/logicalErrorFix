#include <bits/stdc++.h>
constexpr int N = 105;
int T, n;
int a[N];
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) {
    std::cin >> n;
    int max = 0;
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
      max = std::max(max, (a[i] + 2) / 3);
    }
    bool f1 = true;
    bool f2 = true;
    bool exist1 = false;
    bool exist2 = false;
    bool has1 = false;
    bool t1 = true;
    bool t2 = true;
    for (int i = 1; i <= n; ++i) {
      if (a[i] % 3) f1 = false;
      if (a[i] == 3 * max) f2 = false;
      if (a[i] % 3 == 1) exist1 = true;
      if (a[i] % 3 == 2) exist2 = true;
      if (a[i] == 1) has1 = true;
      if (a[i] == 3 * max - 3) t1 = false;
      if (a[i] == 3 * max - 1) t2 = false;
    }
    if (f1)
      std::cout << max << '\n';
    else if (f2) {
      if (!exist1 || !exist2)
        std::cout << max << '\n';
      else {
        if (max == 1)
          std::cout << 2 << '\n';
        else if (t1 && t2 && !has1)
          std::cout << max << '\n';
        else
          std::cout << max + 1 << '\n';
      }
    } else
      std::cout << max + 1 << '\n';
  }
  return 0;
}
