#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int mod = 998244353;
int n;
int a[N], dp[N];
stack<pair<int, pair<int, int> > > s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  dp[0] = 1;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int sum = 1ll * a[i] * dp[i - 1] % mod;
    int tmp = dp[i - 1];
    res = (res + sum) % mod;
    while (!s.empty() && s.top().first > a[i]) {
      sum = (sum + 1ll * s.top().second.first * a[i] % mod) % mod;
      res = (res - s.top().second.second + mod) % mod;
      res = (res + 1ll * s.top().second.first * a[i] % mod) % mod;
      tmp = (tmp + s.top().second.first) % mod;
      s.pop();
    }
    s.push(make_pair(a[i], make_pair(tmp, sum)));
    dp[i] = (mod - res) % mod;
  }
  int ans = dp[n];
  if (n & 1) ans = (mod - ans) % mod;
  cout << ans << endl;
  return 0;
}
