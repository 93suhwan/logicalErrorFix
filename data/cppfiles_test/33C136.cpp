#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<long long> st(11, 1);
    for (int i = 1; i < 11; ++i) {
      st[i] = st[i - 1] * 2;
    }
    vector<pair<long long, long long>> dp(513, {0, 550});
    dp[0].first = 1;
    dp[0].second = 513;
    for (int i = 0; i < n; ++i) {
      long long k;
      for (int j = 0; j < 11; ++j) {
        if (st[j] >= a[i]) {
          k = st[j];
          break;
        }
      }
      if (dp[a[i]].first) {
        dp[a[i]].second = min(dp[a[i]].second, a[i]);
      } else {
        dp[a[i]].first = 1;
        dp[a[i]].second = a[i];
      }
      for (int j = 0; j <= k; ++j) {
        if (dp[j].second < a[i]) {
          if (dp[j ^ a[i]].first == 0) {
            dp[j ^ a[i]].first = 1;
            dp[j ^ a[i]].second = a[i];
          } else {
            dp[j ^ a[i]].second = min(dp[j ^ a[i]].second, a[i]);
          }
        }
      }
    }
    long long d = 0;
    for (int i = 0; i < 513; ++i) {
      if (dp[i].first) {
        ++d;
      }
    }
    cout << d << '\n';
    for (int i = 0; i < 513; ++i) {
      if (dp[i].first) {
        cout << i << " ";
      }
    }
  }
}
