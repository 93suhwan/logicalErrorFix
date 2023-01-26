#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int power(int a, int b) {
  int r = !!a;
  for (; b > 0; b >>= 1, a = (long long)a * a % mod) {
    if (b & 1) {
      r = (long long)r * a % mod;
    }
  }
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int S = 3 * (n + 1);
  vector<int> fac(S + 1), ifac(S + 1);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= S; i++) {
    fac[i] = (long long)fac[i - 1] * i % mod;
  }
  ifac[S] = power(fac[S], mod - 2);
  for (int i = S - 1; i > 0; i--) {
    ifac[i] = (long long)ifac[i + 1] * (i + 1) % mod;
  }
  auto C = [&](int n, int m) {
    if (n < m || m < 0) {
      return 0ll;
    }
    return (long long)fac[n] * ifac[m] % mod * ifac[n - m] % mod;
  };
  const int inv3 = power(3, mod - 2);
  vector<int> ans(3 * n + 1);
  for (int i = 0; i <= 3 * n; i++) {
    ans[i] = C(3 * (n + 1), i + 1);
    if (i < 3) {
      ans[i] -= C(3, i + 1);
      if (ans[i] < 0) ans[i] += mod;
    }
    ans[i] = (long long)ans[i] * inv3 % mod;
    if (i >= 1) {
      ans[i] -= ans[i - 1];
      if (ans[i] < 0) ans[i] += mod;
    }
    if (i >= 2) {
      ans[i] = (ans[i] - (long long)inv3 * ans[i - 2]) % mod;
      if (ans[i] < 0) ans[i] += mod;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << '\n';
  }
  return 0;
}
