#include <bits/stdc++.h>
using namespace std;
long long t, n;
string s;
int32_t main() {
  cin >> t;
  while (t--) {
    cin >> n >> s;
    vector<string> v;
    for (long long i = 0; i < n; ++i) v.push_back(s.substr(i, n - i));
    sort(v.begin(), v.end());
    vector<long long> dp(n, 0);
    long long res = 0;
    for (long long i = n - 1; i >= 0; --i) {
      long long l = 0;
      for (long long j = n - 1; j > i; --j) {
        while (l < v[j].size() && l < v[i].size() && v[i][l] == v[j][l]) l++;
        if (v[j].size() < v[i].size()) {
          dp[i] = max(dp[i], dp[j] + (long long)v[j].size() - l);
        }
      }
      res = max(res, dp[i] + (long long)v[i].size());
    }
    cout << res << "\n";
  }
}
