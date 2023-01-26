#include <bits/stdc++.h>
const int M = 1e5 + 5;
const int mod = 998244353;
std::vector<std::pair<int, int> > lr;
int mobius[M];
int cnt[M];
int is_composite[M];
std::vector<int> primes;
int solve(std::vector<int> &L, std::vector<int> &R, int m) {
  int n = L.size();
  int sz = 0;
  for (int i = 0; i < n; i++) {
    m -= L[i];
    R[i] -= L[i];
    sz += R[i];
  }
  if (m < 0) {
    return 0;
  }
  sz++;
  std::vector<int> dp(sz, 0);
  dp[0] = 1;
  for (int r : R) {
    std::vector<int> nways(sz, 0);
    for (int i = 0; i < sz; i++) {
      nways[i] += dp[i];
      int e = std::min(sz - 1, i + r);
      nways[e] -= dp[i];
    }
    for (int i = 1; i < sz; i++) {
      nways[i] = (nways[i] + nways[i - 1]) % mod;
    }
    std::swap(dp, nways);
  }
  int ans = 0;
  for (int i = 0; i <= m; i++) {
    ans = (ans + dp[i]) % mod;
  }
  return ans;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  lr.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> lr[i].first >> lr[i].second;
    lr[i].second++;
  }
  std::fill(is_composite, is_composite + m + 1, false);
  std::fill(cnt, cnt + m + 1, 0);
  is_composite[0] = true;
  is_composite[1] = true;
  mobius[0] = 1;
  mobius[1] = 1;
  for (int i = 2; i <= m; i++) {
    if (!is_composite[i]) {
      mobius[i] = -1;
      primes.push_back(i);
      cnt[i] = 1;
    }
    for (int j = 0; j < primes.size() && i * primes[j] <= m; j++) {
      is_composite[i * primes[j]] = true;
      cnt[i * primes[j]] += cnt[i];
      mobius[i * primes[j]] = mobius[primes[j]] * mobius[i];
      if (i % primes[j] == 0) {
        int powp = pow(primes[j], cnt[i]);
        mobius[i * primes[j]] = 0;
        break;
      }
    }
  }
  std::vector<int> L(n);
  std::vector<int> R(n);
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (mobius[i] != 0) {
      for (int j = 0; j < n; j++) {
        L[j] = (lr[j].first + i - 1) / i;
        R[j] = (lr[j].second + i - 1) / i;
      }
      int tmp = solve(L, R, m / i);
      int tmp2 = mobius[i] * tmp;
      ans = (ans + tmp2) % mod;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
