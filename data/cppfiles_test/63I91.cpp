#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
const int MM = 998244353;
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
int _runtimeTerror_() {
  int n;
  cin >> n;
  vector<string> a(n);
  vector<int> len(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    len[i] = (long long)a[i].size();
  }
  vector<map<int, int>> mp(n);
  vector<int> tsum(n, 0);
  for (int i = 0; i < n; ++i) {
    int mn = 0;
    for (char c : a[i]) {
      tsum[i] += c == '(';
      tsum[i] -= c == ')';
      if (tsum[i] <= mn) {
        ++mp[i][tsum[i]];
        amin(mn, tsum[i]);
      }
    }
  }
  vector<long long> dp(1 << n, -2000000000000000000);
  dp[0] = 0;
  vector<long long> sum(1 << n, 0);
  for (int i = 1; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        sum[i] += tsum[j];
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < (1 << n); ++i) {
    amax(ans, dp[i]);
    if (dp[i] == -2000000000000000000) {
      continue;
    }
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) == 0) {
        int f = mp[j].begin()->first;
        if (f + sum[i] < 0) {
          amax(ans, dp[i] + mp[j][-sum[i]]);
        } else {
          amax(dp[i | (1 << j)], dp[i] + mp[j][-sum[i]]);
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  return 0;
}
