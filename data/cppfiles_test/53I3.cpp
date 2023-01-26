#include <bits/stdc++.h>
int main(const int argc, const char** argv) {
  std::ios::sync_with_stdio(false);
  std::cout.tie(nullptr);
  std::cin.tie(nullptr);
  int num_tests;
  std::cin >> num_tests;
  while (num_tests--) {
    int n;
    char c;
    std::string s;
    std::cin >> n >> c >> s;
    bool is_all_odd = std::count(s.begin(), s.end(), c) != n;
    for (int i = 0; i < n; ++i) {
      if (s[i] != c) {
        if ((i + 1) % 2 == 0) {
          is_all_odd = false;
        }
      }
    }
    std::vector<int> answer;
    if (is_all_odd)
      answer.emplace_back(2);
    else {
      if (s.back() != c) answer.emplace_back(n - 1);
      if (std::count(s.begin(), s.end() - 1, c) != n - 1)
        answer.emplace_back(n);
    }
    std::cout << answer.size() << '\n';
    for (size_t i = 0; i < answer.size(); ++i) {
      std::cout << answer[i] << (i + 1 != answer.size() ? ' ' : '\n');
    }
  }
  return EXIT_SUCCESS;
}
