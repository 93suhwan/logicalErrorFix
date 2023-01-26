#include <bits/stdc++.h>
using namespace std;
long long rem = 1000000007;
long long binaryexpo(long long x, long long n, long long m) {
  long long res = 1;
  while (n != 0) {
    if (n % 2 == 1) {
      res = ((res % m) * (x % m)) % m;
    }
    x = ((x % m) * (x % m)) % m;
    n /= 2;
  }
  return res;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long temp = log2(k);
    long long terms = pow(2, temp);
    if (k == terms) {
      long long var = binaryexpo(n, temp, rem);
      cout << var << "\n";
    } else {
      long long left = k - terms;
      long long ans = binaryexpo(n, temp, rem);
      while (left > 0) {
        long long go = log2(left);
        long long ter = pow(2, go);
        left -= ter;
        long long ad = binaryexpo(n, go, rem);
        ans = (ans + ad) % rem;
      }
      cout << ans << "\n";
    }
  }
}
