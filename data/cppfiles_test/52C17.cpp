#include <bits/stdc++.h>
using namespace std;
long long fact[(int)1000002];
long long infac[(int)1000002];
long long bin_pow(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a % (long long)1000000007;
  if (b % 2 == 0) {
    long long temp = bin_pow(a, b / 2);
    return (temp * temp) % (long long)1000000007;
  } else {
    return ((a % (long long)1000000007) * bin_pow(a, b - 1)) %
           (long long)1000000007;
  }
}
long long mul(long long a, long long b) {
  return ((a % (long long)1000000007) * (b % (long long)1000000007)) %
         (long long)1000000007;
}
void pre() {
  fact[0] = 1;
  for (long long i = 1; i < (int)1000002; i += 1)
    fact[i] = (i * fact[i - 1]) % (long long)1000000007;
  infac[(int)1000002 - 1] =
      bin_pow(fact[(int)1000002 - 1], (long long)1000000007 - 2);
  for (long long i = (int)1000002 - 1; i > 0; i -= 1)
    infac[i - 1] = (i * infac[i]) % (long long)1000000007;
}
long long nCr(long long n, long long r) {
  long long res = fact[n];
  res = (res * infac[n - r]) % (long long)1000000007;
  res = (res * infac[r]) % (long long)1000000007;
  return res;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  long long ans = 1;
  while (ans * 2 <= k) ans *= 2;
  long long idx;
  for (long long i = 63; i >= 0; i -= 1) {
    if ((ans & (1ll << i))) {
      idx = i;
      break;
    }
  }
  if (ans == k) {
    long long z = idx;
    long long res = bin_pow(n, z);
    cout << res << "\n";
  } else {
    k -= ans;
    long long res = bin_pow(n, idx);
    for (long long i = 63; i >= 0; i -= 1) {
      if ((k & (1ll << i))) {
        res += bin_pow(n, i);
      }
      res %= (long long)1000000007;
    }
    cout << res << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
