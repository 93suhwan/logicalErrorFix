#include <bits/stdc++.h>
using namespace std;
const int max_n = 2e5 + 10, inf = 1000111222;
int a[max_n];
vector<pair<int, int>> before[max_n];
vector<int> suf_min_r[max_n];
vector<long long> dp[max_n];
void solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i <= n; i++) {
    before[i].clear();
    suf_min_r[i].clear();
    dp[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    int id = upper_bound(a, a + n, r) - a;
    if (id == 0 || a[id - 1] < l) {
      before[id].push_back(make_pair(l, r));
    }
  }
  for (int i = 0; i <= n; i++) {
    sort(before[i].begin(), before[i].end());
  }
  for (int i = 0; i <= n; i++) {
    suf_min_r[i].reserve((int)(before[i].size()));
    for (int j = (int)(before[i].size()) - 1; j >= 0; j--) {
      suf_min_r[i].push_back(
          min((suf_min_r[i].empty() ? +inf : suf_min_r[i].back()),
              before[i][j].second));
    }
    reverse(suf_min_r[i].begin(), suf_min_r[i].end());
  }
  vector<pair<int, long long>> cur_dp;
  if (before[0].empty()) {
    cur_dp.push_back(make_pair(0, 0));
  } else {
    int want_r = suf_min_r[0][0];
    cur_dp.push_back(make_pair(a[0] - want_r, a[0] - want_r));
  }
  a[n] = +inf;
  for (int i = 0; i < n; i++) {
    sort(cur_dp.begin(), cur_dp.end());
    vector<long long> pref_min__dp_plus_l;
    pref_min__dp_plus_l.reserve((int)(cur_dp.size()));
    vector<long long> suf_min__dp;
    suf_min__dp.reserve((int)(cur_dp.size()));
    for (int j = 0; j < (int)(cur_dp.size()); j++) {
      pref_min__dp_plus_l.push_back(
          min((pref_min__dp_plus_l.empty() ? 1ll * inf * inf
                                           : pref_min__dp_plus_l.back()),
              cur_dp[j].first + cur_dp[j].second));
    }
    for (int j = (int)(cur_dp.size()) - 1; j >= 0; j--) {
      suf_min__dp.push_back(
          min((suf_min__dp.empty() ? 1ll * inf * inf : suf_min__dp.back()),
              cur_dp[j].second));
    }
    reverse(suf_min__dp.begin(), suf_min__dp.end());
    auto get_new_dp = [&](int cur_max_R) {
      int next_in_before_i_plus_one =
          upper_bound(before[i + 1].begin(), before[i + 1].end(),
                      make_pair(cur_max_R, +inf)) -
          before[i + 1].begin();
      int to_go_for_next_guy = -1;
      if (next_in_before_i_plus_one == (int)(before[i + 1].size())) {
        to_go_for_next_guy = 0;
      } else {
        to_go_for_next_guy =
            a[i + 1] - suf_min_r[i + 1][next_in_before_i_plus_one];
      }
      long long value_dp_from_left = 1ll * inf * inf;
      {
        int pref_to_use = upper_bound(cur_dp.begin(), cur_dp.end(),
                                      make_pair((cur_max_R - a[i]) + 1, -1ll)) -
                          cur_dp.begin();
        if (pref_to_use != 0) {
          value_dp_from_left =
              min(value_dp_from_left, pref_min__dp_plus_l[pref_to_use - 1] +
                                          1ll * (cur_max_R - a[i]));
        }
      }
      {
        int suf_to_use = upper_bound(cur_dp.begin(), cur_dp.end(),
                                     make_pair((cur_max_R - a[i]) + 1, -1ll)) -
                         cur_dp.begin();
        if (suf_to_use != (int)(cur_dp.size())) {
          value_dp_from_left =
              min(value_dp_from_left,
                  suf_min__dp[suf_to_use] + 2ll * (cur_max_R - a[i]));
        }
      }
      long long value_of_dp = 1ll * to_go_for_next_guy + value_dp_from_left;
      return make_pair(to_go_for_next_guy, value_of_dp);
    };
    vector<pair<int, long long>> new_dp;
    new_dp.reserve((int)(before[i + 1].size()) + 1);
    new_dp.push_back(get_new_dp(a[i]));
    for (auto q : before[i + 1]) {
      new_dp.push_back(get_new_dp(q.first));
    }
    cur_dp = new_dp;
  }
  long long ans = 1ll * inf * inf;
  for (auto i : cur_dp) {
    if (i.first == 0) {
      ans = min(ans, i.second);
    }
  }
  cout << ans << "\n";
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    solve();
  }
}
