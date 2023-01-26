#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
long long BinPow(int x, int power) {
  if (power == 0) {
    return 1;
  } else if (power == 1) {
    return x % MOD;
  } else {
    long long s = BinPow(x, power / 2);
    if (power % 2) {
      return (s * s % MOD) * x % MOD;
    }
    return s * s % MOD;
  }
}
void Solve() {
  int n = 0, k = 0;
  std::cin >> n >> k;
  std::vector<long long> pow(n + k + 1);
  pow[0] = 1;
  for (int i = 1; i < pow.size(); ++i) {
    pow[i] = pow[i - 1] * 2 % MOD;
  }
  long long ans = 0;
  if (n % 2 == 0) {
    for (int i = 0; i < k; ++i) {
      ans += BinPow(pow[n - 1] - 1, k - 1 - i) * BinPow(pow[n], i) % MOD;
      ans %= MOD;
    }
    ans += BinPow(pow[n - 1] - 1, k);
    ans %= MOD;
  } else {
    ans = BinPow(pow[n - 1] + 1, k);
  }
  std::cout << ans << '\n';
}
int main() {
  int t = 0;
  std::cin >> t;
  while (t--) {
    Solve();
  }
}
