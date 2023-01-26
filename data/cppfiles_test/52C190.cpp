#include <bits/stdc++.h>
using namespace std;
void fun() {}
long long int __gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
long long int poww(long long int a, long long int b, long long int md) {
  if (b < 0) return 0;
  if (a == 0) return 0;
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = (1ll * res * a) % md;
    }
    a = (1ll * a * a) % md;
    b >>= 1;
  }
  return res;
}
long long int divide(long long int a, long long int b, long long int md) {
  long long int rr = a * (poww(b, md - 2, md));
  rr %= md;
  return rr;
}
const long long int siz = 2e5 + 5;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  fun();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k, ans = 0;
    cin >> n >> k;
    long long int md = 1e9 + 7;
    for (long long int i = 0; i < 32; i++) {
      if (k & (1 << i)) {
        ans = (ans + poww(n, i, md)) % md;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
