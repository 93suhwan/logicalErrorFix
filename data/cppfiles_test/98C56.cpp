#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string k, s;
    cin >> k >> s;
    int pos[26];
    for (int i = 0; i < 26; i++) {
      pos[k[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 1; i < s.size(); i++) {
      ans += abs(pos[s[i] - 'a'] - pos[s[i - 1] - 'a']);
    }
    cout << ans << endl;
  }
  return 0;
}
