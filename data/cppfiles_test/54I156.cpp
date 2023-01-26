#include <bits/stdc++.h>
using namespace std;
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
long long fact[N], inv[N], invfact[N];
void factInverse() {
  fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
  for (long long i = 2; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
    invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
  }
}
int add(int a, int b) {
  if ((a += b) >= MOD)
    a -= MOD;
  else if (a < 0)
    a += MOD;
  return a;
}
long long mul(int x, int y) { return (1LL * x * y) % MOD; }
long long nCr(int n, int r) {
  if (r > n) return 0;
  return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}
int mem[N][2], vis[N][2], test_id;
int dp[N][2];
int cntEven, _2pwn, n;
int main() {
  run();
  factInverse();
  int t;
  cin >> t;
  while (t--) {
    test_id++;
    int k;
    cin >> n >> k;
    dp[0][0] = 1;
    dp[0][1] = 1;
    cntEven = 0;
    for (int i = 0; i < n; i += 2) cntEven = add(cntEven, nCr(n, i));
    _2pwn = 1;
    for (int i = 0; i < n; i++) _2pwn = mul(_2pwn, 2);
    for (int i = 1; i <= k; i++) {
      dp[i][0] = _2pwn * dp[i - 1][0] % MOD;
    }
    if (n & 1) {
      for (int i = 1; i <= k; i++) {
        dp[i][1] = (dp[i - 1][1] % MOD * (cntEven + 1) % MOD) % MOD;
      }
    } else {
      for (int i = 1; i <= k; i++) {
        dp[i][1] = (dp[i - 1][1] * (cntEven) % MOD + dp[i - 1][0]) % MOD;
      }
    }
    int ans = (dp[k][1]) % MOD;
    cout << ans << "\n";
  }
}
