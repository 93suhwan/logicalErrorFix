#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  string s;
  cin >> s;
  int sz = (int)s.size();
  int l = 0, d = 0;
  vector<int> vl, vd;
  for (int i = 0; i < sz; i++) {
    if (s[i] - '0' == 1) {
      l++;
      vl.push_back(v[i]);
    } else {
      d++;
      vd.push_back(v[i]);
    }
  }
  sort((vl).begin(), (vl).end());
  sort((vd).begin(), (vd).end());
  unordered_map<int, int> mp;
  int k = 1;
  for (int i = 0; i < d; i++) {
    mp[vd[i]] = k;
    k++;
  }
  for (int i = 0; i < l; i++) {
    mp[vl[i]] = k;
    k++;
  }
  for (auto x : v) cout << mp[x] << ' ';
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
