#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, flag = -1;
    cin >> n;
    string s;
    cin >> s;
    if (s.size() == 1) {
      if (s[0] == '?') {
        cout << "B" << endl;
        continue;
      } else {
        cout << s << endl;
        continue;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (flag == 0 && s[i] != '?') {
        do {
          i--;
          if (s[i + 1] == 'B')
            s[i] = 'R';
          else if (s[i + 1] == 'R')
            s[i] = 'B';
        } while (s[i - 1] == '?');
        flag = -1;
      }
      if (flag == 1 && s[i] == '?') {
        s[n - 1] = 'R';
        do {
          i--;
          if (s[i + 1] == 'B')
            s[i] = 'R';
          else if (s[i + 1] == 'R')
            s[i] = 'B';
        } while (s[i - 1] == '?');
        flag = -1;
      }
      if (s[i] == '?') {
        if (i == 0) {
          if (s[i + 1] == 'B')
            s[i] = 'R';
          else if (s[i + 1] == 'R')
            s[i] = 'B';
          else if (s[i + 1] == '?') {
            flag = 0;
            continue;
          }
        } else if (i == n - 1) {
          if (s[i - 1] == 'B')
            s[i] = 'R';
          else if (s[i - 1] == 'R')
            s[i] = 'B';
          else if (s[i - 1] == '?') {
            flag = 1;
            i--;
            continue;
          }
        } else {
          if (s[i + 1] == 'B' || s[i - 1] == 'B')
            s[i] = 'R';
          else if (s[i + 1] == 'R' || s[i - 1] == 'R')
            s[i] = 'B';
          else if (s[i + 1] == '?') {
            flag = 0;
            continue;
          }
        }
      }
    }
    cout << s << endl;
  }
  return 0;
}
