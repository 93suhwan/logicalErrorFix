#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  int test_case;
  cin >> test_case;
  while (test_case--) {
    string s;
    cin >> s;
    int l = s.size();
    if (l % 2 != 0) {
      cout << "No" << endl;
    } else {
      string a, b;
      a.clear();
      b.clear();
      for (int i = 0; i < l / 2; i++) {
        a += s[i];
      }
      for (int i = l / 2; i < l; i++) {
        b += s[i];
      }
      if (a == b) {
        cout << "Yes" << endl;
      } else
        cout << "No" << endl;
    }
  }
  return 0;
}
