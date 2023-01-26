#include <bits/stdc++.h>
using namespace std;
int64_t mod = 1e9 + 7;
int64_t log2(int64_t x, int64_t base) { return log(x) / log(base); }
int64_t bin_pow(int64_t base, int64_t pow) {
  if (pow == 0) {
    return 1;
  }
  if (pow == 1) {
    return base;
  }
  int64_t res = bin_pow(base, pow / 2);
  res %= mod;
  res *= res;
  res %= mod;
  if (pow % 2 != 0) {
    res *= base;
    res %= mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n, k;
    cin >> n >> k;
    int64_t res = 0;
    while (k > 0) {
      int64_t n2p = log2(k, 2);
      res += bin_pow(n, n2p);
      res %= mod;
      k -= pow(2, n2p);
    }
    cout << res << "\n";
  }
}
