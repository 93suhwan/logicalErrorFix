#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
const long long mod = 1e9 + 7;
long long qmi(long long a, long long k, long long p) {
  long long res = 1 % p;
  while (k) {
    if (k & 1) res = (long long)res * a % p;
    a = (long long)a * a % p;
    k >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    long long res = 1;
    for (long long i = 1; i <= n * 2; i++) {
      res = ((res % mod * i % mod)) % mod;
    }
    res = res * qmi(2, mod - 2, mod);
    cout << res % mod << endl;
  }
}
