#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 51; i++) {
      if (s[i] == NULL) {
        break;
      }
      if (s[i] == 'A') {
        a++;
      }
      if (s[i] == 'B') {
        b++;
      }
      if (s[i] == 'C') {
        c++;
      }
    }
    if (a + c == b) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
}
