#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t = 1;
  cin >> t;
  while (t--) {
    string s, tt;
    cin >> s >> tt;
    sort(s.begin(), s.end());
    char x = tt[0], y = tt[1], z = tt[2];
    if (tt != "abc") {
      cout << s << "\n";
      continue;
    }
    if (s[0] != 'a') {
      cout << s << "\n";
      continue;
    }
    string d = "";
    long long int bn = 0, bf = -1;
    ;
    long long int cl = -1;
    for (long long int i = 0; i < s.length(); i++) {
      if (s[i] == 'b') {
        bf = i;
        break;
      }
    }
    for (long long int i = 0; i < s.length(); i++) {
      if (s[i] == 'b') {
        bn++;
      }
    }
    if (bn == 0) {
      cout << s << "\n";
      continue;
    }
    for (long long int i = s.length() - 1; i >= 0; i--) {
      if (s[i] == 'c') {
        cl = i;
        break;
      }
    }
    if (cl == -1) {
      cout << s << "\n";
      continue;
    }
    for (long long int i = 0; i < bf; i++) {
      d += s[i];
    }
    for (long long int i = bf + bn; i <= cl; i++) {
      d += s[i];
    }
    for (long long int i = 0; i < bn; i++) {
      d += 'b';
    }
    for (long long int i = cl + 1; i < s.length(); i++) {
      d += s[i];
    }
    cout << d << "\n";
  }
  return 0;
}
