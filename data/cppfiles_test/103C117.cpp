#include <bits/stdc++.h>
bool check(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
void DFS(int i, int j, std::vector<std::string>& table,
         std::vector<std::vector<int>>& cache) {
  std::stack<std::pair<int, int>> st;
  st.emplace(i, j);
  do {
    auto [i, j] = st.top();
    char d = table[i][j];
    int i1 = i + (d == 'D') - (d == 'U'), j1 = j + (d == 'R') - (d == 'L');
    if (!check(i1, j1, table.size(), table[0].size())) {
      cache[i][j] = 1;
      st.pop();
    } else if (!cache[i1][j1]) {
      std::vector<std::pair<int, int>> cycle = {{i, j}};
      st.pop();
      do {
        auto [pi, pj] = st.top();
        st.pop();
        i = pi, j = pj;
        cycle.emplace_back(i, j);
      } while (i != i1 || j != j1);
      int cnt = cycle.size();
      for (auto [i, j] : cycle) {
        cache[i][j] = cnt;
      }
    } else if (cache[i1][j1] == -1) {
      cache[i][j] = 0;
      st.emplace(i1, j1);
    } else {
      cache[i][j] = cache[i1][j1] + 1;
      st.pop();
    }
  } while (!st.empty());
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> table(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> table[i];
    }
    std::vector<std::vector<int>> cache(n, std::vector<int>(m, -1));
    int mx = 1, imx = 0, jmx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (cache[i][j] == -1) {
          DFS(i, j, table, cache);
          if (cache[i][j] > mx) {
            mx = cache[i][j];
            imx = i;
            jmx = j;
          }
        }
      }
    }
    std::cout << imx + 1 << ' ' << jmx + 1 << ' ' << mx << '\n';
  }
  return 0;
}
