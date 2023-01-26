#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int mod = 998244353;
long long int dp[2][MAXN];
vector<int> V[2];
int a[MAXN];
int main() {
  std::ios::sync_with_stdio(false);
  int _;
  cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    V[n & 1].push_back(a[n]);
    dp[n & 1][a[n]] = 1;
    long long int ans = 0;
    for (int i = n - 1; i >= 1; i--) {
      int id = i & 1;
      dp[id][a[i]] = 1;
      V[id].push_back(a[i]);
      for (auto it : V[id ^ 1]) {
        if (it >= a[i]) {
          dp[id][a[i]] += dp[id ^ 1][it];
          if (V[id].size() == 0 || V[id][V[id].size() - 1] != a[i])
            V[id].push_back(a[i]);
        } else {
          int p = (a[i] + it - 1) / it;
          dp[id][a[i] / p] += dp[id ^ 1][it];
          ans +=
              1ll * ((a[i] + it - 1) / it - 1) * dp[id ^ 1][it] % mod * i % mod;
          ans %= mod;
          if (V[id].size() == 0 || V[id][V[id].size() - 1] != a[i] / p)
            V[id].push_back((a[i] / p));
        }
      }
      for (auto it : V[id ^ 1]) {
        dp[id ^ 1][it] = 0;
      }
      V[id ^ 1].clear();
    }
    for (auto it : V[0]) dp[0][it] = 0;
    for (auto it : V[1]) dp[1][it] = 0;
    V[0].clear();
    V[1].clear();
    cout << ans << '\n';
  }
}
