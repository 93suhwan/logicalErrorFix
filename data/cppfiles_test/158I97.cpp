#include <bits/stdc++.h>
using namespace std;
void read(vector<int64_t> &a);
void read(vector<string> &a);
void read(vector<vector<int64_t>> &a);
void read(vector<pair<int64_t, int64_t>> &a);
void solve() {
  int64_t n, m;
  cin >> n >> m;
  vector<int64_t> exp(n);
  read(exp);
  vector<string> mat(n);
  read(mat);
  vector<pair<int64_t, int64_t>> dp(m);
  for (int64_t i = 0; i < m; i++) {
    dp[i].second = i;
    for (int64_t j = 0; j < n; j++) {
      dp[i].first += mat[j][i] - '0';
    }
  }
  sort(dp.begin(), dp.end());
  vector<int64_t> ans(m);
  for (int64_t i = 0; i < m; i++) {
    ans[dp[i].second] = i + 1;
  }
  int64_t m1 = 0;
  for (int64_t i = 0; i < n; i++) {
    int64_t temp = 0;
    for (int64_t j = 0; j < m; j++) {
      if (mat[i][j] == '1') temp += ans[j];
    }
    m1 += abs(exp[i] - temp);
  }
  vector<int64_t> ans2 = ans;
  for (int64_t i = 0; i < m; i++) {
    ans[dp[i].second] = m - i;
  }
  int64_t m2 = 0;
  for (int64_t i = 0; i < n; i++) {
    int64_t temp = 0;
    for (int64_t j = 0; j < m; j++) {
      if (mat[i][j] == '1') temp += ans[j];
    }
    m2 += abs(exp[i] - temp);
  }
  if (m1 <= m2) {
    for (int64_t i : ans) cout << i << " ";
    cout << endl;
  } else {
    for (int64_t i : ans2) cout << i << " ";
    cout << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int64_t t = 1;
  cin >> t;
  for (int64_t tt = 1; tt <= t; tt++) {
    solve();
  }
  return 0;
}
void read(vector<int64_t> &a) {
  for (int64_t i = 0; i < a.size(); i++) cin >> a[i];
}
void read(vector<string> &a) {
  for (int64_t i = 0; i < a.size(); i++) cin >> a[i];
}
void read(vector<vector<int64_t>> &a) {
  for (int64_t i = 0; i < a.size(); i++)
    for (int64_t j = 0; j < a[i].size(); j++) cin >> a[i][j];
}
void read(vector<pair<int64_t, int64_t>> &a) {
  for (int64_t i = 0; i < a.size(); i++) cin >> a[i].first >> a[i].second;
}
