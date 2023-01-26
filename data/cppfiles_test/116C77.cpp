#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse-lm")
using namespace std;
const int N = 5e5 + 10;
int a[N];
int n;
long long pw[N];
int main() {
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * 2ll % 998244353;
  int _;
  scanf("%d", &_);
  while (_--) {
    scanf("%d", &n);
    vector<long long> mp(n + 10, 0), cnt(n + 10, 0), dp(n + 10, 0);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mp[a[i]]++;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      cnt[a[i]]++;
      long long t = dp[a[i]] + (a[i] ? dp[a[i] - 1] : 1);
      ans = (ans + t) % 998244353;
      if (a[i] >= 2)
        ans = (ans +
               dp[a[i] - 2] *
                   pw[mp[a[i]] - cnt[a[i]] + mp[a[i] - 2] - cnt[a[i] - 2]]) %
              998244353;
      dp[a[i]] = (dp[a[i]] + t) % 998244353;
    }
    cout << (ans + pw[mp[1]] - 1) % 998244353 << '\n';
  }
  return 0;
}
