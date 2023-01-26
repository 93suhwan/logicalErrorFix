#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b')
        cnt1++;
      else if (s[i] == 'b' && s[i + 1] == 'a')
        cnt2++;
    }
    if (cnt1 < cnt2)
      s[s.size() - 1] = 'b';
    else if (cnt1 > cnt2)
      s[s.size() - 1] = 'a';
    cout << s << endl;
  }
}
