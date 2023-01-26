#include <bits/stdc++.h>
using namespace std;
void init() {}
void solve() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> pre(n + 1);
  pre[0] = 0;
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    int a = 1;
    if (s[i] == '-') a = -1;
    if (i & 1) a = 0 - a;
    pre[i + 1] = pre[i] + a;
  }
  for (int i = 0; i < n; i++) {
    mp[(pre[i + 1] + pre[i])].push_back(i + 1);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if ((pre[r] - pre[l - 1]) == 0) {
      cout << 0 << endl;
    } else if (((r - l + 1) % 2) == 0) {
      cout << 2 << endl;
      l++;
      int sum = pre[r] + pre[l - 1];
      cout << l - 1 << " " << *lower_bound(mp[sum].begin(), mp[sum].end(), l)
           << endl;
    } else {
      int sum = pre[r] + pre[l - 1];
      cout << 1 << endl;
      cout << *lower_bound(mp[sum].begin(), mp[sum].end(), l) << endl;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  init();
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
