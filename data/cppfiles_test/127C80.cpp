#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n, x, i, y, m;
    string s, s1;
    cin >> s >> s1;
    sort(s.begin(), s.end());
    int a, b, c;
    a = b = c = 0;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == 'a') {
        a = 1;
      }
      if (s[i] == 'b') {
        b = 1;
      }
      if (s[i] == 'c') {
        c = 1;
      }
    }
    x = a + b + c;
    if (x != 3) {
      cout << s << endl;
      continue;
    }
    if (s1 == "abc") {
      for (i = 0; i < s.size(); i++) {
        if (s[i] == 'a' || s[i] == 'c') cout << s[i];
      }
      for (i = 0; i < s.size(); i++) {
        if (s[i] == 'b') cout << s[i];
      }
      for (i = 0; i < s.size(); i++) {
        if (s[i] == 'b' || s[i] == 'a' || s[i] == 'c') continue;
        cout << s[i];
      }
      cout << endl;
    } else
      cout << s << endl;
  }
  return 0;
}
