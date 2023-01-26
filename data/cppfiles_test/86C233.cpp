#include <bits/stdc++.h>
using namespace std;
int main() {
  long long T = 1;
  cin >> T;
  while (T--) {
    long n, k, i, j = 2, c = 0, f = 0;
    cin >> n;
    string s, t;
    cin >> s >> t;
    i = 0;
    while (i < n) {
      if (s[i] == '1' && t[i] == '0')
        c = c + 2;
      else if (t[i] == '1' && s[i] == '0')
        c = c + 2;
      else {
        if (s[i] == '0' && t[i] == '0') {
          if (i + 1 < n && s[i + 1] == '1' && t[i + 1] == '1')
            c = c + 2, i++;
          else
            c++;
        } else {
          if (i + 1 < n && s[i + 1] == '0' && t[i + 1] == '0') c = c + 2, i++;
        }
      }
      i++;
    }
    cout << c;
    cout << endl;
  }
  return 0;
}
