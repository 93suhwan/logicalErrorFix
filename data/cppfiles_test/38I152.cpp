#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<std::vector<int>> L(n, std::vector<int>(m)), U(L);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'X') {
        L[i][j] = n;
        U[i][j] = m;
        continue;
      }
      L[i][j] = j;
      U[i][j] = i;
      if (j > 0) {
        L[i][j] = std::min(L[i][j], L[i][j - 1]);
        U[i][j] = std::min(U[i][j], U[i][j - 1]);
      }
      if (i > 0) {
        L[i][j] = std::min(L[i][j], L[i - 1][j]);
        U[i][j] = std::min(U[i][j], U[i - 1][j]);
      }
    }
  }
  std::vector<int> max(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '.' && U[i][j] > 0) {
        max[j] = std::max(max[j], L[i][j]);
      }
    }
  }
  for (int j = 1; j < m; ++j) {
    max[j] = std::max(max[j - 1], max[j]);
  }
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    --l, --r;
    if (l >= max[r]) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  }
}
