#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void solve() {
  ll n;
  cin >> n;
  vector<ll> ar(n);
  ll cnt = 0;
  for (ll i = 0; i < n; i++) cin >> ar[i];
  sort(ar.begin(), ar.end());
  ll ind = 0;
  ll sum = 0;
  vector<ll> dp(n + 1);
  map<ll, ll> mp;
  for (ll i = 0; i <= n; i++) {
    while (ind < ar.size() && ar[ind] < i) ind++;
    if (ind < i) break;
    ll pre = ind;
    while (ind < ar.size() && ar[ind] == i) ind++;
    if (i > 0) dp[i] = dp[i - 1];
    ll num = ind - pre;
    if (num > 1)
      mp.insert({i, num - 1});
    else if (num == 0 && mp.empty() == 0) {
      auto cd = mp.rbegin();
      dp[i] += i - cd->first;
      if (cd->second == 1)
        mp.erase(cd->first);
      else
        cd->second--;
    }
    ll tmp = (i) ? dp[i - 1] : 0;
    cout << num + tmp << ' ';
  }
  while (ind++ < ar.size()) cout << "-1 ";
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  clock_t z = clock();
  ll t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
