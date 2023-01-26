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
  ll need = sum - (n - 2) * (sum / n);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (mp[need - vec[i]]) {
      ans += mp[need - vec[i]] - (vec[i] * 2 == need);
      mp[vec[i]] = max(0ll, --mp[vec[i]]);
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
