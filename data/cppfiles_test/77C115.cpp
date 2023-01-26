#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using pll = std::pair<int64_t, int64_t>;
using tiii = std::tuple<int, int, int>;
using ui = uint32_t;
using ll = int64_t;
using ull = uint64_t;
using GR = std::vector<std::vector<int>>;
using namespace std;
class JRobotFactory {
  std::vector<std::vector<char>> used;

 public:
  const std::vector<pii> goes = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  int cnt = 0;
  void dfs(int64_t i, int64_t j, const std::vector<std::vector<int>> &a) {
    used[i][j] = true;
    ++cnt;
    for (int64_t goind = (int64_t)(0); goind < (int64_t)(4); ++goind)
      if (!((((ll)1) << (goind)) & a[i][j])) {
        const auto &go = goes[3 - goind];
        int i1 = i + go.first, j1 = j + go.second;
        if (!used[i1][j1]) dfs(i1, j1, a);
      }
  }
  void solveOne(std::istream &in, std::ostream &out) {
    int n, m;
    in >> n >> m;
    std::vector<std::vector<int>> a(n, (std::vector<int>(m)));
    for (int64_t i = (int64_t)(0); i < (int64_t)(n); ++i)
      generate((a[i]).begin(), (a[i]).end(), [&in]() {
        ll x;
        in >> x;
        return x;
      });
    {
      std::vector<std::vector<char>> _used(n, (std::vector<char>(m, false)));
      used = std::move(_used);
    }
    std::vector<int> sizes(0);
    for (int64_t i = (int64_t)(0); i < (int64_t)(n); ++i)
      for (int64_t j = (int64_t)(0); j < (int64_t)(m); ++j) {
        if (!used[i][j]) cnt = 0, dfs(i, j, a), sizes.push_back(cnt);
      }
    sort((sizes).begin(), (sizes).end());
    for (int64_t i = (int64_t)((static_cast<int>((sizes).size())) - 1);
         i >= (int64_t)(0); --i)
      out << sizes[i] << " ";
    out << "\n";
  }
  void solve(std::istream &in, std::ostream &out) {
    int TestsCount = 1;
    for (int i = 1; i <= TestsCount; ++i) {
      solveOne(in, out);
    }
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  JRobotFactory solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);
  fflush(stdout);
  return 0;
}
