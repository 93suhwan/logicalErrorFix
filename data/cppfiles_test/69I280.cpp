#include <bits/stdc++.h>
std::vector<std::string> get_powers() {
  std::vector<std::string> ans;
  for (size_t i = 1; i < (1ll << 63); i *= 2) {
    ans.push_back(std::to_string(i));
  }
  return ans;
}
int main() {
  const auto powers = get_powers();
  size_t N = 0;
  std::cin >> N;
  for (size_t n = 0; n < N; ++n) {
    size_t num = 0;
    std::cin >> num;
    const std::string str = std::to_string(num);
    size_t ans = str.size() + 1;
    for (const auto& power : powers) {
      size_t cnt = 0;
      for (auto ch : str) {
        if (ch == power[cnt]) ++cnt;
      }
      const size_t cur_sum = power.size() + str.size() - 2 * cnt;
      ans = std::min(ans, cur_sum);
    }
    std::cout << ans << '\n';
  }
  return 0;
}
