#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 998244353;
ll _inv(ll a, ll m = mod) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
  vector<ll> sum(2);
  vector<stack<pair<int, ll>>> st(2);
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    vector<ll> tmp(2);
    for (int j = 0; j < 2; j++) {
      while (!st[j].empty() && st[j].top().first > a[i]) {
        (sum[j] += mod - st[j].top().second) %= mod;
        (tmp[j] += st[j].top().second * a[i] % mod * _inv(st[j].top().first) %
                   mod) %= mod;
        st[j].pop();
      }
      dp[i + 1][1 - j] = (tmp[j] + sum[j] + dp[i][1 - j] * a[i]) % mod;
      st[j].push({a[i], (tmp[j] + dp[i][1 - j] * a[i]) % mod});
      (sum[j] += st[j].top().second) %= mod;
    }
    swap(st[0], st[1]), swap(sum[0], sum[1]);
  }
  cout << (dp[n][0] - dp[n][1] + mod) % mod << endl;
}
