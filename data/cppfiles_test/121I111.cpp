#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, j, a = 0, b, c = 0, d, e = 0, f = 0;
    cin >> n;
    string s, s1;
    cin >> s >> s1;
    if (s == s1)
      cout << "0";
    else {
      for (i = 0; i < s.size(); i++) {
        if (s[i] == s1[i]) a++;
        if (s[i] == '0') f++;
      }
      b = s.size() - a;
      while (a != 1) {
        if (a <= b) {
          d = b;
          b = a - 1;
          a = d + 1;
          c++;
        } else {
          d = a;
          a = b - 1;
          b = d + 1;
          c++;
        }
        if (c >= n) {
          e++;
          break;
        }
      }
      c++;
      if (e == 0 && f != s.size())
        cout << c;
      else
        cout << "-1";
    }
    cout << "\n";
  }
  return 0;
}
