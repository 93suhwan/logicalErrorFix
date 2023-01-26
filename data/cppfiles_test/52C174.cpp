#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int MOD = 1e9 + 7;
    long long int ans = 0;
    long long int ctr = 0;
    while (k != 0) {
      if (k % 2 == 1) {
        ans = (ans + power(n, ctr, MOD) % MOD) % MOD;
      } else {
      }
      ctr++;
      k /= 2;
    }
    cout << ans % MOD << endl;
  }
}
