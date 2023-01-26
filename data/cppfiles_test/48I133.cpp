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
    if (n < 6) {
      std::map<std::vector<long long>, long long> mp;
      std::vector<long long> id;
      std::queue<std::vector<long long> > bfs;
      for (long long i = 0; i < n; i++) {
        id.push_back(i);
      }
      bfs.push(id);
      bool poss = 0;
      while (!bfs.empty()) {
        std::vector<long long> cur = bfs.front();
        bfs.pop();
        bool sorted = true;
        for (long long i = 0; i + 1 < n; i++)
          if (help[cur[i]].first > help[cur[i + 1]].first) sorted = false;
        poss |= sorted;
        for (long long i = 0; i < n; i++) {
          for (long long j = 0; j < n; j++) {
            if (j == i) continue;
            for (long long k = 0; k < n; k++) {
              if (j == k || i == k) continue;
              std::vector<long long> next = cur;
              next[i] ^= next[j] ^= next[i] ^= next[j];
              next[j] ^= next[k] ^= next[j] ^= next[k];
              if (mp[next]) continue;
              mp[next] = 1;
              bfs.push(next);
            }
          }
        }
      }
      std::cout << (poss ? "YES" : "NO") << std::endl;
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
