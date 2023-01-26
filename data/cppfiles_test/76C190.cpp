#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, mod;
long long dp[200005], pre[200005];
int main() {
  cin >> n >> mod;
  dp[1] = pre[1] = 1;
  for (int i = 2; i <= n; i++) {
    int x = pre[i - 1] % mod;
    for (int l = 2, r; l <= i; l = r + 1) {
      r = i / (i / l);
      x += dp[i / l] * (r - l + 1) % mod;
      x %= mod;
    }
    dp[i] = x;
    pre[i] = (pre[i - 1] + dp[i]) % mod;
  }
  cout << dp[n] % mod << endl;
}
