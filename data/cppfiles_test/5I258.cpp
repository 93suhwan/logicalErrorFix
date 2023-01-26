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
        if (s[i] == '0')
          res++;
        else {
          if (i > 1 && s[i - 1] == '1') {
            res++;
            s[i - 1] = '0';
          } else if (i < n - 1 && s[i + 1] == '1') {
            res++;
            s[i + 1] = '0';
          }
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}
