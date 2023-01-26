#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int32_t>& v) {
  int n = v.size();
  int inf = n + 1;
  int32_t dp[2][2][2][2] = {
      {{{-inf, v[0]}, {inf, inf}}, {{-inf, -v[0]}, {inf, inf}}}};
  const int32_t iter_init[2][2] = {{inf, inf}, {inf, inf}};
  vector<uint8_t> trace;
  trace.resize(n);
  for (size_t i = 1; i < n; ++i) {
    auto& cur = dp[i & 1];
    auto const& prev = dp[1 - (i & 1)];
    int x = v[i];
    bool stop = true;
    uint8_t& tr = trace[i];
    for (size_t sign = 0; sign < 2; ++sign, x = -x) {
      auto& dst = cur[sign];
      memcpy(&dst, &iter_init, sizeof(iter_init));
      for (size_t j = 0; j < 2; ++j) {
        for (size_t k = 0; k < 2; ++k) {
          if (x < prev[j][k][0]) continue;
          if (x > prev[j][k][1]) {
            if (dst[0][0] > prev[j][k][0]) {
              dst[0][0] = prev[j][k][0];
              dst[0][1] = x;
              tr &= ~(3 << (sign * 4));
              tr |= (j * 2 + k) << (sign * 4);
              stop = false;
            }
          } else {
            int tmp = std::max(prev[j][k][1], x);
            if (dst[1][1] > tmp) {
              dst[1][0] = x;
              dst[1][1] = tmp;
              tr &= ~(3 << (sign * 4 + 2));
              tr |= (j * 2 + k) << (sign * 4 + 2);
              stop = false;
            }
          }
        }
      }
    }
    if (stop) {
      return false;
    }
  }
  size_t state = 0;
  for (; state < 4; ++state) {
    if (dp[1 - (n & 1)][state / 2][state & 1][0] < inf) break;
  }
  for (size_t i = n - 1; i + 1 != 0; --i) {
    if (state & 2) {
      v[i] = -v[i];
    }
    state = (trace[i] >> (state * 2)) & 3;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  size_t nn;
  cin >> nn;
  vector<int32_t> v;
  for (size_t i = 0; i < nn; ++i) {
    size_t n = 0;
    cin >> n;
    v.resize(n);
    for (auto& x : v) {
      cin >> x;
    }
    if (solve(v)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
      continue;
    }
    bool spc = false;
    for (int32_t x : v) {
      if (spc) cout << ' ';
      cout << x;
      spc = true;
    }
    cout << endl;
  }
  return 0;
}
