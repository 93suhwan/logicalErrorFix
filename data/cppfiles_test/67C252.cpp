#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long double PI = 4 * atan((long double)1);
const long long MOD = 1000000007;
long long nCr(long long n, long long k) {
  long long res = 1;
  if (k > n - k) k = n - k;
  for (long long i = 0; i < k; i++) res *= (n - i), res /= (i + 1);
  return res;
}
long long expo(long long a, long long b, long long M = MOD) {
  long long res = 1;
  while (b) {
    if (b % 2 == 1) res = res * a % M;
    b = b / 2;
    a = a * a % M;
  }
  return (res + M) % M;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long x = min(a, b);
    long long y = max(a, b);
    long long n = 2 * (y - x);
    if (a > n || b > n || c > n)
      cout << -1 << endl;
    else {
      if (c + n / 2 > n)
        cout << (c - n / 2) << endl;
      else
        cout << (c + n / 2) << endl;
    }
  }
  return 0;
}
