#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout << fixed;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n >= 2) {
      if (s[0] != '?' and s[1] == '?') {
        if (s[0] == 'B')
          s[1] = 'R';
        else
          s[1] = 'B';
      }
      if (s[n - 1] != '?' and s[n - 2] == '?') {
        if (s[n - 1] == 'B')
          s[n - 2] = 'R';
        else
          s[n - 2] = 'B';
      }
    }
    for (int j = 0; j < n + 2; j++) {
      for (int i = 1; i < n - 1; i++) {
        if (s[i] != '?') {
          if (s[i + 1] == '?') {
            if (s[i] == 'B')
              s[i + 1] = 'R';
            else
              s[i + 1] = 'B';
          }
          if (s[i - 1] == '?') {
            if (s[i] == 'B')
              s[i - 1] = 'R';
            else
              s[i - 1] = 'B';
          }
        }
      }
    }
    int i = 0;
    string tt;
    while (i < n) {
      tt += 'B';
      i++;
      if (i == n) break;
      tt += 'R';
      i++;
    }
    string x(1, '?');
    if (s.find(x) != string::npos) {
      s = tt;
    }
    cout << s << "\n";
  }
  return 0;
}
