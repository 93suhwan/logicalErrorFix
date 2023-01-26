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
  auto product = [&](pair<int, int>& lhs, pair<int, int>& rhs) -> long long {
    return 1ll * lhs.first * rhs.second - 1ll * rhs.first * lhs.second;
  };
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> points(n);
  for (auto& p : points) cin >> p.first >> p.second;
  vector<long long> sum_product(n, 0);
  for (int i = 1; i < n; ++i) {
    sum_product[i] = sum_product[i - 1] + product(points[i - 1], points[i]);
  }
  auto calc_sum_segment = [&](int u, int v) -> long long {
    if (u <= v) {
      return sum_product[v] - sum_product[u];
    } else {
      return sum_product[v] + sum_product[n - 1] - sum_product[u] +
             product(points[n - 1], points[0]);
    }
  };
  auto calc_area = [&](int u, int v) -> long long {
    if (u == v) return 0;
    return abs(calc_sum_segment(u, v) + product(points[v], points[u]));
  };
  vector<vector<long long>> pre_sum_segment(n, vector<long long>(n, -ll_inf));
  vector<vector<long long>> pre_product(n, vector<long long>(n, -ll_inf));
  vector<vector<long long>> pre_area(n, vector<long long>(n, -ll_inf));
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      pre_product[u][v] = product(points[u], points[v]);
      pre_sum_segment[u][v] = calc_sum_segment(u, v);
      pre_area[u][v] = calc_area(u, v);
    }
  }
  auto calc_sub_area = [&](const pair<int, int>& lhs,
                           const pair<int, int>& rhs) {
    long long sum = pre_sum_segment[lhs.first][lhs.second] +
                    pre_product[lhs.second][rhs.first] +
                    pre_sum_segment[rhs.first][rhs.second] +
                    pre_product[rhs.second][lhs.first];
    return abs(sum);
  };
  auto get_prev = [&](int v) -> int {
    --v;
    if (v < 0) v += n;
    return v;
  };
  auto get_nxt = [&](int u) -> int {
    ++u;
    if (u >= n) u -= n;
    return u;
  };
  vector<vector<int>> dp(n, vector<int>(n, 0));
  auto calc_max_cut = [&](long long max_area) -> int {
    if (calc_area(0, n - 1) < max_area) {
      return -inf;
    }
    for (int u = (0), _b = (n); u < _b; ++u)
      for (int v = (0), _b = (n); v < _b; ++v) dp[u][v] = -inf;
    for (int len = 2; len < n; ++len) {
      for (int u = 0; u < n; ++u) {
        int v = (u + len);
        if (v >= n) v -= n;
        if (pre_area[u][v] < max_area) {
          continue;
        }
        int rhs = v;
        while (rhs != u &&
               calc_sub_area({u, u}, {get_prev(rhs), v}) < max_area) {
          rhs = get_prev(rhs);
        }
        rhs = get_prev(rhs);
        dp[u][v] = 0;
        if (get_nxt(u) == rhs) {
          continue;
        }
        for (int k = u; k != v; k = get_nxt(k)) {
          if (k == rhs) rhs = get_nxt(rhs);
          while (rhs != v &&
                 calc_sub_area({u, k}, {get_nxt(rhs), v}) >= max_area)
            rhs = get_nxt(rhs);
          if (calc_sub_area({u, k}, {rhs, v}) >= max_area) {
            update_max(dp[u][v], dp[k][rhs] + 1);
          }
          if (rhs == v) break;
        }
        if (pre_area[u][v] < 3 * max_area) continue;
        int nxt_k = u;
        pair<int, int> v_seg = {v, v};
        for (int k = get_nxt(u); k != v && nxt_k != v; k = get_nxt(k)) {
          long long pre_cal = pre_area[u][k];
          if (get_nxt(nxt_k) == k) nxt_k = k;
          if (pre_cal < max_area) {
            continue;
          }
          while (nxt_k != v &&
                 calc_sub_area({u, nxt_k}, v_seg) < max_area + pre_cal)
            nxt_k = get_nxt(nxt_k);
          if (nxt_k != v) {
            update_max(dp[u][v], dp[u][k] + dp[nxt_k][v] + 2);
          }
        }
      }
    }
    int best = 0;
    for (int u = 0; u < n; ++u)
      for (int v = u + 1; v < n; ++v) {
        update_max(best, dp[u][v] + dp[v][u] + 1);
      }
    return best;
  };
  if (k == 0) {
    cout << calc_area(0, n - 1) << '\n';
    return;
  }
  long long low = 1, high = calc_area(0, n - 1) / k + 1, found = -1;
  while (low <= high) {
    auto mid = (low + high) >> 1;
    if (calc_max_cut(mid) >= k) {
      found = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << found << '\n';
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
