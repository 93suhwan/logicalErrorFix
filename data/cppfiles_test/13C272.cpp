#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  int a, b, c;
  for (int i = 0; i < n; i++) {
    a = 0;
    b = 0;
    c = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s.at(i) == 'A') {
        a++;
      } else if (s.at(i) == 'B') {
        b++;
      } else {
        c++;
      }
    }
    if (a + c == b) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
