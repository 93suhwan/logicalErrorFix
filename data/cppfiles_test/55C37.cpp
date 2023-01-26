#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long binexp(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  long long ans = 6ll;
  long long nodes = (1ll << k) - 2ll;
  ans = (ans * binexp(4, nodes)) % mod;
  cout << ans << "\n";
  return 0;
}
