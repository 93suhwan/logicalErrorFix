#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
class BOddGrasshopper {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int t;
    in >> t;
    while (t--) {
      int64_t x, n;
      in >> x >> n;
      if (n == 0) {
        out << x << "\n";
        continue;
      }
      if (x % 2 == 0) {
        if (n % 2 == 0) {
          if ((n / 2) % 2 == 0) {
            x += 0;
          } else {
            x += 1;
          }
        } else {
          if (((n - 1) / 2) % 2 == 0) {
            x -= n;
          } else {
            x += (n + 1);
          }
        }
      } else {
        if (n % 2 == 0) {
          if ((n / 2) % 2 == 0) {
            x += 0;
          } else {
            x -= 1;
          }
        } else {
          if (((n - 1) / 2) % 2 == 0) {
            x += n;
          } else {
            x -= (n + 1);
          }
        }
      }
      out << x << "\n";
    }
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  BOddGrasshopper solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
