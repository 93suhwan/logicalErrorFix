#include <bits/stdc++.h>
using namespace std;
long long t;
long long a[105];
int main() {
  cin >> t;
  while (t) {
    long long l;
    cin >> l;
    string s;
    cin >> s;
    s = 'R' + s;
    memset(a, 0, sizeof(a));
    for (long long i = 1; i < s.length(); i++) {
      if (s[i] == '?') a[i] = 1, s[i] = 'B';
    }
    for (long long i = 1; i < s.length(); i++)
      if (a[i] == 1) {
        if (s[i - 1] == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
      }
    for (long long i = s.length() - 2; i >= 1; i--)
      if (a[i] == 1) {
        if (s[i + 1] == 'B')
          s[i] = 'R';
        else
          s[i] = 'B';
      }
    for (long long i = 1; i < s.length(); i++) cout << s[i];
    cout << '\n';
    t--;
  }
  return 0;
}
