#include <bits/stdc++.h>
using namespace std;
void error(long long int i) { cout << "test " << i << '\n'; }
void solve() {
  string s;
  cin >> s;
  map<char, long long int> m;
  for (long long int i = 0; i < s.length(); i++) m[s[i]]++;
  map<char, long long int>::iterator x;
  for (x = m.begin(); x != m.end(); x++)
    if (x->second > 2) x->second = 2;
  long long int one = 0, two = 0;
  long long int ans = 0;
  for (auto it : m) {
    if (it.second == 1) one++;
    if (it.second == 2) two++;
  }
  if (one & 1) one--;
  ans = two + one / 2;
  cout << ans << '\n';
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  for (long long int T = 1; T <= t; T++) {
    solve();
  }
  return 0;
}
