#include <bits/stdc++.h>
using num = long long;
const num inf = 1ll << 61;
int main() {
  num n, m;
  std::cin >> n >> m;
  num count = 0;
  std::vector<num> a(n, 0);
  const auto add = [&a, &count](num i, num j) {
    if (i > j) std::swap(i, j);
    if (a[i] == 0) count++;
    a[i]++;
  };
  const auto del = [&a, &count](num i, num j) {
    if (i > j) std::swap(i, j);
    a[i]--;
    if (a[i] == 0) count--;
  };
  while (m--) {
    num u, v;
    std::cin >> u >> v;
    add(u - 1, v - 1);
  }
  num q;
  std::cin >> q;
  while (q--) {
    num c;
    std::cin >> c;
    if (c == 1) {
      num u, v;
      std::cin >> u >> v;
      add(u - 1, v - 1);
    }
    if (c == 2) {
      num u, v;
      std::cin >> u >> v;
      del(u - 1, v - 1);
    }
    if (c == 3) {
      std::cout << n - count << '\n';
    }
  }
}
