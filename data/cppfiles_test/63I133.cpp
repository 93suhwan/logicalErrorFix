#include <bits/stdc++.h>
using namespace std;
long long bs(vector<long long>& v, long long x) {
  long long l = 0;
  long long r = v.size();
  long long ans = r;
  while (l < r) {
    long long mid = (l + r) >> 1;
    if (x + v[mid] < 0) {
      ans = mid;
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<string> s(n);
  vector<map<long long, vector<long long>>> mp(n);
  vector<vector<long long>> v(n);
  vector<long long> sm(n);
  for (long long i = 0; i < n; i++) cin >> s[i];
  for (long long i = 0; i < n; i++) {
    long long smm = 0;
    long long mi = 0;
    for (long long j = 0; j < s[i].length(); j++) {
      char c = s[i][j];
      if (c == '(')
        smm++;
      else
        smm--;
      mp[i][smm].push_back(j);
      mi = min(mi, smm);
      v[i].push_back(mi);
    }
    sm[i] = smm;
  }
  vector<long long> SM(1 << n);
  for (long long i = 0; i < 1 << n; i++) {
    for (long long j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        SM[i] += sm[j];
      }
    }
  }
  vector<vector<long long>> dp(1 << n, vector<long long>(2));
  for (long long i = 1; i < 1 << n; i++) {
    for (long long j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        long long mask = i ^ (1 << j);
        if (v[j].back() + SM[mask] >= 0 && SM[mask] >= 0) {
          auto it = mp[j].find(-SM[mask]);
          long long tot = 0;
          if (it != mp[j].end()) tot = it->second.size();
          dp[i][0] = max(dp[i][0], dp[mask][0] + tot);
        } else {
          long long idx = bs(v[j], SM[mask]);
          long long tot = 0;
          auto it = mp[j].find(-SM[mask]);
          if (it != mp[j].end()) {
            tot = lower_bound(it->second.begin(), it->second.end(), idx) -
                  it->second.begin();
          }
          dp[i][1] = max(dp[i][1], dp[mask][1]);
          dp[i][1] = max(dp[i][1], dp[mask][0] + tot);
        }
      }
    }
  }
  cout << max(dp[(1 << n) - 1][0], dp[(1 << n) - 1][1]);
  return 0;
}
