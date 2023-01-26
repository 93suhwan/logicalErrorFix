#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    vector<int> a(26);
    for (char c : s) {
      a[c - 'a']++;
    }
    if (t == "abc" && a[0] && a[1] && a[2]) {
      while (a[0]--) cout << "a";
      while (a[2]--) cout << "c";
      while (a[1]--) cout << "b";
      for (int i = 3; i < 26; i++) {
        while (a[i]--) cout << (char)(i + 'a');
      }
    } else {
      sort(s.begin(), s.end());
      cout << s;
    }
    cout << '\n';
  }
  return 0;
}
