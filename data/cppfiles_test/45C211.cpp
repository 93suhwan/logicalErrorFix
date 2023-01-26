#include <bits/stdc++.h>
void solve_test() {
  int n;
  std::cin >> n;
  int count[2] = {0, 0};
  int dist[2] = {0, 0};
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    if (x & 1) {
      dist[0] += std::abs(i - 2 * (count[1]));
      dist[1] += std::abs(i - 2 * (count[1]) - 1);
    }
    count[x & 1] += 1;
  }
  if (std::abs(count[0] - count[1]) <= 1) {
    if (count[0] == count[1]) {
      std::cout << std::min(dist[0], dist[1]) << '\n';
    } else {
      std::cout << dist[count[1] < count[0]] << '\n';
    }
  } else {
    std::cout << "-1\n";
  }
}
int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    solve_test();
  }
  return 0;
}
