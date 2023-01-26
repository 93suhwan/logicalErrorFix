#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> s;
    n = s.length();
    int a = 0, b = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == 'b' && s[i - 1] == 'a')
        a++;
      else if (s[i] == 'a' && s[i - 1] == 'b')
        b++;
    }
    int m = fabs(a - b);
    for (int i = 0; i < n; i++) {
      if (m == 0) break;
      if (a > b && s[i] == 'a') {
        s[i] = 'b';
        m--;
      } else if (a < b && s[i] == 'b') {
        s[i] = 'a';
        m--;
      }
    }
    cout << s << endl;
  }
  return 0;
}
