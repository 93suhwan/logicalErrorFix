#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  for (int i = 0; i < test; i++) {
    string s, t;
    cin >> s >> t;
    int a = 0, b = 0, c = 0;
    for (int j = 0; j < s.length(); j++) {
      switch (s[j]) {
        case 'a':
          a++;
          break;
        case 'b':
          b++;
          break;
        case 'c':
          c++;
          break;
      }
    }
    if (t != "abc" || a == 0) {
      sort(s.begin(), s.end());
      cout << s << endl;
    } else {
      sort(s.begin(), s.end());
      s.erase(a + b, c);
      for (int k = 0; k < c; k++) {
        s.insert(a, "c");
      }
      cout << s << endl;
    }
  }
  return 0;
}
