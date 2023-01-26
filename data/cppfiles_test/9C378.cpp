#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int count = 0;
  unordered_map<char, int> cnt;
  for (int i = 0; i < s.length(); i++) {
    if (cnt[s[i]] < 2) {
      cnt[s[i]]++;
      count++;
    }
  }
  cout << count / 2 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
