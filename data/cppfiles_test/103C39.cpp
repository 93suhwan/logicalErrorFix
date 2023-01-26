#include <bits/stdc++.h>
bool check(int i, int j, int n, int m) {
  return i >= 0 && i < n && j >= 0 && j < m;
}
void DFS(int i, int j, std::vector<std::string>& table,
         std::vector<std::vector<int>>& cache) {
  int n = table.size(), m = table[0].size();
  std::stack<int> st;
  st.push(m * i + j);
  do {
    int i = st.top() / m, j = st.top() % m;
    char d = table[i][j];
    int i1 = i + (d == 'D') - (d == 'U'), j1 = j + (d == 'R') - (d == 'L');
    if (!check(i1, j1, n, m)) {
      cache[i][j] = 1;
      st.pop();
    } else if (!cache[i1][j1]) {
      std::vector<int> cycle = {m * i1 + j1};
      do {
        cycle.push_back(st.top());
        st.pop();
      } while (st.top() != m * i1 + j1);
      st.pop();
      int cnt = cycle.size();
      for (auto idx : cycle) {
        cache[idx / m][idx % m] = cnt;
      }
    } else if (cache[i1][j1] == -1) {
      cache[i][j] = 0;
      st.push(m * i1 + j1);
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
