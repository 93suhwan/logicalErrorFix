#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
template <typename T, typename U>
inline istream& operator>>(istream& in, pair<T, U>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
inline istream& operator>>(istream& in, vector<T>& v) {
  for (T& x : v) in >> x;
  return in;
}
const ll MOD = 1e9 + 7;
inline ll md(ll x, const ll& M = MOD) {
  x %= M;
  return ((x < 0) ? (x + M) : x);
}
ll pw(ll x, ll y, const ll& M = MOD) {
  if (y < 0) {
    x = pw(x, -y, M);
    return pw(x, M - 2, M);
  }
  ll res = 1;
  x = md(x, M);
  while (y > 0) {
    if (y & 1) {
      res = md(res * x, M);
    }
    x = md(x * x, M);
    y >>= 1;
  }
  return md(res, M);
}
void solve(ll& tc) {
  ll n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 1 << '\n';
    return;
  }
  ll dp[k + 2][2];
  memset(dp, 0, sizeof(dp));
  dp[1][0] = md(pw(2, n - 1) - (n % 2 == 0) + (n % 2 == 1));
  dp[1][1] = (n % 2 == 0);
  for (ll i = 2; i <= k; i++) {
    if (n & 1) {
      dp[i][0] = md(dp[i - 1][0] * md(pw(2, n - 1) + 1));
      dp[i][1] = 0;
    } else {
      dp[i][0] = md(dp[i - 1][0] * md(pw(2, n - 1) - 1));
      dp[i][1] = md(md(dp[i - 1][1] * pw(2, n)) + md(dp[i - 1][0] * 1));
    }
  }
  ll ans = md(dp[k][0] + dp[k][1]);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll rep = 1;
  while (rep--) {
    ll tc = 1;
    cin >> tc;
    for (ll i = 1; i <= tc; i++) {
      if (0) cerr << "Case #" << i << "\n";
      solve(i);
    }
    if (1) break;
  }
  return 0;
}
