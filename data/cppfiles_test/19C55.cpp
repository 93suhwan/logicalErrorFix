#include <bits/stdc++.h>
using namespace std;
namespace caide {
template <typename T>
bool relaxMin(T& target, const T& update) {
  if (target > update) {
    target = update;
    return true;
  }
  return false;
}
}  // namespace caide
using namespace caide;
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int t;
    in >> t;
    while (t--) {
      const int INF = 2020;
      vector<int> y(1001, INF);
      y[0] = 0;
      int n;
      in >> n;
      while (n--) {
        int a;
        in >> a;
        vector<int> y1(1001, INF);
        auto update = [&](int l, int r) {
          r += a;
          l = max(0, l - a);
          if (l > r) swap(l, r);
          if (l <= 1000 && l + r <= 2000) relaxMin(y1[l], r);
        };
        for (int x = 0; x <= 1000; ++x) {
          update(x, y[x]);
          update(y[x], x);
        }
        swap(y, y1);
      }
      int res = INF;
      for (int x = 0; x <= 1000; ++x) relaxMin(res, x + y[x]);
      out << res << '\n';
    }
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
