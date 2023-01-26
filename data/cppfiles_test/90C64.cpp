#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 1e15;
vector<pair<int, int>> process_segments(const vector<int>& a,
                                        const vector<int>& l,
                                        const vector<int>& r) {
  int m = l.size();
  vector<pair<int, int>> segments;
  for (int i = 0; i < m; ++i) {
    auto it = lower_bound(a.begin(), a.end(), l[i]);
    if ((it == a.end()) || (*it > r[i])) {
      segments.emplace_back(l[i], r[i]);
    }
  }
  sort(segments.begin(), segments.end());
  segments.resize(unique(segments.begin(), segments.end()) - segments.begin());
  stack<pair<int, int>> st;
  for (const pair<int, int>& seg : segments) {
    while (!st.empty() && (st.top().second >= seg.second)) {
      st.pop();
    }
    st.push(seg);
  }
  vector<pair<int, int>> seg2;
  while (!st.empty()) {
    seg2.push_back(st.top());
    st.pop();
  }
  reverse(seg2.begin(), seg2.end());
  return seg2;
}
template <class T>
T& chmin(T& x, T y) {
  if (y < x) x = y;
  return x;
}
template <class T>
T& chmax(T& x, T y) {
  if (y > x) x = y;
  return x;
}
int64_t solve_sub(const vector<pair<int, int>>& segments, const vector<int>& cp,
                  const vector<int64_t>& u, const vector<int64_t>& v,
                  int range_start, int range_end) {
  vector<int64_t> dp(cp[range_start + 1] - cp[range_start] + 1);
  dp[0] = 0;
  for (int i = cp[range_start]; i < cp[range_start + 1]; ++i) {
    dp[i - cp[range_start] + 1] = segments[i].first - u[i];
  }
  for (int i = range_start + 1; i < range_end; ++i) {
    int64_t x = u[cp[i]];
    vector<int64_t> dp2(cp[i + 1] - cp[i] + 1);
    dp2[0] = dp[cp[i] - cp[i - 1]];
    for (int j = cp[i - 1]; j < cp[i]; ++j) {
      chmin(dp2[0], dp[j - cp[i - 1]] + x - segments[j].second);
    }
    vector<int64_t> prefix(cp[i] - cp[i - 1] + 1),
        suffix(cp[i] - cp[i - 1] + 1);
    prefix[0] = inf;
    suffix[cp[i] - cp[i - 1]] = inf;
    for (int j = cp[i - 1]; j < cp[i]; ++j) {
      prefix[j - cp[i - 1] + 1] =
          min(prefix[j - cp[i - 1]], dp[j - cp[i - 1]] - segments[j].second);
    }
    for (int j = cp[i] - 1; j >= cp[i - 1]; --j) {
      suffix[j - cp[i - 1]] =
          min(suffix[j - cp[i - 1] + 1],
              dp[j - cp[i - 1]] + x - 2 * segments[j].second);
    }
    int p = cp[i - 1];
    for (int j1 = cp[i + 1] - 1; j1 >= cp[i]; --j1) {
      int64_t right_dist = segments[j1].first - x;
      while ((p < cp[i]) && ((x - segments[p].second) > right_dist)) {
        p++;
      }
      dp2[j1 - cp[i] + 1] =
          min(dp[cp[i] - cp[i - 1]] + right_dist,
              min(prefix[p - cp[i - 1]] + 2 * segments[j1].first - x,
                  suffix[p - cp[i - 1]] + segments[j1].first));
    }
    dp2.swap(dp);
  }
  int64_t ans = dp[cp[range_end] - cp[range_end - 1]];
  int64_t x = v[cp[range_end - 1]];
  for (int i = cp[range_end - 1]; i < cp[range_end]; ++i) {
    ans = min(ans, dp[i - cp[range_end - 1]] + x - segments[i].second);
  }
  return ans;
}
int64_t solve(const vector<int>& a, const vector<int>& l,
              const vector<int>& r) {
  int n = a.size();
  vector<pair<int, int>> segments = process_segments(a, l, r);
  int m = segments.size();
  if (m == 0) return 0;
  vector<int64_t> u(m), v(m);
  vector<int> ui(m), vi(m);
  vector<int> t(m - 1);
  for (int i = 0; i < m; ++i) {
    ui[i] = lower_bound(a.begin(), a.end(), segments[i].first) - a.begin();
    u[i] = (ui[i] == 0) ? -inf : a[ui[i] - 1];
    vi[i] = upper_bound(a.begin(), a.end(), segments[i].second) - a.begin();
    v[i] = (vi[i] == n) ? inf : a[vi[i]];
    if (i > 0) {
      int uu = ui[i] - 1;
      int vv = vi[i - 1];
      t[i - 1] = (vv == uu) ? 1 : ((uu > vv) ? 2 : 0);
    }
  }
  vector<int> cp(1, 0);
  for (int i = 0; i < (m - 1); ++i) {
    if (t[i] != 0) {
      cp.push_back(i + 1);
    }
  }
  cp.push_back(m);
  int64_t ans = 0;
  m = int(cp.size()) - 1;
  int prv = 0;
  for (int i = 1; i <= m; ++i) {
    if ((i == m) || (t[cp[i] - 1] == 2)) {
      ans += solve_sub(segments, cp, u, v, prv, i);
      prv = i;
    }
  }
  return ans;
}
void test_case() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i];
  }
  cout << solve(a, l, r) << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    test_case();
  }
}
