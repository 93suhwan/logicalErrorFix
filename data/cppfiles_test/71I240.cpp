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
  int n, k;
  cin >> n >> k;
  --k;
  vector<pair<int, int>> p(n);
  for (auto& x : p) cin >> x.first >> x.second;
  auto get_dir = [](const pair<int, int>& lhs,
                    const pair<int, int>& rhs) -> pair<int, int> {
    int up = lhs.first - rhs.first;
    int down = lhs.second - rhs.second;
    if (down == 0) {
      return {up / abs(up), down};
    }
    int d = gcd(abs(up), abs(down));
    up /= d;
    down /= d;
    if (1ll * up * down < 0) {
      up = -abs(up);
      down = abs(down);
    } else {
      up = abs(up);
      down = abs(down);
    }
    return {up, down};
  };
  auto sqr = [](long long x) -> long long { return x * x; };
  auto get_dist = [&](const pair<int, int>& lhs,
                      const pair<int, int>& rhs) -> double {
    return sqrt(sqr(lhs.first - rhs.first) + sqr(lhs.second - rhs.second));
  };
  if (n == 3) {
    int r1 = -1, r2 = -1;
    for (int i = (0), _b = (3); i < _b; ++i)
      if (i != k) {
        if (r1 < 0)
          r1 = i;
        else
          r2 = i;
      }
    double res = get_dist(p[k], p[r1]) + get_dist(p[r1], p[r2]);
    update_min(res, get_dist(p[k], p[r2]) + get_dist(p[r2], p[r1]));
    cout << fixed << setprecision(7) << res << '\n';
    return;
  }
  vector<pair<pair<int, int>, int>> checking;
  for (int i = (1), _b = (4); i < _b; ++i) {
    checking.push_back({get_dir(p[0], p[i]), i});
  }
  auto cmp = [&](int u, int v) -> bool {
    return checking[u].first == checking[v].first;
  };
  int non_line_index = -1;
  sort(checking.begin(), checking.end());
  if (cmp(0, 1) && cmp(1, 2)) {
    for (int i = (4), _b = (n); i < _b; ++i)
      if (checking[0].first != get_dir(p[0], p[i])) {
        non_line_index = i;
        break;
      }
  } else if (cmp(0, 1)) {
    non_line_index = checking[2].second;
  } else if (cmp(1, 2)) {
    non_line_index = checking[0].second;
  } else {
    non_line_index = 0;
  }
  double ans = ll_inf;
  vector<pair<pair<int, int>, int>> lines;
  for (int i = (0), _b = (n); i < _b; ++i)
    if (i != non_line_index) lines.push_back({p[i], i});
  sort(lines.begin(), lines.end());
  cerr << "non_line_index"
       << ": " << (non_line_index) << '\n';
  ;
  cerr << "p[non_line_index].first"
       << ": " << (p[non_line_index].first) << ", "
       << "p[non_line_index].second"
       << ": " << (p[non_line_index].second) << '\n';
  ;
  auto get_line_range = [&](int u, int v) -> double {
    if (u >= v) return 0;
    return get_dist(lines[u].first, lines[v].first);
  };
  cerr << "get_line_range(0, sz(lines) - 1)"
       << ": " << (get_line_range(0, (int)(lines).size() - 1)) << '\n';
  ;
  auto cost_to_range = [&](int u, int v) -> double {
    double temp = get_line_range(u, v);
    return min(get_dist(p[non_line_index], lines[u].first),
               get_dist(p[non_line_index], lines[v].first)) +
           temp;
  };
  cerr << "cost_to_range(0, sz(lines) - 1)"
       << ": " << (cost_to_range(0, (int)(lines).size() - 1)) << '\n';
  ;
  double line_dist = get_dist(lines[0].first, lines.back().first);
  cerr << "line_dist"
       << ": " << (line_dist) << '\n';
  ;
  if (non_line_index == k) {
    update_min(ans, cost_to_range(0, (int)(lines).size() - 1));
  } else {
    int pos_in_line = -1;
    for (int i = (0), _b = ((int)(lines).size()); i < _b; ++i)
      if (lines[i].second == k) pos_in_line = i;
    for (int i = pos_in_line + 1; i < (int)(lines).size(); ++i) {
      double cur_cost = get_line_range(pos_in_line, i - 1) +
                        get_line_range(i, (int)(lines).size() - 1) +
                        get_dist(p[non_line_index], lines[i - 1].first) +
                        get_dist(p[non_line_index], lines.back().first);
      if (pos_in_line > 0) cur_cost += get_line_range(0, i);
      update_min(ans, cur_cost);
      cur_cost = get_line_range(pos_in_line, i - 1) + get_line_range(0, i) +
                 get_dist(p[non_line_index], lines[i - 1].first) +
                 get_dist(p[non_line_index], lines[i].first) +
                 get_line_range(0, (int)(lines).size() - 1);
      update_min(ans, cur_cost);
      cur_cost = get_line_range(pos_in_line, i - 1) +
                 get_line_range(i, (int)(lines).size() - 1) +
                 get_dist(p[non_line_index], lines[i - 1].first) +
                 get_dist(p[non_line_index], lines[i].first);
      if (pos_in_line > 0)
        cur_cost += get_line_range(0, (int)(lines).size() - 1);
      update_min(ans, cur_cost);
    }
    for (int i = pos_in_line - 1; i >= 0; --i) {
      double cur_cost = get_line_range(i + 1, pos_in_line) +
                        get_line_range(0, i) +
                        get_dist(p[non_line_index], lines[i + 1].first) +
                        get_dist(p[non_line_index], lines[0].first);
      if (pos_in_line + 1 < (int)(lines).size())
        cur_cost += get_line_range(i, (int)(lines).size() - 1);
      update_min(ans, cur_cost);
      cur_cost = get_line_range(i + 1, pos_in_line) +
                 get_line_range(i, (int)(lines).size() - 1) +
                 get_dist(p[non_line_index], lines[i + 1].first) +
                 get_dist(p[non_line_index], lines[i].first) +
                 get_line_range(0, (int)(lines).size() - 1);
      update_min(ans, cur_cost);
      cur_cost = get_line_range(i + 1, pos_in_line) + get_line_range(0, i) +
                 get_dist(p[non_line_index], lines[i + 1].first) +
                 get_dist(p[non_line_index], lines[i].first);
      if (pos_in_line + 1 < (int)(lines).size())
        cur_cost += get_line_range(0, (int)(lines).size() - 1);
      update_min(ans, cur_cost);
    }
    double cur_cost = get_line_range(pos_in_line, (int)(lines).size() - 1) +
                      get_dist(p[non_line_index], lines.back().first);
    if (pos_in_line > 0) cur_cost += cost_to_range(0, pos_in_line - 1);
    update_min(ans, cur_cost);
    cur_cost = get_line_range(0, pos_in_line) +
               get_dist(p[non_line_index], lines[0].first);
    if (pos_in_line + 1 < (int)(lines).size())
      cur_cost += cost_to_range(pos_in_line + 1, (int)(lines).size() - 1);
    update_min(ans, cur_cost);
    update_min(ans, get_line_range(pos_in_line, (int)(lines).size() - 1) +
                        get_line_range(0, (int)(lines).size() - 1) +
                        get_dist(p[non_line_index], lines[0].first));
    update_min(ans, get_line_range(0, pos_in_line) +
                        get_line_range(0, (int)(lines).size() - 1) +
                        get_dist(p[non_line_index], lines.back().first));
    if (pos_in_line > 0) {
      update_min(ans, get_line_range(0, pos_in_line - 1) +
                          get_line_range(pos_in_line, (int)(lines).size() - 1) +
                          get_dist(p[non_line_index], lines[0].first) +
                          get_dist(p[non_line_index], lines.back().first));
    }
    if (pos_in_line + 1 < (int)(lines).size()) {
      update_min(ans,
                 get_line_range(0, pos_in_line) +
                     get_line_range(pos_in_line + 1, (int)(lines).size() - 1) +
                     get_dist(p[non_line_index], lines[0].first) +
                     get_dist(p[non_line_index], lines.back().first));
    }
  }
  cout << fixed << setprecision(7) << ans << '\n';
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
