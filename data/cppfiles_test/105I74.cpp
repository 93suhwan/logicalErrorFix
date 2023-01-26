#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...)
#define CHECK(...)
#endif

namespace {

const int INF = 0x3f3f3f3f;

struct Solver {
  int n;
  std::vector<int> as, bs, ms;
  std::vector<std::pair<int, int>> result;

  void solve(int ca, std::istream& reader) {
    reader >> n;
    std::map<int, std::vector<std::tuple<int, int, int>>> map;
    for (int i = 0; i < n; ++i) {
      int a, b, m;
      reader >> a >> b >> m;
      map[a + b - m].emplace_back(b, b - m, i);
      as.emplace_back(a);
      bs.emplace_back(b);
      ms.emplace_back(m);
    }
    int best = 0;
    result.resize(n);
    for (auto [key, vec] : map) {
      std::sort(vec.begin(), vec.end());  // [r, l, id]
      int last = -INF;
      for (const auto& [r, l, id] : vec) {
        if (last < l) {
          ++best;
          last = r;
        }
        result[id].second = bs[id] - last;
        result[id].first = ms[id] - result[id].second;
      }
    }
    printf("%d\n", best);
    for (int i = 0; i < n; ++i) {
      assert(0 <= result[i].first && result[i].first <= ms[i]);
      assert(0 <= result[i].second && result[i].second <= ms[i]);
      assert(result[i].first + result[i].second == ms[i]);
      printf("%d %d\n", result[i].first, result[i].second);
    }
  }
};

}  // namespace

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

