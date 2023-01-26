#include <bits/stdc++.h>
using namespace std;
vector<int> conn[1000005];
bool vi[1000005];
void init(int k) {
  for (int i = 0; i <= k; i++) {
    vi[i] = false;
    conn[i].clear();
  }
}
bool isprime(int k) {
  for (int i = 2; i <= sqrt(k); i++)
    if (k % i == 0) return false;
  return true;
}
int bm(int a, int b, int mod) {
  if (b == 0) return 1;
  int t = bm(a, b / 2, mod);
  t = t * t % mod;
  return (b % 2 == 1 ? t * a % mod : t);
}
int inv(int a, int mod) { return bm(a, mod - 2, mod); }
void solve() {
  long long n, mod;
  cin >> n >> mod;
  int dp[n + 5];
  dp[0] = 0;
  dp[1] = 1;
  int sum = 1;
  int idk[n + 5];
  int add[n + 5];
  for (int i = 2; i <= n; i++) dp[i] = 0;
  for (int i = 0; i <= n; i++) idk[i] = 0;
  for (int i = 2; i <= n; i++) add[i] = 1;
  for (int i = 2; i <= n; i++) {
    sum += add[i];
    sum %= mod;
    dp[i] += sum;
    dp[i] %= mod;
    sum = (sum + dp[i]) % mod;
    for (int j = 2; j * i <= n; j++) {
      add[j * i] = (add[j * i] + (dp[i] - dp[i - 1] + mod)) % mod;
    }
  }
  dp[n] %= mod;
  if (dp[n] < 0) dp[n] += mod;
  cout << dp[n] % mod << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
