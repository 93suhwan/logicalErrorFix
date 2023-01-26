#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long qpow(long long n, long long k) {
  long long ans = 1;
  while (k) {
    if (k & 1) ans = ((ans % mod) * (n % mod)) % mod;
    n = ((n % mod) * (n % mod)) % mod;
    k >>= 1;
  }
  return ans;
}
int a[13];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    k++;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < (n - 1); i++) {
      int cha = a[i + 1] - a[i];
      long long temp = 0;
      for (int j = 0; j < cha; j++) {
        temp *= 10;
        temp += 9;
      }
      long long base = 1;
      for (int j = 0; j < a[i]; j++) base *= 10;
      if (k <= temp) {
        ans += k * base;
        k = 0;
        break;
      } else {
        ans += temp * base;
        k -= temp;
      }
    }
    long long base = 1;
    for (int i = 0; i < a[n - 1]; i++) base *= 10;
    if (k >= 0) ans += k * base;
    cout << ans << endl;
  }
  return 0;
}
