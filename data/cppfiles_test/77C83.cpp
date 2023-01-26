#include <bits/stdc++.h>
using namespace std;
const long long int N = 200043;
long long int MOD = 1000000007;
long long int add(long long int x, long long int y) {
  x = ((x % MOD) + (y % MOD)) % MOD;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
long long int mul(long long int x, long long int y) {
  return ((x % MOD) * (y % MOD)) % MOD;
}
long long int binpow(long long int x, long long int y) {
  long long int z = 1;
  while (y) {
    if (y & 1) z = mul(z, x);
    x = mul(x, x);
    y >>= 1;
  }
  return z;
}
long long int inv(long long int x) { return binpow(x, MOD - 2); }
long long int divide(long long int x, long long int y) {
  return mul(x, inv(y));
}
long long int ar[4000005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, i, j;
  t = 1;
  while (t--) {
    long long int n;
    cin >> n >> MOD;
    if (n == 1)
      cout << 1 << endl;
    else if (n == 2)
      cout << 2 % MOD << endl;
    if (n <= 2) continue;
    ar[n] = 1;
    ar[n - 1] = 1;
    ar[n - 1] = add(ar[n - 1], ar[n]);
    long long int cur = 2;
    for (i = n - 2; i >= 1; i--) {
      ar[i] = add(ar[i], cur);
      for (j = 2 * i; j <= n; j += i) {
        long long int k = j / i;
        ar[i] = add(ar[i], add(ar[j], -ar[min(j + k, n + 1)]));
      }
      cur = add(cur, ar[i]);
      ar[i] = add(ar[i], ar[i + 1]);
    }
    cout << add(ar[1], -ar[2]) << endl;
  }
}
