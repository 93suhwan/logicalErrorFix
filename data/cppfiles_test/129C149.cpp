#include <bits/stdc++.h>
int main() {
  int tasks;
  std::cin >> tasks;
  for (int o = 0; o < tasks; ++o) {
    int n;
    std::cin >> n;
    int res = 0;
    std::vector<int> a(n);
    std::vector<int> b(n);
    std::vector<int> need_change;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      if (a[i] <= n && b[a[i] - 1] == 0) {
        b[a[i] - 1] = 1;
      } else {
        need_change.push_back(a[i]);
      }
    }
    std::vector<int> change_to;
    for (int i = 0; i < n; ++i) {
      if (b[i] == 0) {
        change_to.push_back(i + 1);
      }
    }
    std::sort(need_change.begin(), need_change.end());
    bool can_we = 1;
    for (int i = 0; i < need_change.size(); ++i) {
      int max_get_from_op = need_change[i] / 2;
      if (need_change[i] % 2 == 1) {
        max_get_from_op += 1;
      }
      if (change_to[i] >= max_get_from_op) {
        can_we = 0;
      }
    }
    if (can_we) {
      std::cout << need_change.size() << std::endl;
    } else {
      std::cout << -1 << std::endl;
    }
  }
}
