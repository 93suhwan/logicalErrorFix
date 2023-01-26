#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll n, sum = 0;
  cin >> n;
  map<ll, ll> mp;
  vector<ll> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    mp[vec[i]]++;
    sum += vec[i];
  }
  ll nm = (n - 2) * (sum / n), need = sum - nm;
  ll ans = 0;
  auto d = [](ll n) {
    ll s = 0;
    for (; n; s += n--)
      ;
    return s;
  };
  for (int i = 0; i < n; i++) {
    if (mp[need - vec[i]] && mp[vec[i]]) {
      if (vec[i] == need - vec[i]) {
        ans += d(mp[vec[i]] - 1);
        mp[vec[i]] = 0;
      } else {
        ans += mp[vec[i]] * mp[need - vec[i]];
        mp[vec[i]] = 0;
      }
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve(), cout << "\n";
  }
  return 0;
}
