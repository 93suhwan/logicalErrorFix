#include <bits/stdc++.h>
using namespace std;
long long powermod(long long x, long long y, long long p) {
  long long res = 1;
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
  long long int mod = 1000000007;
  int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int ans = 0;
    if (ceil(log2(k)) == floor(log2(k))) {
      ans = pow(n, log2(k));
    } else {
      if (k == 1) {
        ans = 1;
      } else if (k == 2) {
        ans = n;
      } else if (k == 3) {
        ans = 1 + n;
      } else {
        while (k > 1) {
          long long int temp = floor(log2(k));
          ans = ans + powermod(n, temp, mod);
          k = k - pow(2, temp);
        }
      }
    }
    cout << ans % mod << endl;
  }
  return 0;
}
