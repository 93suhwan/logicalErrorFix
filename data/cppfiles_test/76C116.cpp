#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 2e18;
const int N = 4e5 + 20;
ll MOD;
ll BITree[N];
void updateBIT(ll n, ll index, ll val) {
  while (index <= n) {
    BITree[index] += val;
    if (BITree[index] >= MOD) BITree[index] %= MOD;
    index += index & (-index);
  }
}
void constructBITree(ll n) {
  for (ll i = 1; i <= n; i++) BITree[i] = 0;
}
ll getSum(ll index) {
  ll sum = 0;
  while (index > 0) {
    sum += BITree[index];
    if (sum >= MOD) sum %= MOD;
    index -= index & (-index);
  }
  return sum % MOD;
}
void update(ll l, ll r, ll n, ll val) {
  updateBIT(n, l, val);
  updateBIT(n, r + 1, (MOD - val) % MOD);
}
bool solve() {
  ll n;
  cin >> n >> MOD;
  constructBITree(n + 20);
  update(1, 1, n, 1);
  for (ll i = 1; i < n; ++i) {
    ll sum = getSum(i);
    update(i + 1, n, n, sum);
    for (ll mul = 2; 1LL * mul * i <= n; mul++) {
      ll fst = mul * i;
      ll lst = min(n, (i + 1) * mul - 1);
      update(fst, lst, n, sum);
    }
  }
  return cout << getSum(n) << endl, 0;
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(ios::badbit | ios::failbit);
  ll tests = 1;
  while (tests--) solve();
}
