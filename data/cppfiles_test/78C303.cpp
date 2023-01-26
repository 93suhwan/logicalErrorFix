#include <bits/stdc++.h>
using namespace std;
const long long maxn = 4e5 + 10;
const long long mod = 998244353;
long long k, A, h;
long long qpow(long long x, long long n) {
  long long tmp = x % mod;
  long long a = 1;
  while (n) {
    if (n % 2) a = (a * tmp) % mod;
    n = n / 2;
    tmp = (tmp * tmp) % mod;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    long long a, b;
    cin >> a >> b;
    if (a <= (b - 1) / 2)
      cout << (b - 1) / 2 << "\n";
    else
      cout << min(b - a, (b - 1) / 2) << "\n";
  }
}
