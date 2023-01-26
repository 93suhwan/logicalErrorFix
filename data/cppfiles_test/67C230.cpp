#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
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
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long a, b, c, sep, tot;
    cin >> a >> b >> c;
    sep = abs(a - b);
    tot = 2 * (sep - 1) + 2;
    if (a > tot || b > tot || c > tot) {
      cout << -1 << '\n';
      continue;
    }
    cout << (c + sep - 1) % tot + 1 << '\n';
  }
}
