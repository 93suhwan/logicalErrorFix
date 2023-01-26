#include <bits/stdc++.h>
using namespace std;
const long long mx = 26;
const long long mod = 998244353;
const long long mx_step = (1 << 23);
long long getbit(long long mask, long long i) { return (mask >> i) & 1; }
long long dp[mx_step][2];
signed main() {
  cin.tie();
  cout.tie();
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  vector<string> s(n);
  vector<vector<long long>> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> s[i];
    a[i].resize(mx);
    for (long long j = 0; j < s[i].size(); ++j) {
      a[i][s[i][j] - 'a']++;
    }
  }
  long long o = (1 << n);
  for (long long l = 0; l < o; ++l) {
    dp[l][1] = 1;
  }
  vector<pair<long long, long long>> sorted_ids[26];
  for (long long i1 = 0; i1 < 26; ++i1) {
    for (long long j = 0; j < n; ++j) {
      sorted_ids[i1].push_back({a[j][i1], j});
    }
    sort(sorted_ids[i1].begin(), sorted_ids[i1].end());
  }
  for (long long i = mx - 1; i >= 0; --i) {
    for (long long mask = 0; mask < o; ++mask) {
      for (long long k = n - 1; k >= 0; --k) {
        long long id = sorted_ids[i][k].second;
        long long val = sorted_ids[i][k].first;
        if (getbit(mask, id) == 0) continue;
        dp[mask][0] += dp[(1ll << id)][1] * (val + 1);
        dp[mask][0] %= mod;
      }
    }
    for (long long j = 0; j < o; ++j) {
      dp[j][1] = dp[j][0];
      dp[j][0] = 0;
    }
  }
  long long ans = 0;
  for (long long m = 0; m < o; ++m) {
    long long k = 0;
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
      if (getbit(m, i) == 1) {
        k++;
        sum += i + 1;
      }
    }
    ans ^= dp[m][1] * k * sum;
  }
  cout << ans;
}
