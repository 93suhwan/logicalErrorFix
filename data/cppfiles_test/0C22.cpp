#include <bits/stdc++.h>
using ld = long double;
using ll = long long;
using namespace std;
mt19937 rnd(1337);
ll MOD = 1e9 + 7;
ll powm(ll a, ll n) {
  if (n == 0) return 1;
  if (n % 2 == 1) return powm(a, n - 1) * a % MOD;
  ll b = powm(a, n / 2);
  return b * b % MOD;
}
const ll MAXN = 1e6 + 5;
ll C[3 * MAXN];
ll fac[3 * MAXN];
ll ifac[3 * MAXN];
void solve() {
  int n;
  cin >> n;
  fac[0] = 1;
  for (int i = 1; i < 3 * MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
  ifac[3 * MAXN - 1] = powm(fac[3 * MAXN - 1], MOD - 2);
  for (int i = 3 * MAXN - 2; i > -1; i--) {
    ifac[i] = ifac[i + 1] * (i + 1) % MOD;
  }
  for (int i = 0; i <= 3 * (n + 1); i++) {
    C[i] = fac[3 * n + 3] * ifac[i] % MOD * ifac[3 * n + 3 - i] % MOD;
  }
  vector<int> need(3 * n + 1), res(3 * n + 1);
  int q;
  cin >> q;
  vector<int> a(q);
  for (int i = 0; i < q; i++) cin >> a[i], need[a[i]] = 1;
  C[0] = 0;
  ll in3 = powm(3, MOD - 2);
  for (int i = 0; i <= 3 * n; i++) {
    ll x = (C[i + 1] % MOD + MOD) % MOD;
    ll y = x * in3 % MOD;
    if (need[i]) res[i] = y;
    C[i + 1] -= x;
    C[i + 2] -= x;
    C[i + 3] -= y;
  }
  for (auto v : a) cout << res[v] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(30);
  solve();
  return 0;
}
