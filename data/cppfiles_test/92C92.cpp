#include <bits/stdc++.h>
using namespace std;
int main() {
  int test_cases;
  cin >> test_cases;
  while (test_cases--) {
    string s;
    cin >> s;
    int ab = 0;
    int ba = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i - 1] == 'a' && s[i] == 'b') {
        ++ab;
      } else if (s[i - 1] == 'b' && s[i] == 'a') {
        ++ba;
      }
    }
    if (ba == ab) {
      cout << s << "\n";
    } else {
      if (ab > ba) {
        s[0] = 'b';
      } else {
        s[0] = 'a';
      }
      cout << s << "\n";
    }
  }
  return 0;
}
