#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int i;
    string s, t;
    cin >> s >> t;
    if (t == "abc") {
      int a = 0, b = 0, c = 0;
      string f;
      for (i = 0; i < s.length(); i++) {
        if (s[i] == 'a')
          a++;
        else if (s[i] == 'b')
          b++;
        else if (s[i] == 'c')
          c++;
        else
          f.push_back(s[i]);
      }
      if (a > 0 && b > 0 && c > 0) {
        sort(f.begin(), f.end());
        for (i = 0; i < a; i++) cout << 'a';
        for (i = 0; i < c; i++) cout << 'c';
        for (i = 0; i < b; i++) cout << 'b';
        cout << f << "\n";
      } else {
        sort(s.begin(), s.end());
        cout << s << "\n";
      }
    } else {
      sort(s.begin(), s.end());
      cout << s << "\n";
    }
  }
}
