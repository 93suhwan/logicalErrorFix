#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    long long c1 = 0, c2 = 0, t1 = 0, t2 = 0;
    long long i;
    for (i = 0; i < s.length(); i++) {
      if (s[i] == '1')
        if (i % 2)
          c2++;
        else
          c1++;
      if (s[i] == '?')
        if (i % 2)
          t2++;
        else
          t1++;
      long long la1 = 4 - i / 2;
      long long la2 = 5 - (i + 1) / 2;
      if (c1 + t1 > c2 + la2) {
        break;
      }
      if (c2 + t2 > c1 + la1) {
        break;
      }
    }
    cout << min(i + 1, 10ll) << endl;
  }
}
