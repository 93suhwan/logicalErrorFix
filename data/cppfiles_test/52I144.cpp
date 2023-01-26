#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long long M = 1e9 + 7;
int main() {
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll r = k;
    ll ans = 0;
    while (r > 0) {
      int l = log2(r);
      ll pwr = pow(n, l);
      ans += pwr;
      ans = ans % M;
      r = r - pow(2, l);
    }
    cout << ans << endl;
  }
  return 0;
}
