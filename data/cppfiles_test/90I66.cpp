#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 1e15;
int64_t solve(const vector<int>& a, const vector<int>& l,
              const vector<int>& r) {
  int n = a.size();
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
  m = segments.size();
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
  m = int(cp.size()) - 1;
  vector<int64_t> dp(cp[m] + 1), leftdist(cp[m]), rightdist(cp[m]);
  for (int i = 0; i < cp[m]; ++i) {
    leftdist[i] = segments[i].first - u[i];
  }
  for (int j = 0; j < m; ++j) {
    for (int i = cp[j + 1] - 1, min_right = INT_MAX; i >= cp[j]; --i) {
      min_right = min(min_right, segments[i].second);
      rightdist[i] = v[i] - min_right;
    }
  }
  dp[0] = 0;
  for (int i = cp[0]; i < cp[1]; ++i) {
    dp[i + 1] = leftdist[i];
  }
  for (int j = 1; j < m; ++j) {
    int ti = t[cp[j] - 1];
    assert(ti > 0);
    if (ti == 1) {
      int x = u[cp[j]];
      int start = cp[j - 1];
      int len = cp[j] - start;
      vector<int> leftside(len);
      leftside[len - 1] = segments[cp[j] - 1].second;
      for (int i = len - 2; i >= 0; --i) {
        leftside[i] = min(leftside[i + 1], segments[start + i].second);
      }
      vector<int64_t> leftdp(len), suffix(len + 1);
      suffix[len] = inf;
      for (int i = cp[j] - 1; i >= start; --i) {
        leftdp[i - start] = dp[i] - leftside[i - start];
        suffix[i - start] = dp[i] + x - 2 * leftside[i - start];
        suffix[i - start] = min(suffix[i - start], suffix[i - start + 1]);
      }
      vector<int64_t> prefix(len + 1);
      prefix[0] = inf;
      for (int i = start; i < cp[j]; ++i) {
        prefix[i - start + 1] = min(prefix[i - start], leftdp[i - start]);
      }
      int p = len;
      for (int i = cp[j]; i < cp[j + 1]; ++i) {
        int rightside = segments[i].first;
        while ((p > 0) && ((x - leftside[p - 1]) < (rightside - x))) {
          p--;
        }
        dp[i + 1] = min(dp[cp[j]] + leftdist[i],
                        rightside + min(suffix[p], prefix[p] + rightside - x));
      }
      dp[cp[j]] = min(dp[cp[j]], dp[cp[j - 1]] + rightdist[cp[j - 1]]);
    } else {
      for (int i = cp[j] - 1; i >= cp[j - 1]; --i) {
        dp[cp[j]] = min(dp[cp[j]], dp[i] + rightdist[i]);
      }
      for (int i = cp[j]; i < cp[j + 1]; ++i) {
        dp[i + 1] = dp[cp[j]] + leftdist[i];
      }
    }
  }
  for (int i = cp[m] - 1; i >= cp[m - 1]; --i) {
    dp[cp[m]] = min(dp[cp[m]], dp[i] + rightdist[i]);
  }
  return dp[cp[m]];
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
