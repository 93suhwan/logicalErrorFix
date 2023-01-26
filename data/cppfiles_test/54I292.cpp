#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long tot = binpow(2, n * k, (long long)1000000007);
    for (int i = 0; i < k; i++) {
      if (n % 2) {
        long long g = binpow(2, n - 1, (long long)1000000007);
        tot = (tot -
               (((g - 1) * binpow(g, i, (long long)1000000007)) %
                (long long)1000000007 *
                binpow(2, k - i - 1, (long long)1000000007)) %
                   (long long)1000000007 +
               (long long)1000000007) %
              (long long)1000000007;
      } else {
        long long g = binpow(2, n - 1, (long long)1000000007);
        tot = (tot -
               (((g)*binpow(g - 1, i, (long long)1000000007)) %
                (long long)1000000007 *
                binpow(2, k - i - 1, (long long)1000000007)) %
                   (long long)1000000007 +
               (long long)1000000007) %
              (long long)1000000007;
      }
    }
    cout << tot << "\n";
  }
  return 0;
}
