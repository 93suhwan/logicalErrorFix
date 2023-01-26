#include <bits/stdc++.h>
using namespace std;
const int M = 500005;
long long a[M], cont, c[M], l[M], b[M];
int main() {
  int t;
  cin >> t;
  while (t--) {
    cont = 0;
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'a' && s[i + 1] == 'b')
        cnt1++;
      else if (s[i] == 'b' && s[i + 1] == 'a')
        cnt2++;
    }
    if (cnt1 == cnt2)
      cout << s << endl;
    else if (cnt1 > cnt2) {
      string t1, t2;
      if (s[0] == 'a' && s[1] == 'a')
        s[0] = 'b';
      else if (s[s.length() - 1] == 'b' && s[s.length() - 2] == 'b')
        s[s.length() - 1] = 'a';
      else if (s[s.length() - 1] == 'b' && s[s.length() - 2] == 'a')
        s[s.length() - 1] = 'a';
      else if (s[0] == 'a' && s[1] == 'b')
        s[0] = 'b';
      cout << s << endl;
    } else {
      if (s[0] == 'b' && s[1] == 'b')
        s[0] = 'a';
      else if (s[0] == 'b' && s[1] == 'a')
        s[0] = 'a';
      else if (s[s.length() - 1] == 'a' && s[s.length() - 2] == 'a')
        s[s.length() - 1] = 'b';
      else if (s[s.length() - 1] == 'a' && s[s.length() - 2] == 'b')
        s[s.length() - 1] = 'b';
      cout << s << endl;
    }
  }
}
