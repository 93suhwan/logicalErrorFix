#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
long long power(long long x, long long y) {
  if (y == 0) return 1ll;
  if (y == 1) return x % mod;
  long long r = power(x % mod, y / 2) % mod;
  if (y % 2 == 0) {
    return ((r % mod) * (r % mod)) % mod;
  } else {
    return ((((r % mod) * (r % mod)) % mod) * (x % mod)) % mod;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long k;
  cin >> k;
  long long ans = (power(2 % mod, (k) % mod) % mod) - 1;
  ans %= mod;
  ans = (power(4 % mod, (ans - 1) % mod) % mod) * 6;
  cout << ans % mod << "\n";
  return 0;
}
