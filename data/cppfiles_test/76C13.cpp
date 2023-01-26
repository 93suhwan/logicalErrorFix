#include <bits/stdc++.h>
constexpr int Maxn = 53;
std::vector<int> e[Maxn];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    if (u <= 50 && v <= 50) {
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
  }
  n = std::min(n, 50);
  for (int i = 1; i <= n; ++i) std::sort(e[i].begin(), e[i].end());
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < i; ++j)
      for (int k = 1; k < j; ++k)
        for (int l = 1; l < k; ++l)
          for (int r = 1; r < l; ++r) {
            std::vector<int> vec = {i, j, k, l, r};
            int cnt = 0;
            for (int x : {0, 1, 2, 3, 4})
              for (int y = 0; y < x; ++y) {
                auto iter = std::lower_bound(e[vec[x]].begin(), e[vec[x]].end(),
                                             vec[y]);
                if (iter == e[vec[x]].end() || *iter != vec[y]) ++cnt;
              }
            if (cnt == 0 || cnt == 10) {
              printf("%d %d %d %d %d\n", i, j, k, l, r);
              return 0;
            }
          }
  puts("-1");
}
