#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
void solve() {
  string s;
  cin >> s;
  vector<long long> v(26, 0);
  for (long long i = 0; i < s.size(); i++) v[s[i] - 'a']++;
  long long cnt1 = 0, cnt2 = 0;
  for (long long i = 0; i < 26; i++) {
    if (v[i] >= 2)
      cnt2++;
    else if (v[i] == 1)
      cnt1++;
  }
  long long ans = cnt1 / 2 + cnt2;
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
