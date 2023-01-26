#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(7);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int last = 0, ind = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        if (s[i] == 'a')
          last = 0;
        else
          last = 1;
        cout << s[i];
      } else if (i != n - 1) {
        if (s[i] == 'a' && last == 1) {
          if (ind) {
            ind = 0;
          } else {
            ind = 1;
          }
          last = 0;
        } else if (s[i] == 'b' && last == 0) {
          if (ind)
            ind = 0;
          else
            ind = 1;
          last = 1;
        }
        cout << s[i];
      } else {
        if (s[i] == 'a' && last == 1) {
          if (ind) {
            ind = 0;
          } else {
            ind = 1;
          }
          last = 0;
        } else if (s[i] == 'b' && last == 0) {
          if (ind)
            ind = 0;
          else
            ind = 1;
          last = 1;
        }
        if (ind == 1) {
          if (s[i] == 'b')
            cout << 'a';
          else
            cout << 'b';
        } else
          cout << s[i];
      }
    }
    cout << "\n";
  }
}
