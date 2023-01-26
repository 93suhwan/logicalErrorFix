#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
long long add(long long a, long long b) {
  a = a % MOD;
  b = b % MOD;
  return (a + b) % MOD;
}
long long sub(long long a, long long b) {
  a = a % MOD;
  b = b % MOD;
  return (a - b + MOD) % MOD;
}
long long mul(long long a, long long b) {
  a = a % MOD;
  b = b % MOD;
  return ((a * b) % MOD + MOD) % MOD;
}
long long mod_pow(long long n, long long x) {
  int res = 1;
  while (x > 0) {
    if (x % 2 == 1) res = (res * n) % MOD;
    n = (n * n) % MOD;
    x /= 2;
  }
  return res;
}
int digits(long long n) {
  int cnt = 0;
  while (n > 0) {
    cnt++;
    n /= 10;
  }
  return cnt;
}
void solve() {
  long long n;
  cin >> n;
  int d = digits(n);
  long long dp[20][3];
  int digitArr[d + 1];
  long long N = n;
  for (int i = 1; i <= d; i++) {
    digitArr[i] = N % 10;
    N /= 10;
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 3; j++) dp[i][j] = 0;
  }
  dp[1][0] = dp[2][0] = 1;
  for (int i = 1; i <= d; i++) {
    for (int j = 0; j < 3; j++) {
      for (int x = 0; x <= 9; x++) {
        for (int y = 0; y <= 9; y++) {
          if ((x + y + j) % 10 == digitArr[i]) {
            dp[i + 2][(x + y + j) / 10] += dp[i][j];
          }
        }
      }
    }
  }
  cout << dp[d + 1][0] * dp[d + 2][0] - 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
