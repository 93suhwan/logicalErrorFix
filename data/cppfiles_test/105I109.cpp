#include <bits/stdc++.h>
using namespace std;
template <typename num_t>
inline void add_mod(num_t& a, const long long& b, const int& m) {
  a = (a + b) % m;
  if (a < 0) a += m;
}
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) {
  return a < b ? a = b, true : false;
}
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) {
  return a > b ? a = b, true : false;
}
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) {
  return !lhs ? rhs : gcd(rhs % lhs, lhs);
}
template <typename num_t>
num_t pw(num_t n, num_t k, num_t mod) {
  num_t res = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) res = 1ll * res * n % mod;
    n = 1ll * n * n % mod;
  }
  return res;
}
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;
const long long ll_inf = 9ll * inf * inf;
const int max_n = 1e5 + 7;
void solve() {
  int test;
  cin >> test;
  while (test-- > 0) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& p : a) {
      cin >> p;
      --p;
    }
    vector<vector<int>> pos(n);
    vector<int> index(n);
    vector<pair<int, int>> segments;
    for (int i = 0; i < n; ++i) {
      index[i] = (int)(pos[a[i]]).size();
      pos[a[i]].push_back(i);
    }
    const int mx_base = 20;
    vector<vector<int>> dp(n, vector<int>(mx_base, inf));
    vector<int> temp_dp(n, inf);
    auto calc_best = [&](int u, int v) -> int {
      if (u > v) return -1;
      if (u >= v) return 0;
      temp_dp[u] = 0;
      for (int j = u + 1; j <= v; ++j) {
        int cur = a[j];
        if (index[j] == 0 || pos[cur][index[j] - 1] < u) {
          temp_dp[j] = temp_dp[j - 1] + 1;
        } else {
          temp_dp[j] = inf;
          for (int t = index[j] - 1; t >= 0 && pos[cur][t] >= u; --t) {
            int prev_j = pos[cur][t];
            int prev_cal = prev_j == u ? 0 : temp_dp[prev_j - 1] + 1;
            update_min(temp_dp[j], prev_cal + dp[j][t]);
          }
        }
      }
      return temp_dp[v];
    };
    for (int i = 0; i < n; ++i)
      if (index[i] > 0) {
        auto& cur_pos = pos[a[i]];
        dp[i][index[i]] = 0;
        for (int t = index[i] - 1; t >= 0; --t) {
          int now = calc_best(cur_pos[t] + 1, cur_pos[index[i]] - 1);
          update_min(dp[i][t], now + 1);
          update_min(dp[i][t], dp[i][t + 1] + dp[cur_pos[t + 1]][t]);
        }
      }
    cout << calc_best(0, n - 1) << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
