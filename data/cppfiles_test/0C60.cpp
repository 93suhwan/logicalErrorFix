#include <bits/stdc++.h>
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long n, m;
  std::cin >> n >> m;
  std::pair<std::string, long long> s[n];
  for (long long i = 0; i < n; i++) {
    std::cin >> s[i].first;
    for (long long j = 1; j < m; j += 2) s[i].first[j] = 'Z' - s[i].first[j];
    s[i].second = i + 1;
  }
  std::sort(s, s + n);
  for (long long i = 0; i < n; i++) {
    std::cout << s[i].second << " ";
  }
  std::cout << std::endl;
  return 0;
}
