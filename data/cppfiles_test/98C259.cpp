#include <bits/stdc++.h>
using namespace std;
unordered_map<char, int> mp;
int t, n, ans;
string s, keyboard;
int main() {
  cin >> t;
  while (t--) {
    cin >> keyboard;
    for (int i = 0; i < keyboard.length(); ++i) {
      mp[keyboard[i]] = i + 1;
    }
    cin >> s;
    ans = 0;
    int pos = mp[s[0]];
    for (int i = 1; i < s.length(); ++i) {
      int next = mp[s[i]];
      ans += abs(pos - next);
      pos = next;
    }
    cout << ans << endl;
  }
}
