#include <bits/stdc++.h>
using namespace std;
void IOS() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1e18;
ll powe(ll a, ll b, ll mod = MOD) {
  b %= (mod - 1);
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
int32_t main() {
  IOS();
  ll tt = 1;
  cin >> tt;
  while (tt--) {
    ll n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    ll ans = 0;
    char la = '#', lb = '#';
    for (ll i = 0; i < n; i++) {
      if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
        ans += 2;
        if (la == '0' && lb == '0') ans++;
        la = lb = '#';
      } else if (a[i] == '1' && b[i] == '1') {
        if (la == '0' && lb == '0')
          ans += 2, la = lb = '#';
        else
          la = lb = '1';
      } else {
        if (la == '1' && lb == '1')
          ans += 2, la = lb = '#';
        else if (la == '0' && lb == '0')
          ans++;
        else
          la = lb = '0';
      }
    }
    if (la == '0' && lb == '0') ans++;
    cout << ans << '\n';
  }
  return 0;
}
