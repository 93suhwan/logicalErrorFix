#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
const int MAXANS = 455;
int dp[maxn][MAXANS];
void Update(int& x, int y) {
  if (x < y) {
    x = y;
  }
}
void Solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a.push_back(0);
  reverse(a.begin(), a.end());
  vector<int64_t> pref(n + 1);
  for (int i = 1; i <= n; ++i) {
    pref[i] = a[i] + pref[i - 1];
  }
  auto Get = [&](int l, int r) { return pref[r] - pref[l - 1]; };
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < MAXANS; ++j) {
      dp[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < MAXANS; ++j) {
      Update(dp[i + 1][j], dp[i][j]);
      if (j == 0 || (i + j + 1 <= n && dp[i][j] > Get(i + 1, i + j + 1))) {
        Update(dp[i + j + 1][j + 1], Get(i + 1, i + j + 1));
      }
    }
  }
  for (int i = MAXANS - 1; i >= 0; --i) {
    if (dp[n][i] > 0) {
      cout << i << '\n';
      return;
    }
  }
  exit(1);
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    Solve();
  }
  return 0;
}
