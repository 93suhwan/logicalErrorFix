#include <bits/stdc++.h>
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long t;
  std::cin >> t;
  while (t--) {
    long long n;
    std::cin >> n;
    std::pair<long long, long long> help[n];
    for (long long i = 0; i < n; i++) {
      std::cin >> help[i].first;
      help[i].second = i;
    }
    if (n < 3) {
      bool sorted = true;
      for (long long i = 0; i + 1 < n; i++) {
        if (help[i] > help[i + 1]) sorted = false;
      }
      std::cout << (sorted ? "YES" : "NO") << std::endl;
      continue;
    }
    std::set<long long> set;
    long long done = 0;
    for (long long i = 0; i < n; i++) {
      if (set.count(help[i].first)) done = 1;
      set.insert(help[i].first);
    }
    if (done) {
      std::cout << "YES" << std::endl;
      continue;
    }
    std::sort(help, help + n);
    long long cur = 1;
    for (long long i = 0; i < n; i++) {
      if (help[i].second > i) {
        cur ^= (help[i].second - i) % 2;
      }
    }
    std::cout << (cur ? "YES" : "NO") << std::endl;
  }
  return 0;
}
