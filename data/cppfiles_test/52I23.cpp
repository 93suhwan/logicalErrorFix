#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return x * temp * temp;
    else
      return (temp * temp) / x;
  }
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
        ans = (ans + power(n, ctr) % MOD) % MOD;
      } else {
      }
      ctr++;
      k /= 2;
    }
    cout << ans % MOD << endl;
  }
}
