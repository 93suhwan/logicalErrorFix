#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
ll solve(vector<ll> a, ll n, ll k) {
  std::sort(a.begin(), a.end());
  const ll m = a.front();
  const ll sum = accumulate(a.begin(), a.end(), (ll)0);
  ll res = 0;
  if (sum <= k) {
    return 0;
  }
  ll suf = 0;
  for (ll p = 0; p < n; ++p) {
    ll rest = k - sum + suf + m;
    ll cur_res = p;
    if (sum - suf + m * p > k) {
      ll target_m;
      if (rest < 0LL) {
        target_m = -((-rest + (ll)p) / (ll)(p + 1));
      } else {
        target_m = rest / (ll)(p + 1);
      }
      cur_res += m - target_m;
    }
    if (res == 0 || cur_res < res) {
      res = cur_res;
    }
    suf += *(a.rbegin() + p);
  }
  return res;
}
int main() {
  uint t, n;
  ll k;
  cin >> t;
  for (uint i = 0; i < t; ++i) {
    cin >> n >> k;
    vector<ll> a(n);
    for (uint j = 0; j < n; ++j) {
      cin >> a[j];
    }
    ll r = solve(std::move(a), n, k);
    cout << r << '\n';
  }
  return 0;
}
