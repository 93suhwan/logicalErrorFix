#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vl = vector<ll>;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 998244353;
int n;
ll a[500005];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  vl dp(n + 5, 0), dp2(n + 5, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    (dp[a[i] + 1] *= 2) %= MOD;
    (dp[a[i] + 1] += dp[a[i]]) %= MOD;
    if (a[i] > 0) {
      (dp2[a[i] - 1] *= 2) %= MOD;
      (dp2[a[i] - 1] += dp[a[i]]) %= MOD;
    }
  }
  ll ans = 0;
  for (auto& l : dp) (ans += l) %= MOD;
  for (auto& l : dp2) (ans += l) %= MOD;
  cout << (ans - 1 + MOD) % MOD << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
