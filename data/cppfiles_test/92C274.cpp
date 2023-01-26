#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = s.length();
    long long c1 = 0, c2 = 0;
    for (long long i = 0; i < n - 1; i++) {
      if (s[i] == 'a' && s[i + 1] == 'b')
        c1++;
      else if (s[i] == 'b' && s[i + 1] == 'a')
        c2++;
    }
    string ans = "s";
    if (c1 != c2) {
      if (c1 < c2) {
        for (long long i = 0; i < n; i++) {
          if (s[i] == 'b') {
            s[i] = 'a';
            break;
          }
        }
        cout << s << endl;
      } else if (c1 > c2) {
        for (long long i = 0; i < n; i++) {
          if (s[i] == 'a') {
            s[i] = 'b';
            break;
          }
        }
        cout << s << "\n";
      }
    } else
      cout << s << endl;
  }
  return 0;
}
