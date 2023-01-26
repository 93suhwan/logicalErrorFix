#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;
int main() {
  ll z;
  cin >> z;
  while (z--) {
    ll l, r, ans, a, b;
    cin >> l >> r;
    if (r - l < l)
      ans = r % l;
    else {
      r++;
      ans = r / 2;
      ans--;
    }
    cout << ans << endl;
  }
}
