#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
size_t solve(vector<ll> a, size_t n, ll k) {
  std::sort(a.begin(), a.end());
  ll m = a.front();
  ll sum = accumulate(a.begin(), a.end(), 0);
  size_t res = 0;
  if (sum <= k) {
    return 0;
  }
  ll suf = 0;
  for (size_t p = 0; p < n; ++p) {
    ll rest = k - sum + suf + m;
    size_t cur_res = p;
    if (sum - suf + m * p > k) {
      ll target_m;
      if (rest < 0) {
        target_m = (rest - (ll)p) / (ll)(p + 1);
      } else {
        target_m = (ll)rest / (ll)(p + 1);
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
    size_t r = solve(std::move(a), n, k);
    cout << r << '\n';
  }
  return 0;
}
