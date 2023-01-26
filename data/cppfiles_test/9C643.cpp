#include <bits/stdc++.h>
using namespace std;
int tc;
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> s;
    int ans = 0;
    vector<int> cnt(26, 0);
    for (char i : s) cnt[i - 'a']++;
    for (int i = 0; i < 26; i++) {
      ans += min(2, cnt[i]);
    }
    cout << ans / 2 << '\n';
  }
  return 0;
}
