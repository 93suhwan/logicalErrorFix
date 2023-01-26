#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int len = s.size(), c1 = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b')
        c1++;
      else if (s[i] == 'b' && s[i + 1] == 'a')
        c1--;
    }
    if (c1 == 0)
      cout << s;
    else if (c1 == 1) {
      s.erase(len - 1, 1);
      cout << s << 'a';
    } else {
      s.erase(len - 1, 1);
      cout << s << 'b';
    }
    cout << endl;
  }
}
