#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x, n;
    cin >> x >> n;
    ll s = x % 2 ? -1 : +1;
    ll ans = n == 0       ? 0
             : n % 4 == 0 ? x
             : n % 4 == 1 ? -s * (1 + (n / 4) * 4)
             : n % 4 == 2 ? s
                          : s * ((n / 4 + 1) * 4);
    cout << x + ans << '\n';
  }
}
