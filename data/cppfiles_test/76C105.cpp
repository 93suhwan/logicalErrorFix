#include <bits/stdc++.h>
const int INF = 1e9;
const long long BIGINF = 2e18;
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  long long m;
  cin >> n >> m;
  vector<long long> add(n + 1, 0);
  vector<long long> dp(n + 1);
  dp[1] = 1;
  for (int j = 2; j <= n; j++) {
    add[j] += dp[1];
    add[j] = (add[j] + m) % m;
    if (j + j <= n) {
      add[j + j] -= dp[1];
      add[j + j] = (add[j + j] + m) % m;
    }
  }
  long long add_v = 1;
  for (int i = 2; i <= n; i++) {
    add_v += add[i];
    add_v = (add_v + m) % m;
    dp[i] = add_v;
    for (int j = 2; i * j <= n; j++) {
      add[i * j] += dp[i];
      add[i * j] = (add[i * j] + m) % m;
      if (i * j + j <= n) {
        add[i * j + j] -= dp[i];
        add[i * j + j] = (add[i * j + j] + m) % m;
      }
    }
    add_v += dp[i];
    add_v %= m;
  }
  cout << dp[n];
  return 0;
}
