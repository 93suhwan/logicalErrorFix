#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  map<char, int> mp;
  for (auto x : s) mp[x]++;
  int one = 0;
  int ans = 0;
  for (auto x : mp) {
    if (x.second >= 2)
      ++ans;
    else
      ++one;
  }
  ans += (one) / 2;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
