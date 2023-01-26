#include <bits/stdc++.h>
int solve(const std::vector<int>& colors) {
  std::vector<std::vector<int>> group_by_color(colors.size() + 1);
  for (auto i = 0; i < colors.size(); ++i) {
    group_by_color[colors[i]].push_back(i);
  }
  std::vector<std::vector<int>> min_count(colors.size(),
                                          std::vector<int>(colors.size() + 1));
  for (auto len = 2; len <= colors.size(); ++len) {
    for (auto from = 0; from <= colors.size() - len; ++from) {
      const auto to = from + len - 1;
      auto count = min_count[from][to] + 1;
      if (colors[from] == colors[to]) {
        if (from + 1 == to) {
          count = 0;
        }
        count = std::min(count, min_count[from + 1][to] + 1);
        const auto& indices = group_by_color[colors[from]];
        const auto end = std::lower_bound(indices.begin(), indices.end(), to);
        for (auto begin =
                 std::upper_bound(indices.begin(), indices.end(), from);
             begin != end; ++begin) {
          const auto mid = *begin;
          count = std::min(count,
                           min_count[from][mid + 1] + min_count[mid][to + 1]);
        }
      } else {
        const auto& from_indices = group_by_color[colors[from]];
        const auto from_end =
            std::lower_bound(from_indices.begin(), from_indices.end(), to);
        for (auto begin = std::upper_bound(from_indices.begin(),
                                           from_indices.end(), from);
             begin != from_end; ++begin) {
          const auto mid = *begin;
          count = std::min(count,
                           min_count[from][mid + 1] + min_count[mid][to + 1]);
        }
        const auto& to_indices = group_by_color[colors[to]];
        const auto to_end =
            std::lower_bound(to_indices.begin(), to_indices.end(), to);
        for (auto begin =
                 std::upper_bound(to_indices.begin(), to_indices.end(), from);
             begin != to_end; ++begin) {
          const auto mid = *begin;
          count = std::min(count,
                           min_count[from][mid + 1] + min_count[mid][to + 1]);
        }
      }
      min_count[from][to + 1] = count;
    }
  }
  return min_count[0][colors.size()];
}
int main() {
  int test_case;
  std::cin >> test_case;
  for (auto t = 0; t < test_case; ++t) {
    int n;
    std::cin >> n;
    std::vector<int> colors(n);
    for (auto& v : colors) {
      std::cin >> v;
    }
    const auto result = solve(colors);
    std::cout << result << '\n';
  }
}
