#include <bits/stdc++.h>
signed main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  long long t;
  std::cin >> t;
  for (long long j = 0; j < t; ++j) {
    long long n;
    long long count = 1;
    std::cin >> n;
    long long prev = 0;
    std::cin >> prev;
    if (prev) {
      count = 2;
    }
    long long i = 1;
    long long curr;
    for (; i < n; ++i) {
      std::cin >> curr;
      if (!prev && !curr) {
        count = -1;
        ++i;
        break;
      }
      if (curr && !prev) {
        ++count;
      } else if (curr && prev) {
        count += 5;
      }
      prev = curr;
    }
    for (; i < n; ++i) {
      std::cin >> curr;
    }
    std::cout << count << '\n';
  }
}
