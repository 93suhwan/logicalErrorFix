#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    string s;
    string t;
    cin >> s;
    cin >> t;
    sort(s.begin(), s.end());
    if (t[0] == 'a' && t[1] == 'b' && t[2] == 'c') {
      int p = 0, q = 0, r = 0;
      for (long long int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') p++;
        if (s[i] == 'b') q++;
        if (s[i] == 'c') r++;
      }
      if (p == 0 || q == 0 || r == 0) {
        cout << s << endl;
      } else {
        long long int p1 = -1;
        long long int p2 = -1;
        for (long long int i = 0; i < s.length(); i++) {
          if (s[i] == 'b') {
            p1 = i;
            break;
          }
        }
        for (long long int i = s.length() - 1; i >= 0; i--) {
          if (s[i] == 'c') {
            p2 = i;
            break;
          }
        }
        if (p1 != -1 && p2 != -1) {
          while (s[p1] == 'b' && s[p2] == 'c' && p1 <= p2 &&
                 p1 <= s.length() - 1 && p2 >= 0) {
            char temp = s[p1];
            s[p1] = s[p2];
            s[p2] = temp;
            p1++;
            p2--;
          }
        }
        cout << s << endl;
      }
    } else {
      cout << s << endl;
    }
  }
}
