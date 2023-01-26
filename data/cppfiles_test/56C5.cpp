#include <bits/stdc++.h>
using namespace std;
mt19937 azino(1337);
const long double PI = 3.14159265358979323846;
void io() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
const int32_t MOD = 1e9 + 7;
int32_t add(int32_t a, int32_t b) {
  if (a + b < MOD) return a + b;
  return a + b - MOD;
}
int32_t sub(int32_t a, int32_t b) {
  if (a - b < 0) return a - b + MOD;
  return a - b;
}
int32_t mul(int32_t a, int32_t b) { return int64_t(a) * b % MOD; }
void solve() {
  map<string, int32_t> num = {{"white", 0}, {"yellow", 1}, {"green", 2},
                              {"blue", 3},  {"red", 4},    {"orange", 5}};
  map<int32_t, int32_t> re = {{0, 1}, {1, 0}, {2, 3}, {3, 2}, {4, 5}, {5, 4}};
  map<int64_t, map<int32_t, int32_t>> unord;
  set<int64_t> must;
  map<int64_t, int32_t> color;
  int32_t k;
  cin >> k;
  int32_t n;
  cin >> n;
  must.insert(1);
  for (int32_t i = 0; i < n; ++i) {
    int64_t v;
    string clr;
    cin >> v >> clr;
    int32_t clr2 = num[clr];
    color[v] = clr2;
    if (v >= (int64_t(1) << (k - 1))) {
      unord[v][clr2] = 1;
    }
    while (v != 0) {
      must.insert(v);
      v /= 2;
    }
  }
  int32_t ans = 1;
  for (int32_t i = 0; i + 1 < k; ++i) {
    for (auto it = must.lower_bound(int64_t(1) << (k - i - 2));
         it != must.end() && *it < (int64_t(1) << (k - i - 1)); ++it) {
      int64_t v = *it;
      for (int32_t lc = 0; lc < 6; ++lc) {
        for (int32_t rc = 0; rc < 6; ++rc) {
          for (int32_t vc = 0; vc < 6; ++vc) {
            int32_t rt = re[vc];
            if (vc != lc && vc != rc && lc != rt && rc != rt) {
              int32_t cl =
                  (must.find(2 * v) == must.end() ? ans : unord[2 * v][lc]);
              int32_t cr =
                  (must.find(2 * v + 1) == must.end() ? ans
                                                      : unord[2 * v + 1][rc]);
              unord[v][vc] = add(unord[v][vc], mul(cl, cr));
            }
          }
        }
      }
      if (color.find(v) != color.end()) {
        int32_t xxx = color[v];
        for (int32_t j = 0; j < 6; ++j) {
          if (j != xxx) unord[v][j] = 0;
        }
      }
    }
    ans = mul(16, mul(ans, ans));
  }
  ans = 0;
  for (auto &elem : unord[1]) ans = add(ans, elem.second);
  cout << ans;
}
int32_t main() {
  io();
  solve();
  return 0;
}
