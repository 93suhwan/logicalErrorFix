#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
void solve() {
  long long k;
  cin >> k;
  if (k == 1) {
    cout << 6 << endl;
    return;
  }
  long long need = (1LL << k) - 2;
  long long ans = binpow(4, need, 1000000007) % 1000000007;
  ans *= 6;
  ans %= 1000000007;
  cout << (ans % 1000000007) << endl;
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
}
