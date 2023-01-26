#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, i;
  cin >> t;
  for (i = 1; i <= t; i++) {
    string s;
    cin >> s;
    long long int p = s.length();
    char ch = s[0];
    long long int c = 0;
    for (long long int i = 0; i < s.length(); i++) {
      if (i == 0) continue;
      if (s[i] != ch) {
        if (ch == '0') c++;
        ch = s[i];
      }
      if (c > 1) {
        c = 2;
        break;
      }
    }
    if (c < 1) {
      if (ch == '0') c++;
    }
    cout << c << "\n";
  }
  return 0;
}
