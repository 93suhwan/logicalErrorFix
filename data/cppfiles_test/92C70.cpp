#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long ab = 0;
    long long ba = 0;
    char ca, cb;
    long long cai, cbi;
    for (long long i = 0; i < s.size() - 1; ++i) {
      if (s[i] == 'a' && s[i + 1] == 'b') {
        ab++;
      } else if (s[i] == 'b' && s[i + 1] == 'a') {
        ba++;
      } else {
        if (s[i + 1] == 'a') {
          ca = s[i + 1];
          cai = i + 1;
        } else {
          cb = s[i + 1];
          cbi = i + 1;
        }
      }
    }
    if (ab == ba) {
      cout << s << endl;
      continue;
    }
    if (ab > ba) {
      s[s.size() - 1] = 'a';
      cout << s << endl;
      continue;
    }
    if (ab < ba) {
      s[s.size() - 1] = 'b';
      cout << s << endl;
      continue;
    }
  }
  return 0;
}
