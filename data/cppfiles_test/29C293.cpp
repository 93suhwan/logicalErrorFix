#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  long long sum = 0;
  map<long long, long long> mp;
  for (auto &it : v) cin >> it, sum += it, mp[it]++;
  cout << (1ll << mp[0]) * mp[1] << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
