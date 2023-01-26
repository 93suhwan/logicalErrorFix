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
      int lt = l;
      ll t1 = 1;
      while (lt--) {
        t1 *= n;
        t1 = t1 % M;
      }
      ans += t1;
      ans = ans % M;
      ll pw2 = pow(2, l);
      r = r - pw2;
    }
    cout << ans << endl;
  }
  return 0;
}
