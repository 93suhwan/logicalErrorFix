#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int maxn = 1e5 + 5;
const long long mod = 998244353;
long long a[maxn];
int n;
long long dp[maxn][2];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < maxn; i++) dp[i][0] = dp[i][1] = 0;
  int now = 0;
  dp[a[n]][now] = 1;
  long long ans = 0;
  for (long long i = n - 1; i >= 1; i--, now ^= 1) {
    for (long long j = 1; j <= a[i + 1];) {
      long long maxsize = a[i + 1] / j;
      long long w = dp[maxsize][now];
      long long k = (a[i] + maxsize - 1) / maxsize;
      ans = (ans + i * w % mod * (k - 1) % mod) % mod;
      dp[a[i] / k][now ^ 1] += w;
      dp[maxsize][now] = 0;
      j = a[i + 1] / maxsize + 1;
    }
    dp[a[i]][now ^ 1]++;
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
