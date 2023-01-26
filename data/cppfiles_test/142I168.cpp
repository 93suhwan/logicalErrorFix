#include <bits/stdc++.h>
using namespace std;
struct Stat {
  uint32_t best;
  uint32_t bestidx;
};
uint32_t solve(size_t m, size_t n, vector<uint32_t>& data) {
  vector<Stat> stat;
  stat.resize(n);
  for (size_t i = 0; i < n; ++i) {
    auto& st = stat[i];
    for (size_t j = 0; j < m; ++j) {
      uint32_t v = data[n * j + i];
      if (v >= st.best) {
        st.bestidx = j;
        st.best = v;
      }
    }
  }
  vector<bool> used;
  used.resize(m);
  bool simple = false;
  uint32_t simple_score = ~0u;
  for (auto& st : stat) {
    simple = simple || used[st.bestidx];
    used[st.bestidx] = true;
    simple_score = std::min(simple_score, st.best);
  }
  if (simple) return simple_score;
  uint32_t bestscore = 0;
  for (size_t j = 0; j + 1 < n; ++j) {
    for (size_t i = j + 1; i < n; ++i) {
      uint32_t pair_score = 0;
      for (size_t k = 0; k < m; ++k) {
        pair_score =
            std::max(pair_score, std::min(data[n * k + j], data[n * k + i]));
      }
      bestscore = std::max(std::min(pair_score, simple_score), pair_score);
    }
  }
  return bestscore;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  size_t nn;
  cin >> nn;
  std::vector<uint32_t> data;
  for (size_t i = 0; i < nn; ++i) {
    size_t m, n;
    cin >> m >> n;
    data.resize(m * n);
    for (auto& x : data) {
      cin >> x;
    }
    cout << solve(m, n, data) << endl;
  }
  return 0;
}
