#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  long long int n = s.length();
  long long int ans1 = 2ll;
  long long int ans2;
  long long int c0, c1, c2;
  c0 = c1 = c2 = 0ll;
  ans2 = 0ll;
  for (auto i = 0; i < n; i++) {
    if (s[i] == '0') {
      c0++;
      ans2 += 1;
    } else if (s[i] == '1')
      c1++;
  }
  long long int MEX = (c0 == 0 ? 0 : (c1 == 0 ? 1 : 2));
  cout << min(ans1, min(ans2, MEX)) << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
