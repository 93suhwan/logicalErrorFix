#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long mod = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, x;
    cin >> n >> k >> x;
    x--;
    string s;
    cin >> s;
    vector<pair<long long, long long>> v;
    for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
        if (v.empty()) {
          v.emplace_back(0ll, 1ll);
        } else {
          v.back().second++;
        }
      } else if (i == 0 || s[i - 1] != 'a') {
        v.emplace_back(1ll, 0ll);
      } else {
        v.back().first++;
      }
    }
    n = v.size();
    vector<long double> dp(n + 1);
    dp[n] = 1;
    for (long long i = n - 1; i >= 0; i--) {
      dp[i] = max(dp[i + 1], dp[i + 1] * (v[i].second * k + 1));
    }
    string s2;
    for (long long i = 0; i < n; i++) {
      long long p = 0;
      for (long long j = 0; j < v[i].first; j++) {
        cout << "a";
      }
      if (dp[i + 1] == 0) {
        continue;
      }
      if (dp[i + 1] > x) {
        p = 0;
      } else {
        p = x / (long long)dp[i + 1];
      }
      for (long long j = 0; j < p; j++) {
        cout << "b";
        x -= p * dp[i + 1];
      }
    }
    cout << '\n';
  }
}
