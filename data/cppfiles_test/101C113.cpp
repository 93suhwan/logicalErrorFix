#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tc;
  std::cin >> tc;
  while (tc--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n), fx, fy;
    for (auto &v : a) std::cin >> v;
    char op;
    for (int i = 0; i < n; ++i) {
      std::cin >> op;
      if (op == 'B')
        fx.push_back(a[i]);
      else
        fy.push_back(a[i]);
    }
    bool ok = true;
    std::sort(fx.begin(), fx.end());
    std::sort(fy.begin(), fy.end());
    for (int i = 0; i < int(fx.size()); ++i) {
      if (fx[i] < i + 1) ok = false;
    }
    for (int i = 0; i < int(fy.size()); ++i) {
      if (fy[i] > int(fx.size()) + i + 1) ok = false;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
