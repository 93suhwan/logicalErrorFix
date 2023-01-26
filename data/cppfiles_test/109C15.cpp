#include <bits/stdc++.h>
const int mod = 998244353;
int mul(int a, int b) { return 1ll * a * b % mod; }
void norm(int &x) {
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
}
void sol() {
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  std::vector<int> fac(n + 1 << 1, 1), ifac(n + 1 << 1, 1), inv(n + 1 << 1, 1);
  for (int i = 2; i <= n << 1; ++i) {
    fac[i] = mul(fac[i - 1], i);
    inv[i] = mul(inv[mod % i], mod - mod / i);
    ifac[i] = mul(ifac[i - 1], inv[i]);
  }
  auto C = [&](int n, int m) {
    if (n < 0 || n < m || m < 0)
      return 0;
    else
      return mul(fac[n], mul(ifac[m], ifac[n - m]));
  };
  bool hasBB = false, allBW = true, allWB = true;
  int BWWB = 1;
  int cntB = 0, cntW = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
    for (char e : s[i]) {
      if (e == 'B')
        ++cntB;
      else if (e == 'W')
        ++cntW;
    }
    if (s[i][0] == s[i][1] && s[i][0] != '?') {
      hasBB = true;
      allWB = allBW = false;
      BWWB = 0;
    } else if (s[i] == "??") {
      norm(BWWB <<= 1);
    } else if (s[i][0] == 'B' || s[i][1] == 'W') {
      allWB = false;
    } else if (s[i][0] == 'W' || s[i][1] == 'B') {
      allBW = false;
    }
  }
  int res = 0;
  res = C(2 * n - cntB - cntW, n - cntB);
  norm(res += mod - BWWB);
  norm(res += allBW + allWB);
  std::cout << res;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  sol();
  return 0;
}
