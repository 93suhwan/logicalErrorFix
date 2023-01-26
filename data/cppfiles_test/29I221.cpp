#include <bits/stdc++.h>
unsigned long long solution() {
  int n;
  std::cin >> n;
  unsigned long long zeros = 0;
  unsigned long long ones = 0;
  int tmp;
  for (int i = 0; i < n; ++i) {
    std::cin >> tmp;
    if (tmp == 0) {
      ++zeros;
    } else if (tmp == 1) {
      ++ones;
    }
  }
  return ones * (1 << zeros);
}
int main() {
  std::ios_base::sync_with_stdio(0);
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::cout << solution() << "\n";
  }
  return 0;
}
