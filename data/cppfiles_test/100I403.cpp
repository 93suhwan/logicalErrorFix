#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using t4 = tuple<ll, ll, ll, ll>;
int T;
const int mod = 998244353;
ll fact[220000];
ll invfact[220000];
ll modpow(ll a, ll k) {
  if (k == 0) return 1;
  if (k & 1)
    return modpow(a, k - 1) * a % mod;
  else {
    ll half = modpow(a, k / 2);
    return half * half % mod;
  }
}
ll nCk(ll n, ll k) { return fact[n] * invfact[k] % mod * invfact[n - k] % mod; }
void f() {
  int N;
  cin >> N;
  vector<ll> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  int mx = *max_element(v.begin(), v.end());
  int cnt = 0;
  for (int i = 0; i < N; i++)
    if (mx == v[i]) cnt++;
  if (cnt > 2) {
    cout << fact[N] << '\n';
  } else {
    int mx2 = 0, cnt2 = 0;
    for (int i = 0; i < N; i++) {
      if (v[i] < mx && v[i] > mx2) {
        mx2 = v[i];
        cnt2 = 1;
      } else if (mx2 == v[i])
        cnt2++;
    }
    if (mx2 != mx - 1) {
      cout << 0 << '\n';
      return;
    }
    ll ans = fact[N];
    ll tmp = fact[cnt2] * fact[N - cnt2 - 1] % mod;
    tmp = tmp * nCk(N, N - cnt2 - 1) % mod;
    ans = (ans - tmp + mod) % mod;
    cout << ans << '\n';
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> T;
  fact[0] = 1;
  for (int i = 1; i <= 200000; i++) fact[i] = fact[i - 1] * i % mod;
  invfact[200000] = modpow(fact[200000], mod - 2);
  for (int i = 200000; i >= 1; i--) invfact[i - 1] = invfact[i] * i % mod;
  while (T--) f();
  return 0;
}
