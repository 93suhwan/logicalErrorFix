#include <bits/stdc++.h>
const long long MAXN = 500005;
long long bit[MAXN];
void add(long long x, long long v) {
  x += 1;
  while (x < MAXN) {
    bit[x] += v;
    x += x & (-x);
  }
}
long long sum(long long x) {
  x += 1;
  long long ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= x & (-x);
  }
  return ret;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long t;
  std::cin >> t;
  while (t--) {
    long long n;
    std::cin >> n;
    for (long long i = 0; i <= n; i++) bit[i] = 0;
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
    long long cur = 0;
    for (long long i = n - 1; i >= 0; i--) {
      cur += sum(help[i].second);
      add(help[i].second, 1);
    }
    std::cout << (cur % 2 == 0 ? "YES" : "NO") << std::endl;
  }
  return 0;
}
