#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> a(26, 0);
    string s, t, ss;
    cin >> s;
    reverse(s.begin(), s.end());
    for (char c : s) {
      if (!a[c - 'a']) {
        ss += c;
      }
      a[c - 'a']++;
    }
    reverse(ss.begin(), ss.end());
    int n = 0;
    for (int i = 1; i <= ss.length(); i++) {
      n += a[ss[i - 1] - 'a'] / i;
    }
    reverse(s.begin(), s.end());
    t = s.substr(0, n);
    string ans;
    for (char c : ss) {
      ans += t;
      int i = 0;
      while (i < t.length()) {
        if (t[i] == c) {
          t.erase(i, 1);
        } else {
          i++;
        }
      }
    }
    if (ans == s) {
      cout << s.substr(0, n) << " " << ss << endl;
    } else {
      cout << -1 << endl;
    }
  }
}
