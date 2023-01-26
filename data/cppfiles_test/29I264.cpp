#include <bits/stdc++.h>
unsigned long long solution() {
  int n;
  std::cin >> n;
  std::vector<int> tab(n);
  for (int k = 0; k < n; ++k) {
    std::cin >> tab[k];
  }
  int ones_blocks = 0;
  std::vector<int> length_of_zero_blocks;
  int i = 0;
  while (i < n) {
    if (tab[i] != 1)
      ++i;
    else {
      while (i < n && tab[i] == 1) {
        ++i;
      }
      ++ones_blocks;
    }
  }
  i = 0;
  while (i < n) {
    if (tab[i] != 0)
      ++i;
    else {
      int j = i;
      while (i < n && tab[i] == 0) {
        ++i;
      }
      length_of_zero_blocks.push_back(i - j);
    }
  }
  unsigned long long res = ones_blocks;
  if (length_of_zero_blocks.empty()) {
    return res;
  }
  for (int k = 0; k < length_of_zero_blocks.size(); ++k) {
    res *= static_cast<unsigned long long>(length_of_zero_blocks[k] + 1);
  }
  return res;
}
int main() {
  std::ios_base::sync_with_stdio(0);
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::cout << solution() << "\n";
  }
  return 0;
}
