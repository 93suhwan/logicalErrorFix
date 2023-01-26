#include <bits/stdc++.h>
std::vector<std::vector<int>> data;
bool check_player(int index) {
  std::vector<int> lost_to_player(data.size());
  for (int i = 0; i < data.size(); ++i) {
    for (int j = 0; j < 5; ++j) {
      if (data[index][j] < data[i][j]) {
        lost_to_player[i]++;
      }
    }
  }
  for (int i = 0; i < data.size(); ++i) {
    if (i == index) {
      continue;
    }
    if (lost_to_player[i] < 3) {
      return false;
    }
  }
  return true;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int test;
  std::cin >> test;
  while (test--) {
    int n;
    std::cin >> n;
    data.clear();
    for (int i = 0; i < n; ++i) {
      std::vector<int> places(5);
      for (int j = 0; j < 5; ++j) {
        std::cin >> places[j];
      }
      data.push_back(std::move(places));
    }
    int best_player = 0;
    for (int i = 1; i < n; ++i) {
      int wins = 0;
      for (int j = 0; j < 5; ++j) {
        if (data[i][j] < data[best_player][j]) {
          ++wins;
        }
      }
      if (wins >= 3) {
        best_player = i;
      }
    }
    if (check_player(best_player)) {
      std::cout << best_player + 1 << "\n";
    } else {
      std::cout << -1 << "\n";
    }
  }
  return 0;
}
