#include <bits/stdc++.h>
const int64_t INF = 0x3f3f3f3f3f3f3f;
struct val_t {
  int64_t val, pos;
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int64_t T;
  std::cin >> T;
  int64_t colors = 2;
  for (int64_t tc = 1; tc <= T; tc++) {
    std::string str;
    std::cin >> str;
    int64_t n = str.length();
    std::vector<val_t> values(n);
    std::vector<int64_t> dict(26, 0);
    for (int64_t k = 0; k < n; k++) {
      int64_t val = str[k] - 'a';
      values[k].val = val;
      dict[values[k].val]++;
      values[k].pos = k;
    }
    std::sort(values.begin(), values.end(),
              [](const val_t& v1, const val_t& v2) { return v1.val < v2.val; });
    int64_t E = 0;
    for (int64_t i = 0; i < 26; i++) E += std::min(dict[i], colors);
    std::cout << E / colors << '\n';
  }
}
