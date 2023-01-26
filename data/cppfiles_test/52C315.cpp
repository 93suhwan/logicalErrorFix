#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
const long long MOD = 1000000007;
long long add(long long x, long long y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
long long sub(long long x, long long y) { return add(x, MOD - y); }
long long mul(long long x, long long y) { return (x * 1ll * y) % MOD; }
long long binpow(long long x, long long y) {
  long long z = 1;
  while (y > 0) {
    if (y % 2 == 1) z = mul(z, x);
    x = mul(x, x);
    y /= 2;
  }
  return z;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long ttt;
  cin >> ttt;
  for (long long T = 1; T <= ttt; T++) {
    long long n, k;
    cin >> n >> k;
    long long res = 0;
    for (long long i = 0; i < 35; i++) {
      if (k & (1ll << i)) {
        res = add(res, binpow(n, i));
      }
    }
    cout << res << '\n';
  }
  return 0;
}
