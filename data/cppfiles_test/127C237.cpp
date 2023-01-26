#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    string s, t;
    cin >> s;
    cin >> t;
    map<char, int> m;
    for (auto it : s) m[it]++;
    if (t != "abc" || (m['a'] == 0 || m['b'] == 0 || m['c'] == 0)) {
      sort(s.begin(), s.end());
      cout << s << endl;
    } else {
      while (m['a'] > 0) {
        cout << 'a';
        m['a']--;
      }
      while (m['c'] > 0) {
        cout << 'c';
        m['c']--;
      }
      while (m['b'] > 0) {
        cout << 'b';
        m['b']--;
      }
      for (auto it : m) {
        int r = it.second;
        if (it.first == 'a' || it.first == 'b' || it.first == 'c') continue;
        while (r--) cout << it.first;
      }
      cout << endl;
    }
  }
  return 0;
}
