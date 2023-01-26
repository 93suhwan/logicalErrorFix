#include <bits/stdc++.h>
const long long MAXN = 200005;
std::vector<long long> pos[MAXN];
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long t;
  std::cin >> t;
  while (t--) {
    long long n, k;
    std::cin >> n >> k;
    long long a[n];
    long long count = 0;
    std::set<long long> dist;
    for (long long i = 0; i < n; i++) {
      std::cin >> a[i];
      pos[a[i]].push_back(i);
      dist.insert(a[i]);
    }
    for (long long j : dist) {
      count += std::min(k, (long long)pos[j].size());
    }
    long long ans = count / k;
    ans *= k;
    ans--;
    std::vector<long long> out(n, 0);
    for (long long j : dist) {
      for (long long i = 0; i < pos[j].size() && i < k && ans >= 0; i++) {
        out[pos[j][i]] = (ans % k) + 1;
        ans--;
      }
      pos[j].clear();
    }
    for (long long j : out) std::cout << j << " ";
    std::cout << std::endl;
  }
  return 0;
}
