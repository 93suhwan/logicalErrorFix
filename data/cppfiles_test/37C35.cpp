#include <bits/stdc++.h>
using ll = long long;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> freq(n + 1, 0);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      std::cin >> a >> b >> c;
      ++freq[b];
    }
    int node = -1;
    for (int i = 1; i <= n; ++i) {
      if (freq[i] == 0) {
        node = i;
        break;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (node != i) {
        std::cout << node << ' ' << i << '\n';
      }
    }
  }
}
