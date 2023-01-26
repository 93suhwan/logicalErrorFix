#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
const long long mod = 998244353;
long long dp[maxn], sum[maxn], s[maxn], st[maxn], a[maxn], n;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  long long ans = 0, top = 0;
  dp[0] = sum[0] = 1;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    while (top && a[st[top]] > a[i]) ans -= s[top--];
    long long gg = sum[i - 1] * a[i];
    if (st[top]) gg -= (sum[st[top] - 1] * a[i]);
    gg %= mod;
    (ans += gg) %= mod;
    st[++top] = i;
    s[top] = gg;
    dp[i] = ans;
    if (!(i & 1)) dp[i] *= -1ll;
    sum[i] = sum[i - 1];
    if (i & 1)
      (sum[i] -= dp[i]) %= mod;
    else
      (sum[i] += dp[i]) %= mod;
  }
  cout << (dp[n] + mod * mod) % mod;
}
