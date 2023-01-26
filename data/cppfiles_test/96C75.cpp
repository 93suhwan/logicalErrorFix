#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
int N, X;
long long dp[510][510], fact[510], inv[510], ifact[510];
const long long MOD = 998244353;
long long binpow(int base, int power) {
  if (power < 0) return 0;
  if (power == 0) return 1;
  long long ret = 1;
  long long mult = base;
  while (power > 0) {
    if (power % 2 == 1) {
      ret *= mult;
      ret %= MOD;
    }
    mult *= mult;
    mult %= MOD;
    power /= 2;
  }
  return ret;
}
void calc() {
  fact[0] = 1;
  for (int i = 1; i <= 500; i++) fact[i] = fact[i - 1] * i % MOD;
  inv[1] = 1;
  for (int i = 2; i <= 500; i++) {
    inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    inv[i] %= MOD;
  }
  ifact[0] = 1;
  for (int i = 1; i <= 500; i++) {
    ifact[i] = ifact[i - 1] * inv[i] % MOD;
  }
}
long long C(int a, int b) {
  return fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
}
int main() {
  fastIO();
  calc();
  cin >> N >> X;
  for (int i = 1; i < N; i++) {
    for (int j = i + 1; j <= N; j++) {
      for (int k = 1; k <= j; k++) {
        dp[i][j] += C(j, k) * binpow(i - 1, j - k) % MOD;
        dp[i][j] %= MOD;
      }
    }
  }
  for (int i = 1; i <= X; i++) {
    for (int j = 1; j <= i; j++) {
      for (int k = 1; k <= j; k++) {
        dp[i][j] += dp[i - j + 1][k] * binpow(j - 1, j - k) % MOD * C(j, k);
        dp[i][j] %= MOD;
      }
    }
  }
  long long ret = 0;
  for (int i = 1; i <= X; i++) {
    ret += dp[i][N];
    ret %= MOD;
  }
  cout << ret << "\n";
}
