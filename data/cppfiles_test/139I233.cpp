#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    string t;
    cin >> s;
    int k = 0, count = 1, last;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[k]) {
        last = i;
        break;
      }
    }
    t = s.substr(0, last);
    int end;
    int i = 1;
    while ((last * i) <= s.size()) {
      if (s.substr(last * i, last) == t) {
        count++;
      }
      i++;
    }
    if (count == s.size() / t.size()) {
      if (count % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
