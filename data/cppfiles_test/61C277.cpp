#include <bits/stdc++.h>
using namespace std;
char rev(char x) {
  if (x == 'B') {
    return 'R';
  }
  return 'B';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int first = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'B' || s[i] == 'R') {
        first = i;
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (first != -1) {
        if (s[i] == '?') {
          if (abs(i - first) % 2 == 1) {
            s[i] = rev(s[first]);
          } else {
            s[i] = s[first];
          }
        } else {
          first = i;
        }
      } else {
        s[0] = 'B';
        if (i != 0) {
          s[i] = rev(s[i - 1]);
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
