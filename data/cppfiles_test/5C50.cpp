#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, r;
    cin >> s >> r;
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (r[i] == '1') {
        if (s[i] == '0') {
          res++;
          s[i] = 'a';
        } else {
          if (i > 0 && s[i - 1] == '1') {
            res++;
            s[i - 1] = 'a';
          } else if (i < n - 1 && s[i + 1] == '1') {
            res++;
            s[i + 1] = 'a';
          }
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
