#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 998244353, inf = 1e18;
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
}
vl fact(2e5 + 5, 1);
ll binPow(ll a, ll b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  ll ret = binPow(a, b / 2);
  if (b % 2 == 0) return (ret * ret) % mod;
  return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a) { return (binPow(a, mod - 2) % mod + mod) % mod; }
ll binom(ll a, ll b) {
  if (b < 0 or a < 0) return 0;
  return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) %
         mod;
}
int main() {
  setIO();
  int t;
  cin >> t;
  for (int i = 1; i <= 2e5; i++) fact[i] = (i * fact[i - 1]) % mod;
  while (t--) {
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    if (a[n] == a[n - 1]) {
      cout << fact[n] << '\n';
      continue;
    }
    if (a[n] > a[n - 1] + 1) {
      cout << 0 << '\n';
      continue;
    }
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == a[n - 1]) cnt++;
    }
    ll ans = ((fact[n] - ((fact[n - cnt - 1] * fact[cnt]) % mod *
                          binom(n, cnt + 1) % mod)) %
                  mod +
              mod) %
             mod;
    cout << ans << '\n';
  }
  return 0;
}
