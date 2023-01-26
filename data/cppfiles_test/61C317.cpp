#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char prev = '?';
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        if (prev == 'R') {
          s[i] = 'B';
        } else if (prev == 'B') {
          s[i] = 'R';
        }
      }
      prev = s[i];
    }
    reverse(s.begin(), s.end());
    prev = '?';
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        if (prev == 'R') {
          s[i] = 'B';
        } else if (prev == 'B') {
          s[i] = 'R';
        }
      }
      prev = s[i];
    }
    reverse(s.begin(), s.end());
    if (s[0] == '?') {
      char prev = 'B';
      s[0] = 'B';
      for (int i = 1; i < n; i++) {
        if (prev == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
        prev = s[i];
      }
    }
    cout << s << endl;
  }
  return 0;
}
