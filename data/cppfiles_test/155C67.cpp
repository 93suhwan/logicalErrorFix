#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  string s;
  cin >> s;
  vector<int> set0, set1;
  for (int i = 0; i < (s.length()); ++i) {
    if (s[i] == '1') {
      set1.push_back(a[i]);
    } else {
      set0.push_back(a[i]);
    }
  }
  sort(set0.begin(), set0.end());
  sort(set1.begin(), set1.end());
  vector<int> res(n);
  int cnt = 0;
  for (auto x : set0) {
    res[mp[x]] = ++cnt;
  }
  for (auto x : set1) {
    res[mp[x]] = ++cnt;
  }
  for (int i = 0; i < (n); ++i) cout << res[i] << " ";
  cout << "\n";
}
signed main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  };
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
