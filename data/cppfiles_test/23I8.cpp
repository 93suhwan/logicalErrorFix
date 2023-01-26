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
const long long ll_inf = 3ll * inf * inf;
const int max_n = 1e5 + 7;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto& x : a) cin >> x;
  vector<vector<long long>> dp(n, vector<long long>(m + 1, -ll_inf));
  const int null = -1;
  function<int(int, int)> build = [&](int lhs, int rhs) -> int {
    if (lhs > rhs) {
      return null;
    }
    int root = lhs;
    for (int i = lhs + 1; i <= rhs; ++i)
      if (a[root] >= a[i]) {
        root = i;
      }
    dp[root][1] = a[root] * (m - 1);
    dp[root][0] = 0;
    if (lhs == rhs) {
      return root;
    }
    int left_node = build(lhs, root - 1);
    int right_node = build(root + 1, rhs);
    if (left_node != null) {
      for (int j = (0), _b = (m + 1); j < _b; ++j) {
        update_max(dp[root][j], dp[left_node][j]);
        if (j < m) {
          update_max(dp[root][j + 1],
                     dp[left_node][j] + a[root] * (m - 1 - 2 * j));
        }
      }
    }
    if (left_node != null && right_node != null) {
      for (int u = m - 1; u > 0; --u) {
        for (int v = (1), _b = (m + 1 - u); v < _b; ++v) {
          update_max(dp[root][u + v],
                     dp[root][u] + dp[right_node][v] - a[root] * 2 * (u * v));
        }
      }
    }
    if (right_node != null) {
      for (int j = (0), _b = (m + 1); j < _b; ++j) {
        update_max(dp[root][j], dp[right_node][j]);
        if (j < m) {
          update_max(dp[root][j + 1],
                     dp[right_node][j] + a[root] * (m - 1 - 2 * j));
        }
      }
    }
    return root;
  };
  int root = build(0, n - 1);
  cout << dp[root][m] << '\n';
  for (int i = (0), _b = (n); i < _b; ++i) {
    for (int j = (0), _b = (m + 1); j < _b; ++j) cout << dp[i][j] << ' ';
    cout << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test) cin >> test;
  for (int i = 0; i < test; ++i) {
    solve();
  }
}
