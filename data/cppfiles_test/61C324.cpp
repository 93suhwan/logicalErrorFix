#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    n = s.size();
    long long idx = n;
    long long ch = 0;
    string wrd = "BR";
    for (long long i = 0; i < n; i++) {
      if (s[i] != '?') {
        if (s[i] == 'B') {
          ch = 1;
        }
        idx = i;
        break;
      }
    }
    if (idx >= n) {
      for (long long i = 0; i < n; i++) {
        s[i] = wrd[ch];
        if (ch == 0)
          ch = 1;
        else
          ch = 0;
      }
    } else {
      for (long long i = idx; i < n; i++) {
        if (s[i] != '?') {
          if (s[i] == 'B') {
            ch = 1;
          } else
            ch = 0;
        } else {
          s[i] = wrd[ch];
          if (ch == 0)
            ch = 1;
          else
            ch = 0;
        }
      }
      for (long long i = n - 1; i >= 0; i--) {
        if (s[i] != '?') {
          if (s[i] == 'B') {
            ch = 1;
          } else
            ch = 0;
        } else {
          s[i] = wrd[ch];
          if (ch == 0)
            ch = 1;
          else
            ch = 0;
        }
      }
    }
    cout << s << "\n";
  }
  return 0;
}
