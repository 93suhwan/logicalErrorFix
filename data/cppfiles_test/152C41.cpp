#include <bits/stdc++.h>
using namespace std;
struct State {
  int st, nd, val, prv;
  State(int st_, int nd_, int val_, int prv_)
      : st(st_), nd(nd_), val(val_), prv(prv_) {}
  bool operator>(const State& other) const {
    if (st != other.st) {
      return st > other.st;
    }
    return nd > other.nd;
  }
  void update(int x) {
    if (x > st) {
      st = x;
    } else if (x > nd) {
      nd = x;
    }
  }
  string to_string() const {
    stringstream ss;
    ss << st << ' ' << nd << ' ' << val << ' ' << prv;
    return ss.str();
  }
};
vector<State> cleanup(const vector<State>& v) {
  vector<State> cleaned;
  int n = v.size();
  vector<int> o(n);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(), [&v](int i1, int i2) { return v[i1] > v[i2]; });
  for (int i : o) {
    const State& state = v[i];
    while (!cleaned.empty() && (cleaned.back().nd >= state.nd)) {
      cleaned.pop_back();
    }
    cleaned.push_back(state);
  }
  return cleaned;
}
vector<int> solve(const vector<int>& p) {
  int n = p.size();
  int inf = n + 5;
  vector<vector<State>> dp(n);
  dp[0].emplace_back(p[0], -inf, p[0], -1);
  dp[0].emplace_back(-p[0], -inf, -p[0], -1);
  dp[0] = cleanup(dp[0]);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < int(dp[i - 1].size()); ++j) {
      const State& prv = dp[i - 1][j];
      for (int flip = -1; flip < 2; flip += 2) {
        int val = p[i] * flip;
        if (val > prv.nd) {
          State new_state = prv;
          new_state.val = val;
          new_state.prv = j;
          new_state.update(val);
          dp[i].push_back(new_state);
        }
      }
    }
    dp[i] = cleanup(dp[i]);
  }
  if (dp[n - 1].empty()) {
    return {};
  }
  vector<int> a(n);
  int cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    a[i] = dp[i][cur].val;
    cur = dp[i][cur].prv;
  }
  return a;
}
void test_case() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> ans = solve(p);
  if (ans.empty()) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      if (i > 0) cout << ' ';
      cout << ans[i];
    }
    cout << '\n';
  }
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
