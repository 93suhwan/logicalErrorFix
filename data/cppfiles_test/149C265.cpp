#include <bits/stdc++.h>
#pragma GCC optimize("O1")
using namespace std;
void solve() {
  long long int n, k, x;
  cin >> n >> k >> x;
  x--;
  string s;
  cin >> s;
  long long int c = 0;
  long long int p = 1;
  vector<pair<char, long long int>> v;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '*') {
      c += k;
    } else {
      c++;
      if (c > 1) v.push_back({'b', c});
      v.push_back({'a', 1});
      c = 0;
    }
  }
  c++;
  if (c > 1) v.push_back({'b', c});
  reverse(v.begin(), v.end());
  string ans = "";
  long long int l = v.size();
  for (long long int i = 0; i < l; i++) {
    if (v[i].first == 'b') {
      long long int p = x % v[i].second;
      x /= v[i].second;
      for (long long int j = 0; j < p; j++) ans.push_back('b');
    } else
      ans.push_back('a');
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
