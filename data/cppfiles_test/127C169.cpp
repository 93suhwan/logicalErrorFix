#include <bits/stdc++.h>
using namespace std;
int T = 1;
string s, t;
int main() {
  cin >> T;
  while (T--) {
    cin >> s >> t;
    sort(s.begin(), s.end());
    if (t == "abc" && s[0] == 'a') {
      for (int i = 0; i < s.size(); i++)
        if (s[i] == 'c')
          s[i] = 'b';
        else if (s[i] == 'b')
          s[i] = 'c';
      sort(s.begin(), s.end());
      for (int i = 0; i < s.size(); i++)
        if (s[i] == 'c')
          s[i] = 'b';
        else if (s[i] == 'b')
          s[i] = 'c';
    }
    cout << s << endl;
  }
}
