#include <bits/stdc++.h>
using namespace std;
int bin_pow(int a, long long n, int mod) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    int b = bin_pow(a, n / 2, mod);
    return (long long)b * b % mod;
  } else {
    return (long long)bin_pow(a, n - 1, mod) * a % mod;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long k;
  cin >> k;
  int mod = 1e9 + 7;
  int ans = 6;
  ans = (long long)ans * bin_pow(4, (1LL << k) - 2, mod) % mod;
  cout << ans << '\n';
}
