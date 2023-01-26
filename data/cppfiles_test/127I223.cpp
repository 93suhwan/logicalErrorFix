#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    string ss;
    cin >> ss;
    sort(s.begin(), s.end());
    if (ss != "abc")
      cout << s << endl;
    else {
      if (s.find('a') != string::npos && s.find('b') != string ::npos &&
          s.find('c') != string ::npos) {
        s[s.find('c')] = 'b';
        s[s.find('b')] = 'c';
      }
      cout << s << endl;
    }
  }
}
