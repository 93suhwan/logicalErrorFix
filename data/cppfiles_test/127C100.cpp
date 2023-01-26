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
      int bCnt = 0, cCnt = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'b')
          bCnt++;
        else if (s[i] == 'c')
          cCnt++;
      }
      if (s.find('a') != string::npos && s.find('b') != string ::npos &&
          s.find('c') != string ::npos) {
        int b = s.find('b');
        int c = s.find('c');
        for (int i = b; i < b + cCnt; i++) s[i] = 'c';
        for (int i = b + cCnt; i < b + cCnt + bCnt; i++) s[i] = 'b';
      }
      cout << s << endl;
    }
  }
}
