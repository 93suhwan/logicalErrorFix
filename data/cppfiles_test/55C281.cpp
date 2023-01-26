#include <bits/stdc++.h>
using namespace std;
long long powerMod(long long x, long long y, long long p) {
  long long res = 1 % p;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n = 1, k, m;
  cin >> k;
  while (k--) n *= 2;
  n -= 2;
  m = powerMod(4, n, 1000000007);
  m = (m * 6ll) % 1000000007;
  cout << m << "\n";
  return 0;
}
