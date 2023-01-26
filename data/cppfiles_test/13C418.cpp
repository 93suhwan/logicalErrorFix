#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s;
  for (int i = 1; i <= t; i++) {
    int a = 0, b = 0, c = 0;
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == 'A') {
        a++;
      } else if (s[j] == 'B') {
        b++;
      } else if (s[j] == 'C') {
        c++;
      }
    }
    if (b == c + a) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
}
