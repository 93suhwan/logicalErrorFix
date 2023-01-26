#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 100;
const long long mod = 998244353;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<vector<long long> > cnt(n, vector<long long>(26));
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (long long j = 0; j < (long long)s.size(); j++) {
      cnt[i][s[j] - 'a']++;
    }
  }
  vector<vector<long long> > dp_sum((1 << n), vector<long long>(2, 1));
  vector<long long> dp_min(1 << n);
  for (long long i = 0; i < 26; i++) {
    fill(dp_min.begin(), dp_min.end(), 1e9);
    for (long long bit = 0; bit < n; bit++) {
      for (long long msk = 0; msk < (1 << bit); msk++) {
        dp_min[(1 << bit) + msk] = min(dp_min[msk], cnt[bit][i]);
      }
    }
    dp_min[0] = 0;
    for (long long msk = 0; msk < (1 << n); msk++) {
      dp_sum[msk][1] = 1LL * dp_sum[msk][1] * (dp_min[msk] + 1) % mod;
    }
  }
  dp_sum[0][1] = 0;
  for (long long msk = 0; msk < (1 << n); msk++) {
    long long c = 0;
    dp_sum[msk][0] = 0;
    for (long long j = 0; j < n; j++) {
      c ^= (((1 << j) & msk) >> j);
    }
    if (!c) {
      dp_sum[msk][0] = (mod - dp_sum[msk][1]) % mod;
      dp_sum[msk][1] = 0;
    }
  }
  for (long long k = 0; k < 2; k++) {
    for (long long i = 0; i < n; i++) {
      for (long long msk = 0; msk < (1 << n); msk++) {
        if (msk & (1 << i)) {
          continue;
        }
        dp_sum[msk | (1 << i)][k] += dp_sum[msk][k];
        if (dp_sum[msk | (1 << i)][k] >= mod) {
          dp_sum[msk | (1 << i)][k] -= mod;
        }
      }
    }
  }
  long long ans = 0;
  for (long long msk = 0; msk < (1 << n); msk++) {
    long long sum = 0;
    long long c = 0;
    for (long long i = 0; i < n; i++) {
      if ((1 << i) & msk) {
        c++;
        sum += i + 1;
      }
    }
    long long s = (dp_sum[msk][0] + dp_sum[msk][1]) % mod;
    ans = ans ^ (1LL * sum * c * s);
  }
  cout << ans;
  return 0;
}
